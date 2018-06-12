// Include the required Wire library for I2C<br> 
#include<Wire.h>
#include<SoftwareSerial.h>

SoftwareSerial rfidSerial(10,11);//10RX,11TX
boolean counter=true;
#define RELAYPIN 13
char tag[] ="020054BEC72F"; // Replace with your own Tag ID
char input[12];        // A variable to store the Tag ID being presented
int count = 0;   
int reading=0;// A counter variable to navigate through the input[] character array
boolean flag = 0;
char incomingByte;
//#define Red 8
//#define green 9
//int x=0;
void setup() {
  // Start the I2C Bus as Master
 // pinMode(Red,OUTPUT);
  //digitalWrite(Green,LOW);
  Serial.begin(9600);
  delay(10);
  rfidSerial.begin(9600);
  Wire.begin(); 
  pinMode(RELAYPIN,OUTPUT);
}
void loop() {
  if(rfidSerial.available())// Check if there is incoming data in the RFID Reader Serial Buffer.
  {
    count = 0; // Reset the counter to zero
    /* Keep reading Byte by Byte from the Buffer till the RFID Reader Buffer is empty 
       or till 12 Bytes (the ID size of our Tag) is read */
    while(rfidSerial.available() && count < 12) 
    {
      input[count] = rfidSerial.read(); // Read 1 Byte of data and store it in the input[] variable
      count++; // increment counter
      delay(5);
    }
    /* When the counter reaches 12 (the size of the ID) we stop and compare each value 
        of the input[] to the corresponding stored value */
    if(count == 12) // 
    {
      count =0; // reset counter varibale to 0
      flag = 1;
      /* Iterate through each value and compare till either the 12 values are 
         all matching or till the first mistmatch occurs */
      while(count<12 && flag !=0)  
      {
        if(input[count]==tag[count])
        {
        flag = 1;
       // reading=1;
        
        
        } // everytime the values match, we set the flag variable to 1
        else
       { flag= 0;
       //reading=0 ;
       }                       /* if the ID values don't match, set flag variable to 0 and 
                                  stop comparing by exiting the while loop */
        count++; // increment i
      }
    }
    if(flag == 1)// If flag variable is 1, then it means the tags match
    {//reading=1;
      Serial.println("Access Allowed!");
      digitalWrite(RELAYPIN,HIGH);
   
    //  Wire.beginTransmission(9);
  
   
    while(!rfidSerial.available())
    { Wire.beginTransmission(9);
    incomingByte=Serial.read();
    //counter++;
    Wire.write(incomingByte);
    Serial.println(incomingByte);
    Wire.endTransmission();
  }
 // reading=1;//Serial.println("hi");
 }//counter=0;//Serial.println("hello");
    /*if(flag==0)
    { Serial.println("Access Denied");
     while(!rfidSerial.available())
    { Wire.beginTransmission(9);
    incomingByte='0';
    //counter++;
    Wire.write(incomingByte);
    //Serial.println(0);
    Wire.endTransmission();
   
    }}*/
    // if((flag == 1)&&reading==1)If flag variable is 1, then it means the tags match
    /*{
      Serial.println("Access denied");
     // digitalWrite(RELAYPIN,HIGH);
   
    //  Wire.beginTransmission(9);
  
   
    while(!rfidSerial.available())
    { Wire.beginTransmission(9);
    incomingByte='0';
    //counter++;
    Wire.write(incomingByte);
    //Serial.println(incomingByte);
    Wire.endTransmission();
  }
  reading=0;//Serial.println("hi");
 }*///counter=0;//Serial.println("hello");
    if(flag==0)
    { Serial.println("Access Denied");
     while(!rfidSerial.available())
    { Wire.beginTransmission(9);
    incomingByte='0';
    //counter++;
    Wire.write(incomingByte);
    //Serial.println(0);
    Wire.endTransmission();
   
    }// Incorrect Tag Message
while(flag==0)
{digitalWrite(RELAYPIN,HIGH);
delay(300);digitalWrite(RELAYPIN,LOW);
delay(300);if(rfidSerial.available())
break;
}
    }
    /* Fill the input variable array with a fixed value 'F' to overwrite 
    all values getting it empty for the next read cycle */
    for(count=0; count<12; count++) 
    {
      input[count]= 'F';
    }
    count = 0; // Reset counter variable
   // Serial.println("what's up");
}}

