#!/bin/bash

### MCU ###

# Datasheet
wget -nc http://cache.freescale.com/files/microcontrollers/doc/data_sheet/MC9S08JM60.pdf

# HCS08 Family reference manual
wget -nc http://cache.freescale.com/files/microcontrollers/doc/ref_manual/HCS08RMV1.pdf


### Joystick ###
wget -nc http://www.adafruit.com/datasheets/SKQUCAA010-ALPS.pdf


### H Bridge ###
wget -nc http://www.allegromicro.com/~/media/Files/Datasheets/A3901-Datasheet.ashx
cp A3901-Datasheet.ashx A3901-Datasheet.pdf


### Quadrature encoder ###

# Reflective photointerrupter
wget -nc http://www.sharpsme.com/download/GP2S60-DSpdf
cp GP2S60-DSpdf GP2S60-DS.pdf


### IR receiver ###
wget -nc http://www.vishay.com/docs/82494/tsop752.pdf


### Line sensor ###

# Phototransistor
wget -nc https://www.kingbrightusa.com/images/catalog/spec/APT2012P3BT.pdf


### Color sensor ###
wget -nc http://www.ams.com/eng/content/download/250258/975997/142735
cp 142735 tcs3414.pdf


### Power supply ###

# Lithium battery controller
wget -nc http://ww1.microchip.com/downloads/en/DeviceDoc/21984F.pdf
# LDO
wget -nc http://www.onsemi.com/pub_link/Collateral/NCP605-D.PDF
# Current amplifier
wget -nc http://diodes.com/datasheets/ZXCT1022.pdf


### Accelerometer ###
wget -nc http://www.freescale.com/files/sensors/doc/data_sheet/MMA8452Q.pdf


### Bluetooth module ###
wget -nc http://www.e-gizmo.com/KIT/images/EGBT-04/EGBT-045MS-046S%20Bluetooth%20Module%20Manual%20rev%201r0.pdf
