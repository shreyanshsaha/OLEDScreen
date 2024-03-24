#include "OLED.h"
#include "OLEDShape.h"

OLEDShape::OLEDShape(Adafruit_SH1106G * display): OLED(display){}

OLEDShape::OLEDShape(Adafruit_SH1106G * display, uint16_t w, uint16_t h): OLED(display, w, h){}

void OLEDShape::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    display->drawRect(x,y,w,h,color);
}
