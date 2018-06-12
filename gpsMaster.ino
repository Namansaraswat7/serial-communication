#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(8,1); 
  while(Wire.available())
  {int c = Wire.read();
  //c=c<<8;
  //c|=Wire.read();
   Serial.println(c); 
    
    }// request 6 bytes from slave device #8

 // while (Wire.available()) { // slave may send less than requested
   // int c = Wire.read(); // receive a byte as character
    //Serial.println(c);         // print the character
  //}

  delay(500);
}
