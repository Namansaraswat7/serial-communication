#include<SPI.h>
char buf[100];
volatile byte pos;
volatile boolean process_it;

void setup() {
Serial.begin(115200);
pinMode(MISO,OUTPUT);
SPCR|=_BV(SPE);
pos=0;
process_it=false;
SPI.attachInterrupt();// put your setup code here, to run once:

}
ISR(SPI_STC_vect)
{
  byte c=SPDR;
  if(pos< sizeof buf)
  {buf[pos++]=c;
  if(c=='\n')
  process_it= true;
    }
  }

void loop() {
  // put your main code here, to run repeatedly:
if(process_it)
{buf[pos]=0;
Serial.println(buf);
pos=0;
process_it= false;
  }
}
