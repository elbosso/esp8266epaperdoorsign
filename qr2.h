#ifndef _QR2_H_
#define _QR2_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

// 180 x 64 (Boot)
const unsigned char gImage_IMG_0002[1300] PROGMEM = {
  0xff, 0xff, 0xe0, 0xe0, 0x03, 0x9f, 0xe0, 0x60, 0x0f, 0x8c, 0x7f, 0xff, 0xf0
  , 0xff, 0xff, 0xe0, 0xe0, 0x03, 0x9f, 0xe0, 0x60, 0x0f, 0x8c, 0x7f, 0xff, 0xf0
  , 0xff, 0xff, 0xe0, 0xe0, 0x03, 0x1f, 0xe0, 0x60, 0x0f, 0x8c, 0x7f, 0xff, 0xf0
  , 0xe0, 0x00, 0xe3, 0xe0, 0xfc, 0x1f, 0x80, 0x1f, 0x8c, 0x00, 0x70, 0x00, 0x70
  , 0xe0, 0x00, 0xe3, 0xe0, 0xfc, 0x1f, 0x80, 0x1f, 0x8c, 0x00, 0x70, 0x00, 0x70
  , 0xe3, 0xf8, 0xe0, 0xff, 0xfc, 0x60, 0x00, 0x7f, 0xe0, 0x20, 0x71, 0xfc, 0x70
  , 0xe7, 0xfc, 0xe0, 0xff, 0xfc, 0x60, 0x00, 0x7f, 0xf0, 0x70, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0xff, 0xfc, 0x60, 0x00, 0x7f, 0xf0, 0x70, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0x03, 0xe0, 0x00, 0x1f, 0xe3, 0xfc, 0x7c, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0x03, 0xe0, 0x00, 0x1f, 0xe3, 0xfc, 0x7c, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0x03, 0xe0, 0x00, 0x1f, 0xe3, 0xfc, 0x7c, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0x1f, 0xfc, 0x7f, 0x9f, 0x9c, 0x00, 0x0c, 0x73, 0xfe, 0x70
  , 0xe7, 0xfc, 0xe0, 0x1f, 0xfc, 0x7f, 0x9f, 0x9c, 0x00, 0x0c, 0x73, 0xfe, 0x70
  , 0xe3, 0xf8, 0xe0, 0x1f, 0xfc, 0x7f, 0x9f, 0x1c, 0x00, 0x0c, 0x71, 0xfc, 0x70
  , 0xe0, 0x00, 0xe3, 0x1f, 0x1c, 0x7c, 0x1c, 0x1f, 0x83, 0x80, 0x70, 0x00, 0x70
  , 0xe0, 0x00, 0xe3, 0x1f, 0x1c, 0x7c, 0x1c, 0x1f, 0x83, 0x80, 0x70, 0x00, 0x70
  , 0xff, 0xff, 0xe3, 0x1c, 0x63, 0x1c, 0x63, 0x1c, 0x63, 0x8c, 0x7f, 0xff, 0xf0
  , 0xff, 0xff, 0xe3, 0x1c, 0xe3, 0x9c, 0x63, 0x9c, 0x73, 0x8c, 0x7f, 0xff, 0xf0
  , 0xff, 0xff, 0xe3, 0x1c, 0xe3, 0x0c, 0x63, 0x9c, 0x73, 0x8c, 0x7f, 0xff, 0xf0
  , 0x00, 0x00, 0x03, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xf3, 0x8c, 0x00, 0x00, 0x00
  , 0x00, 0x00, 0x03, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xf3, 0x8c, 0x00, 0x00, 0x00
  , 0x00, 0x00, 0x00, 0xfc, 0x1c, 0x03, 0xff, 0xf0, 0xf3, 0xdc, 0x00, 0x00, 0x00
  , 0x00, 0x1f, 0xf8, 0xfc, 0x1f, 0xe3, 0xff, 0xe0, 0x7f, 0xfc, 0x7c, 0x01, 0x80
  , 0x00, 0x1f, 0xf8, 0xfc, 0x1f, 0xe3, 0xff, 0xe0, 0x7f, 0xfc, 0x7c, 0x01, 0x80
  , 0xf8, 0x03, 0x9f, 0xe3, 0x1c, 0x63, 0x9f, 0x83, 0xff, 0xf1, 0xf3, 0x81, 0xf0
  , 0xf8, 0x03, 0x1f, 0xe3, 0x1c, 0x63, 0x9f, 0x83, 0xff, 0xf1, 0xf3, 0x81, 0xf0
  , 0xf8, 0x03, 0x1f, 0xe3, 0x1c, 0x63, 0x9f, 0x83, 0xff, 0xf1, 0xf3, 0x81, 0xf0
  , 0xf8, 0xe3, 0xff, 0x03, 0xe3, 0xe0, 0x00, 0x63, 0xf0, 0x71, 0xff, 0x8e, 0x00
  , 0xf8, 0xe3, 0xff, 0x03, 0xe3, 0xe0, 0x00, 0x63, 0xf0, 0x71, 0xff, 0x8e, 0x00
  , 0xfc, 0xe3, 0xff, 0x03, 0xe3, 0xe0, 0x00, 0x63, 0xf0, 0x71, 0xff, 0x8e, 0x00
  , 0x1f, 0xe0, 0x1f, 0x1c, 0x03, 0x9c, 0x1f, 0x83, 0xf3, 0x8c, 0x03, 0x8e, 0x00
  , 0x1f, 0xe0, 0x1f, 0x1c, 0x03, 0x9c, 0x1f, 0x83, 0xf3, 0x8c, 0x03, 0x8e, 0x00
  , 0xfc, 0xe3, 0xe0, 0x1c, 0x03, 0x9f, 0xe0, 0x0f, 0xf0, 0x7c, 0x3c, 0x7f, 0xf0
  , 0xf8, 0xe3, 0xe0, 0x1c, 0x03, 0x9f, 0xe0, 0x1f, 0xf0, 0x7c, 0x7c, 0x7f, 0xf0
  , 0xf8, 0xe3, 0xe0, 0x1c, 0x03, 0x9f, 0xe0, 0x1f, 0xf0, 0x7c, 0x7c, 0x7f, 0xf0
  , 0x00, 0xfc, 0x03, 0x1c, 0x63, 0xff, 0x9f, 0xe3, 0x8c, 0x0f, 0x83, 0xf0, 0x70
  , 0x00, 0xfc, 0x03, 0x1c, 0xe3, 0xff, 0x9f, 0xe3, 0x8c, 0x0f, 0x83, 0xf0, 0x70
  , 0x00, 0xfc, 0x07, 0x1c, 0xe3, 0xff, 0x9f, 0xe3, 0x8c, 0x0f, 0x83, 0xf0, 0x70
  , 0xf8, 0xe3, 0xff, 0x00, 0xe0, 0x00, 0x1c, 0x7c, 0x70, 0x70, 0x70, 0x00, 0x00
  , 0xf8, 0xe3, 0xff, 0x00, 0xe0, 0x00, 0x1c, 0x7c, 0x70, 0x70, 0x70, 0x00, 0x00
  , 0xf8, 0x63, 0xff, 0x00, 0x60, 0x00, 0x1c, 0xfc, 0x70, 0x70, 0x70, 0x00, 0x00
  , 0xf8, 0x03, 0x18, 0xe0, 0x00, 0x7c, 0x63, 0xfc, 0x73, 0x8f, 0xf0, 0x0e, 0x70
  , 0xf8, 0x03, 0x18, 0xe0, 0x00, 0x7c, 0x63, 0xfc, 0x73, 0x8f, 0xf0, 0x0e, 0x70
  , 0xe0, 0x1c, 0x60, 0x1f, 0x1c, 0x7f, 0x9c, 0x1c, 0x7c, 0x7f, 0xfc, 0x01, 0x80
  , 0xe0, 0x1c, 0xe0, 0x1f, 0x1c, 0x7f, 0x9c, 0x1c, 0x7c, 0x7f, 0xfc, 0x01, 0x80
  , 0xe0, 0x1c, 0xe0, 0x1f, 0x1c, 0x7f, 0x9c, 0x1c, 0x7c, 0x7f, 0xfc, 0x01, 0x80
  , 0x18, 0x1c, 0x18, 0xff, 0xfc, 0x1f, 0xe3, 0xfc, 0x70, 0x7e, 0x03, 0x81, 0xf0
  , 0x18, 0x1c, 0x18, 0xff, 0xfc, 0x1f, 0xe3, 0xfc, 0x70, 0x7c, 0x03, 0x81, 0xf0
  , 0x18, 0x1c, 0x18, 0xff, 0xfc, 0x1f, 0xe3, 0xfc, 0x70, 0x7c, 0x03, 0x81, 0xf0
  , 0xe0, 0x1f, 0xe3, 0xff, 0xe0, 0x7c, 0x63, 0xe0, 0x7c, 0x70, 0x03, 0x80, 0x00
  , 0xe0, 0x1f, 0xe3, 0xff, 0xe0, 0x7c, 0x63, 0xe0, 0x7c, 0x70, 0x03, 0x80, 0x00
  , 0xff, 0x03, 0x03, 0x00, 0x1c, 0x60, 0x60, 0x03, 0xf0, 0x0c, 0x0f, 0x8c, 0x00
  , 0xff, 0x03, 0x03, 0x00, 0x1c, 0x60, 0x60, 0x03, 0xf0, 0x0c, 0x0f, 0x8e, 0x00
  , 0xff, 0x03, 0x07, 0x00, 0x1c, 0x60, 0x60, 0x03, 0xe0, 0x0e, 0x0f, 0x8e, 0x00
  , 0x18, 0x1c, 0xff, 0xfc, 0xfc, 0x7c, 0x60, 0x63, 0x80, 0x0f, 0xff, 0x8e, 0x00
  , 0x18, 0x1c, 0xff, 0xfc, 0xfc, 0x7c, 0x60, 0x63, 0x80, 0x0f, 0xff, 0x8e, 0x00
  , 0x3c, 0x18, 0x7f, 0xf8, 0xfc, 0xfc, 0x60, 0x63, 0x80, 0x0f, 0xff, 0x8c, 0x00
  , 0xff, 0x00, 0x1f, 0xe0, 0xe3, 0xfc, 0x1c, 0x63, 0x83, 0xf1, 0x83, 0x80, 0x00
  , 0xff, 0x00, 0x1f, 0xe0, 0xe3, 0xfc, 0x1c, 0x63, 0x83, 0xf1, 0x83, 0x80, 0x00
  , 0x00, 0x1f, 0xe7, 0xe3, 0x1f, 0xf0, 0x1f, 0x9c, 0x0f, 0xf1, 0x83, 0xfc, 0x00
  , 0x00, 0x1f, 0xe3, 0xe3, 0x1f, 0xe0, 0x1f, 0x9c, 0x0f, 0xf1, 0x83, 0xfe, 0x00
  , 0x00, 0x1f, 0xe3, 0xe3, 0x1f, 0xe0, 0x1f, 0x9c, 0x0f, 0xf1, 0x83, 0xfe, 0x00
  , 0xff, 0xff, 0x1f, 0x03, 0xff, 0xe0, 0x63, 0xe0, 0x7c, 0x0f, 0x8c, 0x0f, 0x80
  , 0xff, 0xff, 0x1f, 0x03, 0xff, 0xe0, 0x63, 0xe0, 0x7c, 0x0f, 0x8c, 0x0f, 0x80
  , 0xff, 0xff, 0x1f, 0x03, 0xff, 0xe0, 0x63, 0xe0, 0x7c, 0x0f, 0x8c, 0x0f, 0x80
  , 0xe0, 0xe3, 0xff, 0x00, 0x1c, 0x7c, 0x63, 0xfc, 0x7c, 0x0c, 0x70, 0x0e, 0x70
  , 0xe0, 0xe3, 0xff, 0x00, 0x1c, 0x7c, 0x63, 0xfc, 0x7c, 0x0c, 0x70, 0x0e, 0x70
  , 0xe0, 0xe3, 0xff, 0x80, 0x1c, 0x7c, 0x63, 0xfc, 0x7e, 0x0c, 0x60, 0x0c, 0x30
  , 0xe0, 0xe3, 0x03, 0xe3, 0xfc, 0x7f, 0x9c, 0x7c, 0x0f, 0xf1, 0x8f, 0x80, 0x00
  , 0xe0, 0xe3, 0x03, 0xe3, 0xfc, 0x7f, 0x9c, 0x7c, 0x0f, 0xf1, 0x8f, 0x80, 0x00
  , 0x03, 0x00, 0xc0, 0xff, 0x9f, 0xfc, 0x03, 0xfc, 0x03, 0xff, 0xff, 0x80, 0x00
  , 0x07, 0x00, 0xe0, 0xff, 0x1f, 0xfc, 0x03, 0xfc, 0x03, 0xff, 0xff, 0x80, 0x00
  , 0x07, 0x00, 0xe0, 0xff, 0x1f, 0xfc, 0x03, 0xfc, 0x03, 0xff, 0xff, 0x80, 0x00
  , 0x07, 0x1f, 0x03, 0xe3, 0x03, 0xff, 0xfc, 0x1c, 0x73, 0x8f, 0xf0, 0x0c, 0x70
  , 0x07, 0x1f, 0x03, 0xe3, 0x03, 0xff, 0xfc, 0x1c, 0x73, 0x8f, 0xf0, 0x0e, 0x70
  , 0x07, 0x1f, 0x03, 0xe3, 0x03, 0xff, 0xfc, 0x1c, 0x63, 0x8f, 0xf0, 0x0e, 0x70
  , 0xff, 0x1c, 0xe3, 0xe3, 0x1f, 0xe3, 0x9c, 0x1f, 0x80, 0x7f, 0xff, 0xff, 0x80
  , 0xff, 0x1c, 0xe3, 0xe3, 0x1f, 0xe3, 0x9c, 0x1f, 0x80, 0x7f, 0xff, 0xff, 0x80
  , 0x00, 0x00, 0x03, 0xe3, 0x00, 0xe3, 0x80, 0x03, 0x80, 0x7e, 0x03, 0xde, 0x00
  , 0x00, 0x00, 0x03, 0xe3, 0x00, 0x63, 0xe0, 0x63, 0x8c, 0x7c, 0x03, 0x8e, 0x00
  , 0x00, 0x00, 0x03, 0xe3, 0x00, 0x63, 0xe0, 0x63, 0x8c, 0x7c, 0x03, 0x8e, 0x00
  , 0xff, 0xff, 0xe3, 0xff, 0xfc, 0x03, 0xe3, 0xff, 0xf0, 0x0c, 0x63, 0x8e, 0x00
  , 0xff, 0xff, 0xe3, 0xff, 0xfc, 0x03, 0xe3, 0xff, 0xf0, 0x0c, 0x73, 0x8e, 0x00
  , 0xff, 0xff, 0xe3, 0xff, 0xfc, 0x03, 0xe3, 0xff, 0xf0, 0x1c, 0x23, 0x8e, 0x00
  , 0xe0, 0x00, 0xe3, 0xff, 0x1c, 0x1c, 0x60, 0x00, 0x70, 0x7c, 0x03, 0x8f, 0x80
  , 0xe0, 0x00, 0xe3, 0xff, 0x1c, 0x1c, 0x60, 0x00, 0x70, 0x7c, 0x03, 0x8f, 0x80
  , 0xe3, 0xf8, 0xe3, 0x00, 0x00, 0x03, 0x9c, 0x0f, 0x8c, 0x0f, 0xff, 0x83, 0xf0
  , 0xe7, 0xfc, 0xe3, 0x00, 0x00, 0x03, 0x9c, 0x1f, 0x8c, 0x0f, 0xff, 0x81, 0xf0
  , 0xe7, 0xfc, 0xe3, 0x00, 0x00, 0x03, 0x9c, 0x1f, 0x8c, 0x0f, 0xff, 0x81, 0xf0
  , 0xe7, 0xfc, 0xe0, 0x1c, 0x03, 0x9c, 0x1f, 0xe0, 0x70, 0x0f, 0xf0, 0x7c, 0x00
  , 0xe7, 0xfc, 0xe0, 0x1c, 0x03, 0x9c, 0x1f, 0xe0, 0x70, 0x0f, 0xf0, 0x7e, 0x00
  , 0xe7, 0xfc, 0xe0, 0x1c, 0x03, 0x9c, 0x1f, 0xe0, 0x70, 0x0f, 0xf0, 0x7c, 0x00
  , 0xe7, 0xfc, 0xe0, 0xfc, 0xff, 0xfc, 0x7f, 0x83, 0xff, 0xfc, 0x0c, 0x01, 0x80
  , 0xe7, 0xfc, 0xe0, 0xfc, 0xff, 0xfc, 0x7f, 0x83, 0xff, 0xfc, 0x0c, 0x01, 0x80
  , 0xe3, 0xf8, 0xe0, 0x78, 0xff, 0xfc, 0x7f, 0x03, 0xff, 0xfc, 0x0c, 0x03, 0x80
  , 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x60, 0x00, 0x7f, 0x80, 0x70, 0x0c, 0x0f, 0x80
  , 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x60, 0x00, 0x7f, 0x80, 0x70, 0x0c, 0x0f, 0x80
  , 0xff, 0xff, 0xe0, 0xff, 0x03, 0xe3, 0x9c, 0x1c, 0x60, 0x71, 0xff, 0x8f, 0xf0
  , 0xff, 0xff, 0xe0, 0xff, 0x03, 0xe3, 0x9c, 0x1c, 0x70, 0x71, 0xff, 0x8f, 0xf0
  , 0xff, 0xff, 0xe0, 0xff, 0x03, 0xe3, 0x9c, 0x1c, 0x70, 0x71, 0xff, 0x8f, 0xf0

};
#endif

