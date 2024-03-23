#include "OLEDText.h"


OLEDText::OLEDText(Adafruit_SH1106G* display, uint16_t w, uint16_t h): OLED(display, w, h){}

OLEDText::OLEDText(Adafruit_SH1106G* display): OLED(display){}

OLEDText::OLEDText(Adafruit_SH1106G* display, uint16_t w, uint16_t h, TextConfig config): OLEDText(display, w, h){
	this->config = config;
}

OLEDText::OLEDText(Adafruit_SH1106G* display, TextConfig config): OLEDText(display){
	this->config = config;
}

void OLEDText::printText(std::string text, int16_t x, int16_t y){
	printText(text, x, y, this->config);
}

void OLEDText::printText(std::string text, int16_t x, int16_t y, TextConfig config){
	display->setTextSize(config.textSize);
	display->setTextColor(config.textColor);
	display->setCursor(x, y);
	display->setTextColor(config.textColor, config.bgColor);
	display->println(text.c_str());
}

void OLEDText::printText(std::string text){
	display->setTextSize(config.textSize);
	display->setTextColor(config.textColor);
	display->setTextColor(config.textColor, config.bgColor);
	display->println(text.c_str());
}
