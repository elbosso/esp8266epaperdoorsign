# esp8266epaperdoorsign

<!---
[![start with why](https://img.shields.io/badge/start%20with-why%3F-brightgreen.svg?style=flat)](http://www.ted.com/talks/simon_sinek_how_great_leaders_inspire_action)
--->
[![GitHub release](https://img.shields.io/github/release/elbosso/esp8266epaperdoorsign/all.svg?maxAge=1)](https://GitHub.com/elbosso/esp8266epaperdoorsign/releases/)
[![GitHub tag](https://img.shields.io/github/tag/elbosso/esp8266epaperdoorsign.svg)](https://GitHub.com/elbosso/esp8266epaperdoorsign/tags/)
[![GitHub license](https://img.shields.io/github/license/elbosso/esp8266epaperdoorsign.svg)](https://github.com/elbosso/esp8266epaperdoorsign/blob/master/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/elbosso/esp8266epaperdoorsign.svg)](https://GitHub.com/elbosso/esp8266epaperdoorsign/issues/)
[![GitHub issues-closed](https://img.shields.io/github/issues-closed/elbosso/esp8266epaperdoorsign.svg)](https://GitHub.com/elbosso/esp8266epaperdoorsign/issues?q=is%3Aissue+is%3Aclosed)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/elbosso/esp8266epaperdoorsign/issues)
[![GitHub contributors](https://img.shields.io/github/contributors/elbosso/esp8266epaperdoorsign.svg)](https://GitHub.com/elbosso/esp8266epaperdoorsign/graphs/contributors/)
[![Github All Releases](https://img.shields.io/github/downloads/elbosso/esp8266epaperdoorsign/total.svg)](https://github.com/elbosso/esp8266epaperdoorsign)
[![Website elbosso.github.io](https://img.shields.io/website-up-down-green-red/https/elbosso.github.io.svg)](https://elbosso.github.io/)

I got my inspiration from https://ct.de/yrzv, however i wanted to use only an ESP8266. I came upon https://github.com/skx/esp8266, however i resented the idea of inventing yet another image format when http://netpbm.sourceforge.net/doc/pbm.html has been around for decades (and i also loathe php).

So - this happened: included is the code for the ESP8266 (upload it with the Arduino IDE for example) and a python script for creating the Image. The third thing is a bash snippet for converting PNG to PBM.
