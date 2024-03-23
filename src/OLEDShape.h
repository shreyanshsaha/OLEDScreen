#ifndef OLEDSHAPE_H
#define OLEDSHAPE_H

#include "OLED.h"

class OLEDShape: public OLED
{
private:
    /* data */
public:
    OLEDShape(Adafruit_SH1106G*);
    OLEDShape(Adafruit_SH1106G*, uint16_t, uint16_t);

    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h,
                            uint16_t color);
    ~OLEDShape();
};

#endif