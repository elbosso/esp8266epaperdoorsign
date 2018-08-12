#!/bin/bash
<path>/createImage.py
pngtopnm -mix -background "#FFFFFF" /tmp/output.png |ppmtopgm | pgmtopbm |pnmtoplainpnm >/var/www/html/Hardware/d1-epaper/wss.pbm
chown www-data:www-data /var/www/html/Hardware/d1-epaper/wss.pbm
