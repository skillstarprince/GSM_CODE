
String textMessage;
const int LED1 = 13;
const int LED2 = 11;
const int LED3 = 12;  
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(19200);
//Give time to GSM shield log on to network
delay(2000);
//AT Command to set SIM900 to SMS Mode
Serial.println("AT+CMGF=1\r");
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  textMessage = Serial.readString();
  textMessage.toUpperCase();
  delay(100);
}
if(textMessage.indexOf("LED1ON")>=0)
{
  digitalWrite(LED1,HIGH);
  textMessage = "";
  delay(1000);
}
if(textMessage.indexOf("LED2ON")>=0)
{
  digitalWrite(LED2,HIGH);
  textMessage = "";
}
if(textMessage.indexOf("LED3ON")>=0)
{
  digitalWrite(LED3,HIGH);
  textMessage = "";
}
if(textMessage.indexOf("LED1OFF")>=0)
{
  digitalWrite(LED1,LOW);
  textMessage = "";
}
if(textMessage.indexOf("LED2OFF")>=0)
{
  digitalWrite(LED2,LOW);
  textMessage = "";
}
if(textMessage.indexOf("LED3OFF")>=0)
{
  digitalWrite(LED3,LOW);
  textMessage = "";
}
if(textMessage.indexOf("ALLON")>=0)
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  textMessage = "";
}
if(textMessage.indexOf("ALLOFF")>=0)
{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  textMessage = "";
}
}
