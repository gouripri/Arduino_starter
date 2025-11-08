#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001"; // address must match receiver

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening(); // this one sends data
}

void loop() {
  const char text[] = "Hello!";
  radio.write(&text, sizeof(text));
  delay(1000); // send every second
}
