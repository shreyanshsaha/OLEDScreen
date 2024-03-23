#ifndef SCREEN_H
#define SCREEN_H

#include "OLEDShape.h"
#include "OLEDText.h"
#include <vector>
#include<string>

class Screen
{
private:
    /* data */
public:
    OLEDText *text;
    OLEDShape *shape;
    Adafruit_SH1106G* display;

    Screen(Adafruit_SH1106G*);

    void boxedScreenText(std::string string, int16_t text_x, int16_t text_y, int64_t rect_x, int16_t rect_y, int16_t rect_w, int16_t rect_h, uint16_t color);
    void fullBoxedScreenText(std::string string, int16_t text_x, int16_t text_y, uint16_t color);
    void fullBoxedInfoScreen(std::string heading, std::string text, int16_t text_x, int16_t text_y, uint16_t color);
    void fullBoxedInfoScreen(std::string heading, std::vector<std::string> texts, int16_t text_x, int16_t text_y, uint16_t color);
    void screenText(std::string string, int16_t text_x, int16_t text_y);
    void infoScreenText(std::string heading, std::string text, int16_t text_x, int16_t text_y, OLEDText::TextConfig headingConfig);
    void infoScreenText(std::string heading, std::vector<std::string> text, int16_t text_x, int16_t text_y, OLEDText::TextConfig headingConfig);
    void clear();

    ~Screen();
};

#endif