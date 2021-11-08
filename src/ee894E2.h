/***************************************************************************/
/* headerfile for "ee894E2.cpp" module */
/***************************************************************************/
/*
Read functions for measurement values of the EE894 Sensor via E2 interface.

Copyright 2021 E+E Elektronik Ges.m.b.H.

Disclaimer:
This application example is non-binding and does not claim to be complete with regard
to configuration and equipment as well as all eventualities. The application example
is intended to provide assistance with the EE894 sensor module design-in and is provided "as is".
You yourself are responsible for the proper operation of the products described.
This application example does not release you from the obligation to handle the product safely
during application, installation, operation and maintenance. By using this application example,
you acknowledge that we cannot be held liable for any damage beyond the liability regulations
described.

We reserve the right to make changes to this application example at any time without notice.
In case of discrepancies between the suggestions in this application example and other E+E
publications, such as catalogues, the content of the other documentation takes precedence.
We assume no liability for the information contained in this document.
*/

#ifndef ee894E2_H
#define ee894E2_H

#include "Arduino.h"
#include "e2Interface.h"


// constant definition
//-----------------------------------------------------------------------------
#define CB_TYPELO 0x11 					//controlbyte for reading sensortype low-byte
#define CB_TYPESUB 0x21 				//controlbyte for reading sensor-Subtype
#define CB_AVPHMES 0x31 				//controlbyte for reading available physical measurements
#define CB_TYPEHI 0x41 					//controlbyte for reading sensortype high-byte
#define CB_STATUS 0x71 					//controlbyte for reading statusbyte
#define CB_MV1LO 0x81 					//controlbyte for reading measurement value 1 low-byte
#define CB_MV1HI 0x91 					//controlbyte for reading measurement value 1 high-byte
#define CB_MV2LO 0xA1 					//controlbyte for reading measurement value 2 low-byte
#define CB_MV2HI 0xB1 					//controlbyte for reading measurement value 2 high-byte
#define CB_MV3LO 0xC1 					//controlbyte for reading measurement value 3 low-byte
#define CB_MV3HI 0xD1 					//controlbyte for reading measurement value 3 high-byte
#define CB_MV4LO 0xE1 					//controlbyte for reading measurement value 4 low-byte
#define CB_MV4HI 0xF1 					//controlbyte for reading measurement value 4 high-byte


// declaration of functions
//-----------------------------------------------------------------------------

class ee894E2
{	

public:	
ee894E2(void);
ee894E2(int _SDA, int _SCL);

uint8_t readMeasValue(float &value,unsigned char controlBytes[], int scaleFactor); //Read two bytes and treat them as measurement values
uint8_t readSensorType(unsigned int &sensorType); 		// read sensortype from E2-Interface
uint8_t readSensorSubType(uint8_t &sensorSubType); 	// read sensor subtype from E2-Interface
uint8_t readAvailablePhysicalMeasurements(uint8_t &availablePhysicalMeasurements); 	//read available physical measurements from E2-Interface
uint8_t readRh(float &humidity); 						//read measurement value 1 (relative humidity [%RH])
uint8_t readTemp(float &temperature); 					//read measurement value 2 (temperature [°C])
uint8_t readPres(float &pressure); 					//read measurement value 3 (ambient pressure [mbar])
uint8_t readCo2Mean(float &Co2); 				//read measurement value 4 (CO2 mean [ppm])
uint8_t readStatus(void); 		//read statusbyte from E2-Interface
void getErrorString(unsigned char e2Status, char errorString[]);
};

#endif
