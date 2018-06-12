#include<Wire.h>
//const byte slaveId=2;
int x = 0;
int reading=0;
int mid;

void setup() {
  Wire.begin(9);
 // Wire.onReceive(receiveEvent);
 pinMode(A0,INPUT);
 
 pinMode(7,OUTPUT);
pinMode(5,OUTPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(3,OUTPUT);
pinMode(11,OUTPUT);
pinMode(6,INPUT);
pinMode(4,INPUT);
 Wire.onReceive(receiveEvent);
//digitalWrite(13,LOW);
}
void receiveEvent(int bytes) {
  x = Wire.read(); 
  }
void loop() {
  if(x=='L')
  {
     reading=analogRead(A0);
  Serial.println(reading);
  if(reading<=500)
  {mid=1;
  }
  if(reading>=580)
  {
    mid=0;
     }
    if(mid==1)
    {digitalWrite(12,HIGH);
      }
      if(mid==0)
      digitalWrite(12,LOW);
    }
    if(x=='U')
    {long durationr,distancer;
 digitalWrite(7,LOW);
 delayMicroseconds(2);
 digitalWrite(7,HIGH);
 delayMicroseconds(10);
 digitalWrite(7,LOW);
 durationr=pulseIn(6,HIGH);
 distancer=(durationr/2)/29.1;
 Serial.println(distancer);
 long durationl,distancel;
 digitalWrite(5,LOW);
 delayMicroseconds(2);
 digitalWrite(5,HIGH);
 delayMicroseconds(10);
 digitalWrite(5,LOW);
 durationl=pulseIn(4,HIGH);
 distancel=(durationl/2)/29.1;
 Serial.println(distancel);
 if(distancer<200)
 {digitalWrite(13,HIGH);
  }
  if(distancer<100)
  {digitalWrite(12,HIGH);
   // delay(100);
    //digitalWrite(12,LOW);
    //delay(100);
    }
     if(distancel<200)
 {digitalWrite(3,HIGH);
  }
  if(distancel<100)
  {digitalWrite(11,HIGH);
    //delay(100);
    //digitalWrite(11,LOW);
    //delay(100);
    }
     if(distancer>200)
 {digitalWrite(13,LOW);digitalWrite(12,LOW);
  }
   if(distancel>200)
 {digitalWrite(3,LOW);digitalWrite(11,LOW);
  }
  
      }
  
  if (x == '0') {
     digitalWrite(7,LOW);
      digitalWrite(5,LOW);
       digitalWrite(13,LOW);
        digitalWrite(3,LOW);
         digitalWrite(11,LOW);
          digitalWrite(6,LOW);
           digitalWrite(4,LOW);
           // digitalWrite(12,LOW);
             //digitalWrite(12,LOW);
  }
 }


