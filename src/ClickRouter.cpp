#include "ClickRouter.h"

using namespace ui;

ClickRouter::ClickRouter()
    : _buttons{},
      _pressed{false}
{
}

void ClickRouter::add(Button &button)
{
    _buttons.push_back(&button);
}

void ClickRouter::clear()
{
    _buttons.clear();
}

bool ClickRouter::isPressed()
{
    return _pressed;
}

void ClickRouter::press()
{
    if (!_pressed)
    {
        for (auto b : _buttons)
        {
            if (b->hasFocus())
            {
                b->press();
                _pressed = true;
                return;
            }
        }
    }
}

void ClickRouter::release()
{
    if (_pressed)
    {
        for (auto b : _buttons)
        {
            if (b->hasFocus())
            {
                b->release();
                _pressed = false;
                return;
            }
        }
    }
}
