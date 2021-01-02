#include "Button.h"
using namespace ui;

Button::Button(std::string text, Box bounds)
    : Label{text, bounds, true},
      _clickListener{[]() {}},
      _prevState{NORMAL},
      _pressed{false}
{
    setTextColor(BLACK);
    setBgColor({0, 128, 255});
    setAlignment(CENTER);
    setVAlignment(MIDDLE);
}

void Button::press(bool respectFocus)
{
    if (!respectFocus)
    {
        _prevState = (_prevState != ACTIVE) ? getState() : _prevState;
        _pressed = true;
        setState(ACTIVE);
    }
    else if (hasFocus())
    {
        _prevState = (_prevState != ACTIVE) ? getState() : _prevState;
        _pressed = true;
        setState(ACTIVE);
    }
}

void Button::release()
{
    if (_pressed)
    {
        _clickListener();
        setState(_prevState);
        _pressed = false;
    }
}

void Button::setClickListener(std::function<void(void)> listener)
{
    _clickListener = listener;
}