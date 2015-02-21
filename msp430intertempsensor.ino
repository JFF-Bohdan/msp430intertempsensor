#include "internaltempsensor.h"

InternalTempSensor    intTempSensor(true);

void setup()
{
  Serial.begin(9600);  
  Serial.println("BOOTED");
}

void printDec(int32_t ui) 
{
  if(ui < 0) 
    Serial.print("-");
    
  Serial.print(ui/10, DEC);
  Serial.print(".");
  Serial.print(ui%10, DEC);
}

void loop()
{ 
  int32_t currentValue = intTempSensor.update();
  Serial.print("Internal temperature (integer) : ");
  printDec(currentValue);
  Serial.println();
  
  Serial.print("Internal temperature (float)   : ");
  Serial.print(intTempSensor.temperatureFloat());
  Serial.println();  
  
  delay(2000);   
}



