#include "Arduino.h"
#include "LoRa_E32.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
LoRa_E32 e32ttl(&mySerial);

void setup()
{
  Serial.begin(9600);
  while (!Serial) 
  {
      ;
  }
  delay(100);
  e32ttl.begin();
  Serial.println();
}
typedef struct {
byte altitude[5];
byte latitude[10];
byte longtitude[10];
byte hiz[3];
byte volt[3];
byte enerji[3];
byte sicaklik1[3];
byte sicaklik2[3];
byte sicaklik3[3];
} Signal;
Signal data;

void loop()
{
  if (e32ttl.available()  > 1){
    ResponseStructContainer rsc = e32ttl.receiveMessage(sizeof(Signal));
    data = *(Signal*) rsc.data;
    Serial.print(*(float*)data.altitude,1);
    Serial.print(" ");
    Serial.print(*(float*)data.latitude,6);
    Serial.print(" ");
    Serial.print(*(float*)data.longtitude,6);
    Serial.print(" ");
    Serial.print(*(int*)data.hiz);
    Serial.print(" ");
    Serial.print(*(int*)data.volt);
    Serial.print(" ");
    Serial.print(*(int*)data.enerji);
    Serial.print(" ");
    Serial.print(*(int*)data.sicaklik1);
    Serial.print(" ");
    Serial.print(*(int*)data.sicaklik2);
    Serial.print(" ");
    Serial.print(*(int*)data.sicaklik3);
    Serial.println(" ");
    rsc.close();
  }
}
