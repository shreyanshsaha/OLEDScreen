#include "OLED.h"

OLED::OLED(Adafruit_SH1106G *display): OLED(display, display->width(), display->height()){}

OLED::OLED(Adafruit_SH1106G *display, uint16_t w, uint16_t h){
	this->w = w;
	this->h=h;
	this->display = display;
	this->display->begin(i2c_Address, true); // Address 0x3C default
}

void OLED::show(){
	this->display->display();
}

void OLED::clear(){
  this->display->clearDisplay();
}