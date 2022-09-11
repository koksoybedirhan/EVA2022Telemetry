# EVA2022Telemetry

Author: b1d0

EVA Team 2022 Telemetry Codes
Vehicle Control System card = Arduino Mega 2560 R3
Telemetry Card = Arduino Mega 2560 R3
Ground Station Card = Arduino Mega 2560 R3
GSM Module = Arduino GSM Shield 2
LoRa Modules = LoRa SX 1278
LoRa Module Antenna (Transmitter) = TX433-JKD-20P
LoRa Module Antenna (Receiver) = DRFA-433Y

GSM Communication:
Vehicle Control System card taking variables and concatenates all the data into the defined string. After that sending, Telemetry Card with Arduino GSM Shield 2 takes sending variables and sends directly to web server. This system is sample of telemetry system. In the race day, Telemetry system will take data from actual vehicle control system card.

LoRa Communication:
Vehicle Control System card with LoRa SX 1278 seperates predetermined instant data and puts into struct. After that, it will send data to Ground Station card with LoRa module. Ground Station card takes data with own LoRa module and it will send variables via COM Port to EVA Team Telemetry Application.

GSM communication can send datas with 3 seconds because of 2G (It depends web server quality. When we use free web server, it takes 4 second and after we changed with great web server but it's still taking 3 second.), but GSM communication can send big datas (It means bytes, not everything.). In response of this, LoRa communication can send datas with 0.65 second. In the other handi LoRa can send only 58 byte packet. 
So, we are sending instant changing datas with LoRa communication like speed and sending other datas which is required but non-immediate data with GSM.


