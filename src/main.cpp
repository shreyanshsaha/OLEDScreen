#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include "Screen.h"

Screen *screen;

Adafruit_SH1106G* display;

void setup()   {
  Serial.begin(9600);
  display = new Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


  OLEDText::TextConfig config;
  config.textSize = 1;
  config.textColor = SH110X_WHITE;
  config.bgColor = SH110X_BLACK;

  screen = new Screen(display);
  screen->text->config = config;

  delay(250); // wait for the OLED to power up
}


void loop() {
  screen->clear();
  screen->fullBoxedInfoScreen("Heading", "Hello World 2", 10, 10, SH110X_WHITE);
  delay(2000);
}


