#ifndef SCREEN_H
#define SCREEN_H

#include "OLEDShape.h"
#include "OLEDText.h"

class Screen
{
private:
    /* data */
public:
    OLEDText *text;
    OLEDShape *shape;
    Adafruit_SH1106G* display;

    Screen(Adafruit_SH1106G*);

    void boxedScreenText(String string, int16_t text_x, int16_t text_y, int64_t rect_x, int16_t rect_y, int16_t rect_w, int16_t rect_h, uint16_t color);
    void fullBoxedScreenText(String string, int16_t text_x, int16_t text_y, uint16_t color);
    void fullBoxedInfoScreen(String heading, String text, int16_t text_x, int16_t text_y, uint16_t color);
    void fullBoxedInfoScreen(String heading, String texts[], size_t  n, int16_t text_x, int16_t text_y, uint16_t color);
    void screenText(String string, int16_t text_x, int16_t text_y);
    void infoScreenText(String heading, String text, int16_t text_x, int16_t text_y, OLEDText::TextConfig headingConfig);
    void infoScreenText(String heading, String texts[], size_t  n, int16_t text_x, int16_t text_y, OLEDText::TextConfig headingConfig);
    void clear();

    ~Screen();
};

#endif