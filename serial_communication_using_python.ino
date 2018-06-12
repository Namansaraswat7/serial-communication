void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
int i=1;
}
int i=1;
void loop() {
 // int i=1;
Serial.println(i);
i++;
if(i>500)
i=0;
delay(500);
}
