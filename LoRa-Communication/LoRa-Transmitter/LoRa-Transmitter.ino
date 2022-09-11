//Author: b1d0

#include "Arduino.h"
#include "LoRa_E32.h"
#include "TinyGPS++.h"
#include <SoftwareSerial.h>

SoftwareSerial portLora(10, 11);
LoRa_E32 e32ttl(&portLora);

TinyGPSPlus gps;

float sicaklik1float;
float hizfloat;
float voltfloat;
float enerjifloat;
float sicaklik2float;
float sicaklik3float;

String gelenString;
char gelenChar[30];
int i = 0;

typedef struct {
byte sicaklik1[5];
byte hiz[5];
byte volt[7];
byte enerji[5];
byte sicaklik2[5];
byte sicaklik3[5];
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
  hizfloat = random(10.0,99.9);
  voltfloat = random(1000.0,9999.9);
  enerjifloat = random(10.0,99.9);
  sicaklik1float = random(10.0,99.9);
  sicaklik2float = random(10.0,99.9);
  sicaklik3float = random(10.0,99.9);
  *(float*)(data.hiz) = hizfloat,1;
  *(float*)(data.volt) = voltfloat,1;
  *(float*)(data.enerji) = enerjifloat,1;
  *(float*)(data.sicaklik1) = sicaklik1float,1;
  *(float*)(data.sicaklik2) = sicaklik2float,1;
  *(float*)(data.sicaklik3) = sicaklik3float,1;
  Serial.print(*(float*)data.hiz, 1);
  Serial.print(" ");
  Serial.print(*(float*)data.volt,1 );
  Serial.print(" ");
  Serial.print(*(float*)data.enerji, 1);
  Serial.print(" ");
  Serial.print(*(float*)data.sicaklik1, 1);
  Serial.print(" ");
  Serial.print(*(float*)data.sicaklik2, 1);
  Serial.print(" ");
  Serial.print(*(float*)data.sicaklik3, 1);
  Serial.print(" ");
  /*while(Serial2.available()) //Eğer GPS kullanılacaksa burası aktif edilecek.
  {
    if(gps.encode(Serial2.read()))
    {
      String msg = Serial2.readStringUntil('\r');
      Serial.println(msg);
      Serial.print("LAT="); Serial.println(gps.location.lat(), 6);
      (float)(data.latitude) = (gps.location.lat());
      Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
      (float)(data.longtitude) = (gps.location.lng());
      Serial.print("ALT="); Serial.println(gps.altitude.meters(), 1);
      (float)(data.altitude) = (gps.altitude.meters());
      delay(4*1000);
    }      
  }*/
  ResponseStatus rs = e32ttl.sendFixedMessage(0, 16, 29, &data, sizeof(Signal));
  Serial.println(rs.getResponseDescription());
  delay(650);
}
