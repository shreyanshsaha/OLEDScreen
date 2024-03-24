#ifndef OLEDTEXT_H
#define OLEDTEXT_H

#include "OLED.h"

class OLEDText: public OLED
{
private:
    /* data */
public:
    struct TextConfig
    {
        uint8_t textSize;
        uint16_t textColor;
        uint16_t bgColor;
    } config;
    OLEDText(Adafruit_SH1106G*);
    OLEDText(Adafruit_SH1106G*, uint16_t, uint16_t);
    OLEDText(Adafruit_SH1106G*, uint16_t, uint16_t, TextConfig);
    OLEDText(Adafruit_SH1106G*, TextConfig);

    void printText(String, int16_t, int16_t);
    void printText(String, int16_t, int16_t, TextConfig);
    void printText(String);
};

#endif