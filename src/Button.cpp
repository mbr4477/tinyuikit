#include "Button.h"
using namespace ui;

Button::Button(std::string text, Box bounds)
    : Label{text, bounds}
{
    setTextColor(BLACK);
    setBgColor({0, 128, 255});
    setAlignment(CENTER);
    setVAlignment(MIDDLE);
}