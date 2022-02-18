#include <GSM.h>
#include <stdio.h>
#include <string.h>
#include <ArduinoJson.h>

#define PINNUMBER ""

#define GPRS_APN       "internet"
#define GPRS_LOGIN     "eva"
#define GPRS_PASSWORD  "123"

GSMClient client;
GPRS gprs;
GSM gsmAccess;

char server[] = "18.194.209.204";
// char path[] = "/api/send/dagilmak_istiyorum";
int port = 3000;

//char server[] = "webhook.site";
//int port = 80;

long result;
boolean notConnected = true;
boolean serverConnection = false;
int i = 0;

StaticJsonBuffer<3000> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;
    }

    Serial.println("bedirhan naber bebegim");

    while (notConnected) {
        if ((gsmAccess.begin(PINNUMBER) == GSM_READY) & (gprs.attachGPRS(GPRS_APN, GPRS_LOGIN, GPRS_PASSWORD) == GPRS_READY)) {
            notConnected = false;
        } else {
            Serial.println("GSM'e baglanilamadi :(");
            delay(1000);
        }
    }

    Serial.println("servera baglaniliyor");
    Serial.println(" ");
}

void loop() {
    if (!client.connected()) {
        client.connect(server, port);
    }

    if (client.connected()) {
        delay(100);

        Serial.println(Serial.readString());

        client.print("POST /api/send/pembe_mezarlik?data=");
        client.print(Serial.readString());
        client.println(" HTTP/1.1");

        client.print("Host: ");
        client.println(server);

        client.println("Accept: /");
        client.println("Accept-Encoding: gzip, deflate");
        client.println("User-Agent: Arduino/1.0");
        client.print("Content-Length: ");
        client.println(object.measureLength());
        client.println();
        object.printTo(client);

        delay(100);
        i++;
        if(i == 30){
          client.flush();
        }
    }
}
