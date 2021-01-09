#ifndef _STYLESHEET_H_
#define _STYLESHEET_H_
#include "ui.h"
using namespace ui;

typedef struct
{
    ViewState selector; // Select to apply class
    Color background;   // Background color
    Color border;       // Border color
    Color color;        // Text color
} Style;

class Stylesheet
{
public:
    Stylesheet();
    void add(Style style);

    void applyTo(View &view);
    void applyTo(Label &label);

private:
    std::vector<Style> _styles;
};

#endif