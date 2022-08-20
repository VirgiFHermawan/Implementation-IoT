
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLIvsSddsL"
#define BLYNK_DEVICE_NAME "Device"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

//IN1 = D1 KUNING 5
//IN2 = D6 ORANGE 12
//IN3 = D4 BIRU 2 
//IN4 = D7 UNGU 13
//D8 = trigpin 15
//D5 = echopin 14


// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

BLYNK_WRITE(V0)//majubos
{
  if(param.asInt()==1)
  {
    majubos();
  }
  else
  {
    berentibos();
  }
}

BLYNK_WRITE(V1)//mundurbos
{
  if(param.asInt()==1)
  {
    mundurbos();
  }
  else
  {
    berentibos();
    digitalWrite(14, LOW);
  }
}

BLYNK_WRITE(V2)//majukananbos
{
  if(param.asInt()==1)
  {
    majukananbos();
  }
  else
  {
    berentibos();
  }
}

BLYNK_WRITE(V3)//majukiribos
{
  if(param.asInt()==1)
  {
    majukiribos();  }
  else
  {
    berentibos();
  }
}

BLYNK_WRITE(V4)//lampudepan
{
  if(param.asInt()==1)
  {
    Serial.println("1");
  }
  else
  {
    Serial.println("0");
  }
}

BLYNK_WRITE(V5)//lampubelakang
{
  if(param.asInt()==1){
    Serial.println("5");
  }
  else{
    Serial.println("6");
  }
}

BLYNK_WRITE(V6)//mundurkananbos
{
  if(param.asInt()==1)
  {
    mundurkananbos();
  }
  else
  {
    berentibos();
  }
}

BLYNK_WRITE(V7)//mundurkiribos
{
  if(param.asInt()==1)
  {
    mundurkiribos();
  }
  else
  {
    berentibos();
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);  
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, INPUT);
  pinMode(15, OUTPUT);
  Serial.begin(9600);
  BlynkEdgent.begin();
}

void loop() 
{
  BlynkEdgent.run();
  digitalWrite(15, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(15, HIGH);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(14, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Blynk.virtualWrite(V8, distance);
}

void berentibos()
{
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(2,LOW);
  digitalWrite(13,LOW);      
}

void jalanbos()
{
  digitalWrite(5,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(13,HIGH);      
}

void majubos()
{
 digitalWrite(2, HIGH);
 digitalWrite(5, HIGH);
}

void majukananbos()
{
 digitalWrite(2, HIGH);
 digitalWrite(13, LOW);
}

void majukiribos()
{
 digitalWrite(5, HIGH);
 digitalWrite(12, LOW);
}

void mundurkananbos()
{
 digitalWrite(12, HIGH);
 digitalWrite(5, LOW);
}

void mundurkiribos()
{
 digitalWrite(13, HIGH);
 digitalWrite(2, LOW);
}

void mundurbos()
{
 digitalWrite(12, HIGH);
 digitalWrite(13, HIGH);
}
