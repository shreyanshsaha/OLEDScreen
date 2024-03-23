#include "Screen.h"

Screen::Screen(Adafruit_SH1106G *display)
{
    this->display = display;
    this->text = new OLEDText(display);
    this->shape = new OLEDShape(display);
}

void Screen::boxedScreenText(char* string, int16_t text_x, int16_t text_y, int64_t rect_x, int16_t rect_y, int16_t rect_w, int16_t rect_h, uint16_t color)
{
    this->shape->drawRect(rect_x, rect_y, rect_w, rect_h, color);
    this->shape->show();
    this->screenText(string, text_x, text_y);
}

void Screen::fullBoxedScreenText(char * string, int16_t text_x, int16_t text_y, uint16_t color)
{
    this->shape->drawRect(0, 0, this->shape->w, this->shape->h, color);
    this->shape->show();
    this->screenText(string, text_x, text_y);
}

void Screen::fullBoxedInfoScreen(char * heading, char * text, int16_t text_x, int16_t text_y, uint16_t color)
{
    OLEDText::TextConfig headingConfig = this->text->config;
    headingConfig.textSize++;

    this->shape->drawRect(0, 0, this->shape->w, this->shape->h, color);
    this->shape->show();
    this->infoScreenText(heading, text, text_x, text_y, headingConfig);
}

void Screen::screenText(char* string, int16_t text_x, int16_t text_y)
{
    this->text->printText(string, text_x, text_y);
    this->text->show();
    delay(1);
}

void Screen::infoScreenText(char * heading, char * text, int16_t text_x, int16_t text_y, OLEDText::TextConfig headingConfig)
{

    this->text->printText(heading, text_x, text_y, headingConfig);
    this->text->printText(text, text_x, text_y+20);
    this->text->show();
    delay(1);
}

void Screen::clear()
{
    this->text->clear();
    this->shape->clear();
}