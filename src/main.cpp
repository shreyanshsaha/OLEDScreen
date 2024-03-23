#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <vector>
#include <string>

#include "Screen.h"

int NEXT_SCREEN_PIN = 34;
int PREV_SCREEN_PIN = 35;

int lastIdx=0;

Screen *screen;

Adafruit_SH1106G* display;

std::vector<void (*)()> screens;
int screenIdx = 0;

volatile unsigned long lastDebounceRead = 0;
const unsigned long DEBOUNCE_DELAY=500;

void showScreen1(){
  std::vector<std::string> texts;
  texts.emplace_back("Price: 13245.34");
  texts.emplace_back("O:12300  C:24579");
  texts.emplace_back("Daily: -5.42%");
  texts.emplace_back("Weelkly: -10.34%");
  screen->fullBoxedInfoScreen("NIFTY 50", texts, 5, 5, SH110X_WHITE); 
}

void showScreen2(){
  std::vector<std::string> texts;
  texts.emplace_back("Price: 4262.34");
  texts.emplace_back("O:6356  C:2565");
  texts.emplace_back("Daily: -6.13%");
  texts.emplace_back("Weelkly: -1.65%");
  screen->fullBoxedInfoScreen("SnP 500", texts, 5, 5, SH110X_WHITE); 
}
  
boolean canDebounceRead(){
  unsigned long curr = millis();
  if(curr > lastDebounceRead + DEBOUNCE_DELAY){
    lastDebounceRead = millis();
    return true;
  }
  return false;
}

void nextScreen(){
  if(!canDebounceRead()) return;
  Serial.println("Switching to next screen");
  screenIdx = (screenIdx + 1)%screens.size();
  screen->clear();
}

void prevScreen(){
  if(!canDebounceRead()) return;
  Serial.println("Switching to prev screen");
  if(screenIdx == 0){
    screenIdx = screens.size()-1;
  }
  else{
    screenIdx--;
  }
  screen->clear();
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
  screens.emplace_back(showScreen1);
  screens.emplace_back(showScreen2);

  attachInterrupt(digitalPinToInterrupt(NEXT_SCREEN_PIN), nextScreen, HIGH);
  attachInterrupt(digitalPinToInterrupt(PREV_SCREEN_PIN), prevScreen, HIGH);

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




