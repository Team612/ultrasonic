/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
const int TrigPin = 2;
const int EchoPin = 3;
const int OutPin=5;
float cm;
void setup()
{
Serial.begin(9600);
pinMode(TrigPin, OUTPUT);
pinMode(OutPin,OUTPUT);
pinMode(EchoPin, INPUT);

}
void loop()
{
int sum=0;
for(int i=0;i<5;i++){
digitalWrite(TrigPin, LOW);       
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places
sum+=cm;
}
sum/=5;
if(sum<=10){
  digitalWrite(OutPin,HIGH);
}else{
  digitalWrite(OutPin,LOW);
}
Serial.print("Distance avg\t=\t");
Serial.print(sum);
Serial.print("cm");
Serial.println();
delay(500);
}
