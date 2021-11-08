/*
Example script reading measurement values from the EE894 sensor via E2 interface.

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

#define REQUEST_INTERVAL_MS       2000   
#define CSV_DELIMITER             ','
#include <ee894E2.h>

int SDA_pin = 18;
int SCL_pin = 19;

float temperature, humidity, co2Mean, pressure;
unsigned int sensorType;
uint8_t sensorSubType, availablePhysicalMeasurements, error;
char errorString[40];


ee894E2 e2bus(SDA_pin,SCL_pin); 


float kelvinToCelsius(float Kelvin)
{
  float Celsius = Kelvin - 273.15;
  return Celsius;
}


void errorOutput(uint8_t errorcode, float value, char unit[])
{
  if(errorcode)
  {
    e2bus.getErrorString(errorcode, errorString);
    Serial.println(errorString);  
  }
  else
  {
    Serial.print(value);
    Serial.print(unit);
  }
}


void setup() {
  Serial.begin(9600);
  Serial.print("Sensor type: ");
  error = e2bus.readSensorType(sensorType);
  if(error)
  {
    e2bus.getErrorString(error, errorString);  
    Serial.print(errorString);  
  }
  else
  {
    Serial.println(sensorType);
  }
  
  Serial.print("Sensor sub-type: ");
  error = e2bus.readSensorSubType(sensorSubType);
  if(error)
  {
    e2bus.getErrorString(error, errorString);
    Serial.println(errorString);  
  }
  else
  {
    Serial.println(sensorSubType);
  }
  Serial.print("Available measurands (bitmask): ");
  e2bus.readAvailablePhysicalMeasurements(availablePhysicalMeasurements);
  if(error)
  {
    e2bus.getErrorString(error, errorString);
    Serial.println(errorString);  
  }
  else
  {
    Serial.println(availablePhysicalMeasurements,BIN);
  }
 
  Serial.print("temperature");
  Serial.print(CSV_DELIMITER);
  Serial.print("relative humidity");
  Serial.print(CSV_DELIMITER);
  Serial.print("co2");
  Serial.print(CSV_DELIMITER);
  Serial.println("pressure");
  delay(1000); 							//sensor delay for the first meassurment
}


void loop() 
{
  error = e2bus.readTemp(temperature);
  temperature = kelvinToCelsius(temperature);
  errorOutput(error,temperature, " °C");		
  Serial.print(CSV_DELIMITER);
  errorOutput(e2bus.readRh(humidity),humidity," %RH");
  Serial.print(CSV_DELIMITER);
  errorOutput(e2bus.readCo2Mean(co2Mean),co2Mean," ppm");
  Serial.print(CSV_DELIMITER);
  errorOutput(e2bus.readPres(pressure),pressure, " mbar");
  Serial.println("");  
  
  delay(REQUEST_INTERVAL_MS);			//time until the next loop start 
}  
