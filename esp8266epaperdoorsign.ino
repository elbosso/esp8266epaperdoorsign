/*
Copyright (c) 2018.

Juergen Key. Alle Rechte vorbehalten.

Weiterverbreitung und Verwendung in nichtkompilierter oder kompilierter Form, 
mit oder ohne Veraenderung, sind unter den folgenden Bedingungen zulaessig:

   1. Weiterverbreitete nichtkompilierte Exemplare muessen das obige Copyright, 
die Liste der Bedingungen und den folgenden Haftungsausschluss im Quelltext 
enthalten.
   2. Weiterverbreitete kompilierte Exemplare muessen das obige Copyright, 
die Liste der Bedingungen und den folgenden Haftungsausschluss in der 
Dokumentation und/oder anderen Materialien, die mit dem Exemplar verbreitet 
werden, enthalten.
   3. Weder der Name des Autors noch die Namen der Beitragsleistenden 
duerfen zum Kennzeichnen oder Bewerben von Produkten, die von dieser Software 
abgeleitet wurden, ohne spezielle vorherige schriftliche Genehmigung verwendet 
werden.

DIESE SOFTWARE WIRD VOM AUTOR UND DEN BEITRAGSLEISTENDEN OHNE 
JEGLICHE SPEZIELLE ODER IMPLIZIERTE GARANTIEN ZUR VERFUEGUNG GESTELLT, DIE 
UNTER ANDEREM EINSCHLIESSEN: DIE IMPLIZIERTE GARANTIE DER VERWENDBARKEIT DER 
SOFTWARE FUER EINEN BESTIMMTEN ZWECK. AUF KEINEN FALL IST DER AUTOR 
ODER DIE BEITRAGSLEISTENDEN FUER IRGENDWELCHE DIREKTEN, INDIREKTEN, 
ZUFAELLIGEN, SPEZIELLEN, BEISPIELHAFTEN ODER FOLGENDEN SCHAEDEN (UNTER ANDEREM 
VERSCHAFFEN VON ERSATZGUETERN ODER -DIENSTLEISTUNGEN; EINSCHRAENKUNG DER 
NUTZUNGSFAEHIGKEIT; VERLUST VON NUTZUNGSFAEHIGKEIT; DATEN; PROFIT ODER 
GESCHAEFTSUNTERBRECHUNG), WIE AUCH IMMER VERURSACHT UND UNTER WELCHER 
VERPFLICHTUNG AUCH IMMER, OB IN VERTRAG, STRIKTER VERPFLICHTUNG ODER 
UNERLAUBTE HANDLUNG (INKLUSIVE FAHRLAESSIGKEIT) VERANTWORTLICH, AUF WELCHEM 
WEG SIE AUCH IMMER DURCH DIE BENUTZUNG DIESER SOFTWARE ENTSTANDEN SIND, SOGAR, 
WENN SIE AUF DIE MOEGLICHKEIT EINES SOLCHEN SCHADENS HINGEWIESEN WORDEN SIND.
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
//needed for wifimanager
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <GxEPD.h>
#include <GxGDEW075T8/GxGDEW075T8.cpp>      // 7.5" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include "qr1.h"
#include "qr2.h"

//
// Debug messages over the serial console.
//
#include "debug.h"



//Your Wifi SSID
const char* ssid = "your_ssid";
//Your Wifi Key
const char* password = "your_key";

ESP8266WebServer* server;

bool lamp = 0;

//
// The helper & object for the epaper display.
//
GxIO_Class io(SPI, SS, 0, 2);
GxEPD_Class display(io);


//
// Fetch and display the image specified at the given URL
//
void display_url(const char * m_path)
{
    //
    // Clear the display.
    //
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    //
    // The host we're going to fetch from.
    //
    char m_host[] = "apache2.fritz.box";

    char m_tmp[50] = { '\0' };
    memset(m_tmp, '\0', sizeof(m_tmp));

    /*
     * Create a HTTP client-object.
     */
    WiFiClient m_client;
    int port = 80;

    //
    // Keep track of where we are.
    //
    bool finishedHeaders = false;
    bool currentLineIsBlank = true;
    String m_body = "";
    long now;

    Serial.println("About to make the connection to");
    Serial.println(m_host);
    Serial.println(m_path);

    //
    // Connect to the remote host, and send the HTTP request.
    //
    if (!m_client.connect(m_host, port))
    {
        Serial.println("Failed to connect");
        return;
    }

    Serial.println("Making HTTP-request\n");

    m_client.print("GET ");
    m_client.print(m_path);
    m_client.println(" HTTP/1.0");
    m_client.print("Host: ");
    m_client.println(m_host);
    m_client.println("User-Agent: epaper-web-image/1.0");
    m_client.println("Connection: close");
    m_client.println("");

    Serial.println("Made HTTP-request\n");

    now = millis();

    //
    // Test for timeout waiting for the first byte.
    //
    while (m_client.available() == 0)
    {
        if (millis() - now > 15000)
        {
            Serial.println(">>> Client Timeout !");
            m_client.stop();
            return;
        }
    }

    int l = 0;

    //
    // Now we hope we'll have smooth-sailing, and we'll
    // read a single character until we've got it all
    //
    int pbmheaders=2;
        unsigned char gImage[640/8]={0};
        int byteIndexInLine=0;
        int bitCount=0;
        int lineIndex=0;
    while (m_client.connected())
    {
      if(m_client.available())
      {
        char c = m_client.read();
        if (finishedHeaders)
        {
          if(pbmheaders==0)
          {
            if(c=='1')
            {
              display.drawPixel(byteIndexInLine*8+bitCount,lineIndex,GxEPD_BLACK);
              gImage[byteIndexInLine]=(gImage[byteIndexInLine]<<1)|0x1;
              ++bitCount;
              if(bitCount==8)
              {
                bitCount=0;
                ++byteIndexInLine;
                gImage[byteIndexInLine]=0;
              }
            }
            else if(c=='0')
            {
              display.drawPixel(byteIndexInLine*8+bitCount,lineIndex,GxEPD_WHITE);
              //gImage[byteIndexInLine]=(gImage[byteIndexInLine]<<1)&0xfe;
              ++bitCount;
              if(bitCount==8)
              {
                bitCount=0;
                ++byteIndexInLine;
                gImage[byteIndexInLine]=0;
              }
            }
            if(byteIndexInLine==640/8)
            {
              if(lineIndex%10==0)
                Serial.println("drawing a tenth line");
//              display.drawBitmap(0, lineIndex, gImage, 640, 1, GxEPD_BLACK);
              ++lineIndex;
              bitCount=0;
              byteIndexInLine=0;
            }
          }
          else
          {
            if(c == '\n')
            {
              --pbmheaders;
              Serial.println("PBM headers skipped");
            }
          }
/*            //
            // Here we're reading the body of the response.
            //
            // We keep appending characters, but we don't want to
            // store the whole damn response in a string, because
            // that would eat all our RAM.
            //
            // Instead we read each character until we find a newline
            //
            // Once we find a newline we process that input, then
            // we keep reading more.
            //
            if (c == '\n' && strlen(m_tmp) > 5)
            {
                l += 1;

                //
                // Here we've read a complete line.
                //
                // The line will be of the form "x,y,X,Y", so we
                // need to parse that into four integers, and then
                // draw the appropriate line on our display.
                //
                int line[5] = { 0 };
                int i = 0;


                //
                // Parse into values.
                //
                char* ptr = strtok(m_tmp, ",");

                while (ptr != NULL && i < 4)
                {
                    // create next part
                    line[i] = atoi(ptr);
                    i++;
                    ptr = strtok(NULL, ",");
                }


                //
                // Draw the line.
                //
                display.drawLine(line[1], line[0], line[3], line[2], GxEPD_BLACK);

                //
                // Now we nuke the memory so that we can read
                // another line.
                //
                memset(m_tmp, '\0', sizeof(m_tmp));
            }
            else
            {
                // TODO - buffer-overflow.
                m_tmp[strlen(m_tmp)] = c;
            }
            */
        }
        else
        {
            if (currentLineIsBlank && c == '\n')
                finishedHeaders = true;
        }

        if (c == '\n')
            currentLineIsBlank = true;
        else if (c != '\r')
            currentLineIsBlank = false;

        // Wait for more packetses
       // delay(1);
      }
    }

    Serial.println("Nothing more is available - terminating");
    m_client.stop();


    //
    // Trigger the update of the display.
    //
    display.update();

}

void setup(void){
  Serial.begin(115200); 
 // delay(5000);
//  Serial.println("");
   // setup the display
  display.init();
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

  WiFi.persistent(true);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);
//  WiFi.begin("judffgsduifg","75fBWSJumwfOsIb5Kqvvr3vPyoylBcAoSkbB6D4W90BY5IFTDC5XwpCgRELiBeU"); // reading data from EPROM, (last saved credentials)
  WiFi.begin(WiFi.SSID().c_str(),"huihu");//WiFi.psk().c_str()); // reading data from EPROM, (last saved credentials)
//  WiFi.begin("foobar",WiFi.psk().c_str()); // making sure access point and if not configured in time (180 sec), wps happen
 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, lamp);
  
  // Wait for WiFi
  Serial.println("");
  Serial.print("Verbindungsaufbau mit:  ");
  Serial.println(WiFi.SSID().c_str());

  while (WiFi.status() == WL_DISCONNECTED) {          // last saved credentials
    delay(500);
    if(lamp == 0){
       digitalWrite(LED_BUILTIN, 1);
       lamp = 1;
     }else{
       digitalWrite(LED_BUILTIN, 0);
       lamp = 0;
    }
    Serial.print(".");
  }
  lamp=0;
  digitalWrite(LED_BUILTIN, 0);

  wl_status_t status = WiFi.status();
  if(status == WL_CONNECTED) {
    Serial.printf("\nConnected successful to SSID '%s'\n", WiFi.SSID().c_str());
  } else {
  display.setRotation(2);
  display.setFont(&FreeMonoBold18pt7b);
  display.setCursor(0, 0);
  display.println();
  display.println("Please connect to SSID");
  display.println("AutoConnectAP_ePaper!");
    display.drawExampleBitmap(gImage_IMG_0002, 270, 90, 100, 100, GxEPD_BLACK);
    display.setCursor(0,200);
  display.println();
  display.println("Then open configuration at");
  display.println("http://192.168.4.1!");
    display.drawExampleBitmap(gImage_IMG_0001, 270, 290, 100, 100, GxEPD_BLACK);
    display.update();
  display.setRotation(0);
    WiFi.mode(WIFI_OFF);
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset settings - for testing
    //wifiManager.resetSettings();
  
    //sets timeout until configuration portal gets turned off
    //useful to make it all retry or go to sleep
    //in seconds
    digitalWrite(LED_BUILTIN, LOW);
    
    //fetches ssid and pass and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP_12F647"
    //and goes into a blocking loop awaiting configuration
    if(!wifiManager.autoConnect("AutoConnectAP_ePaper")) 
    {
      WiFi.mode(WIFI_OFF);
      WiFi.mode(WIFI_STA);
      digitalWrite(LED_BUILTIN, HIGH);
      // WPS button I/O setup
/*      Serial.printf("\nCould not connect to WiFi. state='%d'\n", status);
      Serial.println("Please press WPS button on your router, until mode is indicated.");
      Serial.println("next press the ESP module WPS button, router WPS timeout = 2 minutes");
      
      while(digitalRead(gpio0Switch) == HIGH)  // wait for WPS Button active
      {
        delay(50);
        if(lamp == 0){
           digitalWrite(LED_BUILTIN, 1);
           lamp = 1;
         }else{
           digitalWrite(LED_BUILTIN, 0);
           lamp = 0;
        }
        Serial.print(".");
        yield(); // do nothing, allow background work (WiFi) in while loops
      }      
      Serial.println("WPS button pressed");
      lamp=0;
      digitalWrite(LED_BUILTIN, 0);
      
      if(!startWPSPBC()) {
         Serial.println("Failed to connect with WPS :-(");  
      } else*/ {
        WiFi.begin(WiFi.SSID().c_str(),WiFi.psk().c_str()); // reading data from EPROM, 
        while (WiFi.status() == WL_DISCONNECTED) {          // last saved credentials
          delay(500);
          Serial.print("."); // show wait for connect to AP
        }
      }
    }
  } 

  
  Serial.println("Verbunden");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  Serial.println("Led aus!");
  digitalWrite(LED_BUILTIN, HIGH);
    //
    // Clear the display.
    //
  Serial.println("clear Display");

    //
    // Trigger the update of the display.
    //
//  Serial.println("Setup done!");
    char *two = "/Hardware/d1-epaper/wss.pbm";
            display_url(two);
//Serial.println("Going into deep sleep for 20 seconds");
//ESP.deepSleep(20e6); // 20e6 is 20 microseconds
Serial.println("Going into deep sleep for 10 minutes");
ESP.deepSleep(600e6); // 20e6 is 20 microseconds
}
void loop(void){
/*//    char *one = "/Hardware/d1-epaper/knot.dat";
//    char *two = "/Hardware/d1-epaper/skull.dat";
    char *one = "/Hardware/d1-epaper/br.pbm";
    char *two = "/Hardware/d1-epaper/wss.pbm";
    static int i = 0;

    //
    // Have we displayed the image?
    //
    static bool show = false;

    //
    // The time we last displayed the image.
    static long displayed = 0;

    //
    // If we've not shown the image, then do so.
    //
    if (show == false)
    {
        //
        // Fetch / display
        //
        if (i == 0)
        {
            display_url(one);
            i = 1;
        }
        else
        {
            display_url(two);
            i = 0;
        }

        //
        // And never again.
        //
        show = true;
        displayed = millis();
    }


    //
    // Update the image 60 seconds.
    //
    // Do this by pretending we've never updated, even though we have.
    //
    if (millis() - displayed > (20 * 1000))
        show = false;
*/
} 