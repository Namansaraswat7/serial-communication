#include<Wire.h>
#define Red 8
#define Green 9

int x = 0;
void setup() {
  // Define the LED pin as Output
  pinMode (Red, OUTPUT);
  pinMode(Green,OUTPUT);
 // digitalWrite(LED,HIGH);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read(); 
  }
  // digitalWrite(LED, HIGH);
    //delay(50);
    //digitalWrite(LED, LOW);
    //delay(50);
  // read one character from the I2C

void loop() {
  //If value received is 0 blink LED for 200 ms
  if (x == 'R') {
    digitalWrite(Red, HIGH);
    //delay(200);
    digitalWrite(Green, LOW);
    //delay(200);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 'G') {
    digitalWrite(Red, LOW);
    //delay(400);
    digitalWrite(Green, HIGH);
  //  delay(400);
  }
   if (x == 'A') {
    digitalWrite(Red, HIGH);
    //delay(400);
    digitalWrite(Green, HIGH);
  //  delay(400);
  }
   if (x == '0') {
    digitalWrite(Red, LOW);
    //delay(400);
    digitalWrite(Green, LOW);
  //  delay(400);
  }
   
  
}
