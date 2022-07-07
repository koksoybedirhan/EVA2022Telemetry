#include "Arduino.h"
#include "LoRa_E32.h"
#include <SoftwareSerial.h>
SoftwareSerial loraSerial(10, 11);
LoRa_E32 e32ttl(&loraSerial);
String value = ",";

void setup()
{
  Serial.begin(9600);
  delay(100);
  e32ttl.begin();
  Serial.println();

}
typedef struct {
byte sicaklik1[5];
byte hiz[5];
byte volt[5];
byte enerji[5];
byte sicaklik2[5];
byte sicaklik3[5];
} Signal;
Signal rocket;

void loop()
{
  if (e32ttl.available()  > 1){
    ResponseStructContainer rsc = e32ttl.receiveMessage(sizeof(Signal));
    rocket = *(Signal*) rsc.data;7
    //Veriler arasına "," konularak ayrıştırma kolaylaştırılmaktadır.
    // "/" son verinin geldiğini bildirmektedir.
    Serial.print(*(float*)rocket.hiz,1);
    Serial.print(value);
    Serial.print(*(float*)rocket.volt,1);
    Serial.print(value);
    Serial.print(*(float*)rocket.enerji,1);
    Serial.print(value);
    Serial.print(*(float*)rocket.sicaklik1,1);
    Serial.print(value);
    Serial.print(*(float*)rocket.sicaklik2,1);
    Serial.print(value);
    Serial.print(*(float*)rocket.sicaklik3,1);
    Serial.println("/");
    rsc.close();
  }
}
