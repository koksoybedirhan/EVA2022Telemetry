//Author: b1d0

#include <Arduino.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxHiz 100
#define MinHiz 10

#define MaxVolt  100
#define MinVolt  10

#define MaxBatarya 100
#define MinBatarya  10

#define MaxMotorSicaklik  100
#define MinMotorSicaklik  10

#define MaxBataryaSicaklik 100
#define MinBataryaSicaklik 20

#define MaxLokasyon  100
#define MinLokasyon  50

#define MaxHucreSicaklik 100
#define MinHucreSicaklik 10

#define MaxHucreBatarya 100
#define MinHucreBatarya 10


#define MaxHucre1 199
#define MinHucre2 10

String value = "_";

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    srand(time(0));

    long a;
    long b;
    long c;
    String d = "$GNGGA,151209.000,4103.45377,N,02849.24715,E,1,10,1.7,95.2,M,37.1,M,,*76";
    long e;
    long f;
    long g;
    long h;
    long j;
    String z = "11_22_33_$GNGGA,151209.000,4103.45377,N,02849.24715,E,1,10,1.7,95.2,M,37.1,M,,*76_55_66";

    for (int i = 1; i > 0; ++i) {
        a++;
        b++;
        c++;
        e++;
        f++;
        
        Serial.print(a + value + b + value + c + value + d + value + e + value + f);

        delay(1500);
        
    } 
}
