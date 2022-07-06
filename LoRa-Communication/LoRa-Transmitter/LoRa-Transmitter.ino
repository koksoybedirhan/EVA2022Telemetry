#include "Arduino.h"
#include "LoRa_E32.h"
#include "TinyGPS++.h"
#include <SoftwareSerial.h>

SoftwareSerial portLora(19, 18);
LoRa_E32 e32ttl(&portLora);

TinyGPSPlus gps;

float hizfloat = 34;
float latfloat = 41.342341;
float longfloat = 28.412512;
float altfloat = 81.5;
float voltfloat = 75;
float enerjifloat = 46;
float sicaklik1float = 29;
float sicaklik2float = 50;
float sicaklik3float = 13;

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

void setup() {
  Serial.begin(9600);
  delay(500);
  //erial2.begin(9600);
  delay(500);
  e32ttl.begin();
}

void loop() 
{
 // while(Serial2.available())
  //{
    *(float*)(data.altitude) = altfloat;
    *(float*)(data.latitude) = latfloat;
    *(float*)(data.longtitude) = longfloat;
    *(float*)(data.hiz) = hizfloat;
    *(float*)(data.volt) = voltfloat;
    *(float*)(data.enerji) = enerjifloat;
    *(float*)(data.sicaklik1) = sicaklik1float;
    *(float*)(data.sicaklik2) = sicaklik2float;
    *(float*)(data.sicaklik3) = sicaklik3float;

    Serial.println(*(float*)data.altitude);
    Serial.println(*(float*)data.latitude);
    Serial.println(*(float*)data.longtitude);
    Serial.println(*(float*)data.hiz);
    Serial.println(*(float*)data.volt);
    Serial.println(*(float*)data.enerji);
    Serial.println(*(float*)data.sicaklik1);
    Serial.println(*(float*)data.sicaklik2);
    Serial.println(*(float*)data.sicaklik3);
    /*if(gps.encode(Serial2.read()))
    {
      String msg = Serial2.readStringUntil('\r');
      Serial.println(msg);

      Serial.print("LAT="); Serial.println(gps.location.lat(), 6);
      (float)(data.latitude) = (gps.location.lat());
      Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
      (float)(data.longtitude) = (gps.location.lng());
      Serial.print("ALT="); Serial.println(gps.altitude.meters(), 1);
      (float)(data.altitude) = (gps.altitude.meters());
      delay(4*1000);*/

      ResponseStatus rs = e32ttl.sendFixedMessage(0, 7, 17, &data, sizeof(Signal));
      Serial.println(rs.getResponseDescription());
      delay(650);
    //}      
  //}  
}
