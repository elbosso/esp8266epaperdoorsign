#!/usr/bin/python

# Copyright (c) 2018.
#
# Juergen Key. Alle Rechte vorbehalten.
#
# Weiterverbreitung und Verwendung in nichtkompilierter oder kompilierter Form,
# mit oder ohne Veraenderung, sind unter den folgenden Bedingungen zulaessig:
#
#   1. Weiterverbreitete nichtkompilierte Exemplare muessen das obige Copyright,
# die Liste der Bedingungen und den folgenden Haftungsausschluss im Quelltext
# enthalten.
#   2. Weiterverbreitete kompilierte Exemplare muessen das obige Copyright,
# die Liste der Bedingungen und den folgenden Haftungsausschluss in der
# Dokumentation und/oder anderen Materialien, die mit dem Exemplar verbreitet
# werden, enthalten.
#   3. Weder der Name des Autors noch die Namen der Beitragsleistenden
# duerfen zum Kennzeichnen oder Bewerben von Produkten, die von dieser Software
# abgeleitet wurden, ohne spezielle vorherige schriftliche Genehmigung verwendet
# werden.
#
# DIESE SOFTWARE WIRD VOM AUTOR UND DEN BEITRAGSLEISTENDEN OHNE
# JEGLICHE SPEZIELLE ODER IMPLIZIERTE GARANTIEN ZUR VERFUEGUNG GESTELLT, DIE
# UNTER ANDEREM EINSCHLIESSEN: DIE IMPLIZIERTE GARANTIE DER VERWENDBARKEIT DER
# SOFTWARE FUER EINEN BESTIMMTEN ZWECK. AUF KEINEN FALL IST DER AUTOR
# ODER DIE BEITRAGSLEISTENDEN FUER IRGENDWELCHE DIREKTEN, INDIREKTEN,
# ZUFAELLIGEN, SPEZIELLEN, BEISPIELHAFTEN ODER FOLGENDEN SCHAEDEN (UNTER ANDEREM
# VERSCHAFFEN VON ERSATZGUETERN ODER -DIENSTLEISTUNGEN; EINSCHRAENKUNG DER
# NUTZUNGSFAEHIGKEIT; VERLUST VON NUTZUNGSFAEHIGKEIT; DATEN; PROFIT ODER
# GESCHAEFTSUNTERBRECHUNG), WIE AUCH IMMER VERURSACHT UND UNTER WELCHER
# VERPFLICHTUNG AUCH IMMER, OB IN VERTRAG, STRIKTER VERPFLICHTUNG ODER
# UNERLAUBTE HANDLUNG (INKLUSIVE FAHRLAESSIGKEIT) VERANTWORTLICH, AUF WELCHEM
# WEG SIE AUCH IMMER DURCH DIE BENUTZUNG DIESER SOFTWARE ENTSTANDEN SIND, SOGAR,
# WENN SIE AUF DIE MOEGLICHKEIT EINES SOLCHEN SCHADENS HINGEWIESEN WORDEN SIND.

import csv
import datetime
import sys
from collections import namedtuple
import numpy
import pytz
from PIL import Image, ImageDraw, ImageEnhance, ImageFont, ImageOps


# with open("/home/elbosso/Desktop/python.csv") as f:
with open(sys.argv[1]) as f:
    reader = csv.reader(f, delimiter=',')
    top_row = next(reader)
    top_row = [t.lower().split() for t in top_row]
    print(top_row)
    top_row = ["_".join(t) for t in top_row]
    print(top_row)
    print(len(top_row))
    topmap = {}
    Data = namedtuple("Data", top_row)

    for row in reader:
        print(row)
        if len(row) == 5:
            data = Data(*row)
            if (data.bezeichnung in topmap):
                topmap[data.bezeichnung].append(data)
            else:
                topmap[data.bezeichnung] = [data]
    todayMap = {}

    for k in topmap:
        print(k)
        list = topmap[k]
        data = list[0]
        print(data)
        von = datetime.datetime.strptime(data.von[:-3], "%Y-%m-%d %H:%M:%S")
        bis = datetime.datetime.strptime(data.bis[:-3], "%Y-%m-%d %H:%M:%S")
        now = datetime.datetime.now()
        print(von, bis, now)
        print(von.date(), now.date())

        if(von.date() == now.date()):
            print("(!)", data.bezeichnung)
            todayMap[von] = data
    print("---")

    for k in todayMap:
        print(todayMap[k].bezeichnung)
    items = []
    for k in sorted(todayMap.keys()):
        print(todayMap[k].bezeichnung)
        if(len(items) < 3):
            items.append(todayMap[k])
        else:
            middle = items[1]
            von = datetime.datetime.strptime(
                middle.von[:-3], "%Y-%m-%d %H:%M:%S")
            bis = datetime.datetime.strptime(
                middle.bis[:-3], "%Y-%m-%d %H:%M:%S")
            now = datetime.datetime.now()
            if(von > now):
                print("lock")
            else:
                print("not now:", middle)
                items = items[1:]
                items.append(todayMap[k])
    print("---")
    for item in items:
        print(item)
    # source_img = Image.open("source.jpg").convert("RGBA")

    # create image with size (100,100) and black background
    button_img = Image.new('RGBA', (640, 384), "white")

    # put text on image
    button_draw = ImageDraw.Draw(button_img)
    y = 0
    tz = pytz.timezone('Europe/Berlin')
    now = datetime.datetime.now(tz)
    button_draw.text((20, y), 'Letzte Aktualisierung: ',
                     font=ImageFont.truetype("arial", 27), fill=(0, 0, 0, 255))
    button_draw.text((300, y), now.strftime("%Y-%m-%d %H:%M:%S"),
                     font=ImageFont.truetype("arial", 27), fill=(0, 0, 0, 255))

    y += 50
    for item in items:
        von = datetime.datetime.strptime(item.von[:-3], "%Y-%m-%d %H:%M:%S")
        bis = datetime.datetime.strptime(item.bis[:-3], "%Y-%m-%d %H:%M:%S")
        button_draw.text((20, y), von.strftime(
            "%H:%M:%S"), font=ImageFont.truetype("arial", 27), fill=(0, 0, 0, 255))
        button_draw.text((220, y), bis.strftime(
            "%H:%M:%S"), font=ImageFont.truetype("arial", 27), fill=(0, 0, 0, 255))
        button_draw.text((150, y+30), item.bezeichnung,
                         font=ImageFont.truetype("arial", 27), fill=(0, 0, 0, 255))
        y += 100
#    tz = pytz.timezone('Europe/Berlin')
#    now = datetime.datetime.now(tz)
#    button_draw.text((20, 100), str(now), font=ImageFont.truetype("arial",27), fill=(0,0,0,255))

    del button_draw

#    button_img=ImageOps.mirror(button_img)
#    button_img=ImageOps.flip(button_img)
    # put button on source image in position (0, 0)
    # source_img.paste(button_img, (0, 0))

    # save in new file
    button_img.save("/tmp/output.png")
    # button_img.netpbm.to_file("./output2.pbm")
    # button_img.save("./output.png", "png")

    button_img = numpy.array(button_img)
    with open(sys.argv[2], 'w') as fd:
        fd.write("P1\n{1} {0}\n".format(
            button_img.shape[0], button_img.shape[1]))
        fd.write("\n".join(
            " ".join(str(1 if i[0] <128 else 0) for i in j) for j in button_img))
        fd.close