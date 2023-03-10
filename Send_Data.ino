#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define NSS 5
#define rst 0
#define DIO0 27

int counter = 0;

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("This LoRa as Sender");

  //setup LoRa transceiver module
  LoRa.setPins(NSS, rst, DIO0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa GeT Ready!!!");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print("Hallo Packet LoRa Already Send!!!");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
