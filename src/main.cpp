#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include "Screen.h"

int NEXT_SCREEN_PIN = 34;
int PREV_SCREEN_PIN = 35;

int lastIdx=0;

Screen *screen;

Adafruit_SH1106G* display;

// function pointers
void (*screens[2])();
int screenIdx = 0;



void showScreen1(){
  String texts[4];
  texts[0] = "Price: 13245.34";
  texts[1] = "O:12300  C:24579";
  texts[2] = "Daily: -5.42%";
  texts[3] = "Weekly: -10.34%";

  screen->fullBoxedInfoScreen("NIFTY 50", texts, 4, 5, 5, SH110X_WHITE); 
}

void showScreen2(){
  String texts[4];
  texts[1] = "Price: 4262.34";
  texts[2] = "O:6356  C:2565";
  texts[3] = "Daily: -6.13%";
  texts[4] = "Weelkly: -1.65%";

  screen->fullBoxedInfoScreen("SnP 500", texts, 4, 5, 5, SH110X_WHITE); 
}

void setup()   {
  Serial.begin(9600);
  Serial.println("Started");
  display = new Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  OLEDText::TextConfig config;
  config.textSize = 1;
  config.textColor = SH110X_WHITE;
  config.bgColor = SH110X_BLACK;

  screen = new Screen(display);
  screen->text->config = config;

  delay(250); // wait for the OLED to power up
  screen->clear();
  screens[0] = showScreen1;
  screens[1] = showScreen2;



  screens[screenIdx]();
}


void loop() {
  // Serial.println("ScreenIdx");
  if(screenIdx!=lastIdx){
    screens[screenIdx]();
    lastIdx = screenIdx;
  }
  delay(1);
}




