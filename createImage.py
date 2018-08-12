#!/usr/bin/python

from PIL import Image, ImageFont, ImageDraw, ImageEnhance, ImageOps
import datetime
import pytz

#source_img = Image.open("source.jpg").convert("RGBA")

# create image with size (100,100) and black background
button_img = Image.new('RGBA', (640,384), "white")

# put text on image
button_draw = ImageDraw.Draw(button_img)
button_draw.text((20, 70), "very loooooooooooooooooong text", font=ImageFont.truetype("arial",27), fill=(0,0,0,255))
tz = pytz.timezone('Europe/Berlin')
now = datetime.datetime.now(tz)
button_draw.text((20, 100), str(now), font=ImageFont.truetype("arial",27), fill=(0,0,0,255))

del button_draw

button_img=ImageOps.mirror(button_img)
button_img=ImageOps.flip(button_img)
# put button on source image in position (0, 0)
#source_img.paste(button_img, (0, 0))

# save in new file
button_img.save("/tmp/output.png", "png")

