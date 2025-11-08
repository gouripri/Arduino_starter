#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define width 128
#define height 32
#define addr 0x3c

Adafruit_SSD1306 display(width, height);



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, addr);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.println("Hey girl heyyyy");

  display.display();
  delay(200);

}

void loop() {
  delay(2000);
  updateScreen(">:)");
  delay(3000);
  updateScreen(">:|");
  delay(3000);
  updateScreen(">:/");
  delay(3000);
  updateScreen(">:\\");
}


void updateScreen(String text){
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println(text);

  display.display();


}
