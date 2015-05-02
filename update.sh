#!/bin/sh

/etc/init.d/openrov stop
git pull origin master
/opt/node/bin/npm install
/opt/openrov/cockpit/linux/arduino/firmware-installfromsource.sh
/etc/init.d/openrov start
