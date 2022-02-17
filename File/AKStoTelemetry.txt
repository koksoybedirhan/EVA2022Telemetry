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

String value = ",";

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    srand(time(0));

    long a;
    long b;
    long c;
    long d;
    long e;
    long f;
    long g;
    long h;
    long j;

    for (int i = 1; i > 0; ++i) {
        a = rand() % MaxHiz + MinHiz;
        b = rand() % MaxVolt + MinVolt;
        c = rand() % MaxBatarya + MinBatarya;
        d = rand() % MaxMotorSicaklik + MinMotorSicaklik;
        e = rand() % MaxBataryaSicaklik + MinBataryaSicaklik;
        f = rand() % MaxLokasyon + MinLokasyon;
        g = rand() % MaxHucreSicaklik + MinHucreSicaklik;
        h = rand() % MaxHucreBatarya + MinHucreBatarya;
        j = rand() % MaxHucreBatarya + MinHucreBatarya;

        Serial.print(a + value + b + value + c + value + d + value + e + value + f + value + g + value + h);

        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
    }
}