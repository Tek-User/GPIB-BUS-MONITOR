# GPIB-BUS-MONITOR

This is an Arduino project.  The program uses two GPIB bus monitoring strategies to watch traffic on the bus.  It can be a Sniffer where it is as close to invisible to the bus as possible.  Or it can be a Listener which actively participates on the bus for listening purposes.  The Arduino platform with minimal hardware as a "listener" can support only a few other devices on the bus because it has current limits on pulling-down the bus when asserting a signal.

Both strategies were tested with two other devices on the bus:  a National Instruments GPIB controller card and a Tektronix 2440 DSO oscilloscope and both techniques functioned well.

The hardware used is an Arduino Nano.  It has enough IO to manage all 16 GPIB signals.

Included in this project is an EAGLE PCB design to connect the Nano to a GPIB header.  You can use a Centronics style GPIB connector or simply hand solder all the GPIB wires directly to the PCB.
