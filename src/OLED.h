#ifndef OLED_H
#define OLED_H

#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>


#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO


class OLED
{
private:
    /* data */
    
public:
    int w;
    int h;
    Adafruit_SH1106G* display;
    OLED(Adafruit_SH1106G*);
    OLED(Adafruit_SH1106G*, uint16_t, uint16_t);

    void show();
    void clear();
};

#endif