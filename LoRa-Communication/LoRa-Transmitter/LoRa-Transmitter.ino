#include "Arduino.h"
#include "LoRa_E32.h"
#include "TinyGPS++.h"
#include <SoftwareSerial.h>

SoftwareSerial portLora(10, 11);
LoRa_E32 e32ttl(&portLora);

TinyGPSPlus gps;

float sicaklik1float = 36.0;
float hizfloat = 52.0;
float voltfloat = 5182.0;
float enerjifloat = 54.0;
float sicaklik2float = 70.0;
float sicaklik3float = 13.0;

typedef struct {
byte sicaklik1[5];
byte hiz[5];
byte volt[5];
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
  *(float*)(data.sicaklik1) = sicaklik1float;
  *(float*)(data.hiz) = hizfloat;
  *(float*)(data.volt) = voltfloat;
  *(float*)(data.enerji) = enerjifloat;
  *(float*)(data.sicaklik2) = sicaklik2float;
  *(float*)(data.sicaklik3) = sicaklik3float;
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
      delay(4*1000);*/
    //}      
  //}  
  ResponseStatus rs = e32ttl.sendFixedMessage(0, 16, 29, &data, sizeof(Signal));
  Serial.println(rs.getResponseDescription());
  delay(650);
}
