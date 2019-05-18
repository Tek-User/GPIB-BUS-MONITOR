
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "gpib.h"
#include "Arduino.h"




// GPIB Monitor:
//Strategy #1:  Sniffer:  Should be as close to invisible to the bus as possible.
// All pins should be input-tristate.
// EXCEPT:
// DAV, pin should be input-pullup (equivalent to de-asserted) so there is no spurious noise on the pin.

// Strategy #2 be a standard listener...

//Define monitoring strategy:  Pick ONE:  Uncomment one and comment-out the other
#define SNIFFER
//#define LISTENER



void setup() {
  Serial.begin(115200);
  
  #ifdef SNIFFER
    GPIBInitSniff();
  #else
    #ifdef LISTENER
      GPIBInitListen();
    #else
      #error MUST DEFINE EITHER SNIFFER OR LISTENER
    #endif
  #endif



}


#ifdef SNIFFER
void loop() {
  long counter= 0;

//  monitor for a byte coming in and send it to the serial port:
//  wait for DAV to be asserted, then read the data, then wait for DAV to be de-asserted
//  then repeat....

  while(!GPIBDataReady()){   //wait for data  to be ready on the bus
     counter++;
     if (counter > 12000000l) {
         Serial.println(F("Waiting..."));
         counter = 0;
     } // end if
  }  // end while
  counter = 0;
  Serial.write(GPIBReadByte()); //read and send the data
  if ((EOI_PIN & EOI_BIT) == 0) Serial.println();  //send new line if it id the end of a message
  while (GPIBDataReady()); // wait for the data to be finished

  
} //end loop
#endif




#ifdef LISTENER
void loop() {
  GPIBMonitor();
}
#endif
