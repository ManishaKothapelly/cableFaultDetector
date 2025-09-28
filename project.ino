#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(2, 3);


const int pf11=0;
const int pf12=1;
const int pf13=4;
const int pf14=5;

const int pf21=6;
const int pf22=7;
const int pf23=8;
const int pf24=9;

const int pf31=10;
const int pf32=11;
const int pf33=12;
const int pf34=13;

int pf11val=1;
int pf12val=1;
int pf13val=1;
int pf14val=1;

int pf21val=1;
int pf22val=1;
int pf23val=1;
int pf24val=1;

int pf31val=1;
int pf32val=1;
int pf33val=1;
int pf34val=1;

const int relay1=14;
const int relay2=15;
const int relay3=16;


void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome To Cable");
lcd.setCursor(0,1);
lcd.print("Fault Project");
pinMode(pf11,INPUT_PULLUP);
pinMode(pf12,INPUT_PULLUP);
pinMode(pf13,INPUT_PULLUP);
pinMode(pf14,INPUT_PULLUP);

pinMode(pf21,INPUT_PULLUP);
pinMode(pf22,INPUT_PULLUP);
pinMode(pf23,INPUT_PULLUP);
pinMode(pf24,INPUT_PULLUP);


pinMode(pf31,INPUT_PULLUP);
pinMode(pf32,INPUT_PULLUP);
pinMode(pf33,INPUT_PULLUP);
pinMode(pf34,INPUT_PULLUP);


pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
Serial.begin(9600);   
mySerial.begin(9600);   

digitalWrite(relay1,HIGH);
digitalWrite(relay2,HIGH);
digitalWrite(relay3,HIGH);
delay(2500);
 Serial.println("AT+CMGF=1");    
  delay(1000); 
  mySerial.println("AT+CMGS=\"+918639427618\"\r"); 
  delay(1000);
  mySerial.println("I am test SMS from GSM Module");
  delay(100);
  mySerial.println((char)26);
  delay(1000);

}

void loop()
{
delay(100); 
pf11val=digitalRead(pf11);
pf12val=digitalRead(pf12);
pf13val=digitalRead(pf13);
pf14val=digitalRead(pf14);

pf21val=digitalRead(pf21);
pf22val=digitalRead(pf22);
pf23val=digitalRead(pf23);
pf24val=digitalRead(pf24);


pf31val=digitalRead(pf31);
pf32val=digitalRead(pf32);
pf33val=digitalRead(pf33);
pf34val=digitalRead(pf34);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("P1    P2    P3");
lcd.setCursor(0,1);
lcd.print("NF    NF    NF");
digitalWrite(relay1,HIGH);
digitalWrite(relay2,HIGH);
digitalWrite(relay3,HIGH);

delay(1000);
if(pf11val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -1 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-1Km");
digitalWrite(relay1,LOW);
SendSMS11();    //Send one SMS

delay(4000);
}
if(pf12val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -1 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-2Km");
digitalWrite(relay1,LOW);
SendSMS12();    //Send one SMS

delay(4000);
}
if(pf13val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -1 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-3Km");
digitalWrite(relay1,LOW);
SendSMS13();    //Send one SMS

delay(4000);
}

if(pf14val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -1 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-4Km");
digitalWrite(relay1,LOW);
SendSMS14();    //Send one SMS

delay(4000);
}


if(pf21val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -2 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-1Km");
digitalWrite(relay2,LOW);
SendSMS21();    //Send one SMS

delay(4000);
}
if(pf22val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -2 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-2Km");
digitalWrite(relay2,LOW);
SendSMS22();    //Send one SMS

delay(4000);
}
if(pf23val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -2 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-3Km");
digitalWrite(relay2,LOW);
SendSMS23();    //Send one SMS

delay(4000);
}

if(pf24val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -2 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-4Km");
digitalWrite(relay2,LOW);
SendSMS24();    //Send one SMS

delay(4000);
}

if(pf31val==LOW)
{

lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -3 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-1Km");
digitalWrite(relay3,LOW);
SendSMS31();    //Send one SMS

delay(4000);
}
if(pf32val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -3 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-2Km");
digitalWrite(relay3,LOW);
SendSMS32();    //Send one SMS

delay(4000);
}
if(pf33val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -3 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-3Km");
digitalWrite(relay3,LOW);
SendSMS33();    //Send one SMS

delay(4000);
}

if(pf34val==LOW)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PHASE -3 FAULT  ");
lcd.setCursor(0,1);
lcd.print(" @-4Km");
digitalWrite(relay3,LOW);
SendSMS34();    //Send one SMS

delay(4000);
}

      
}

void SendSMS11()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r");
  delay(1000);
  mySerial.println("Phase  1  Fault Occur @1Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26);
  delay(1000);  
}
void SendSMS12()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  1  Fault Occur @2Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS13()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  1  Fault Occur @3Km!");
  mySerial.println("lat:17.344850, long:78.324472");
  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS14()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  1  Fault Occur @4Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS21()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r");  
  delay(1000);
  mySerial.println("Phase  2  Fault Occur @1Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}
void SendSMS22()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  2  Fault Occur @2Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS23()
{
  mySerial.println("AT+CMGF=1");  
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r");  
  delay(1000);
  mySerial.println("Phase  2  Fault Occur @3Km!");
  mySerial.println("lat:17.344850, long:78.324472");
  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS24()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  2 Fault Occur @4Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS31()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  3  Fault Occur @1Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}
void SendSMS32()
{
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  3  Fault Occur @2Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}

void SendSMS33()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r");  
  delay(1000);
  mySerial.println("Phase  3  Fault Occur @3Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26);
  delay(1000);  
}

void SendSMS34()
{
  mySerial.println("AT+CMGF=1");  
  delay(1000);
  mySerial.println("AT+CMGS=\"+9186394276xx\"\r"); 
  delay(1000);
  mySerial.println("Phase  3  Fault Occur @4Km!");
  mySerial.println("lat:17.344850, long:78.324472");

  delay(200);
  mySerial.println((char)26); 
  delay(1000);  
}
