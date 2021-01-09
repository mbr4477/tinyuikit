#include "Button.h"

using namespace ui;

Button::Button(std::string text, Box bounds)
    : Label{text, bounds, true},
      _clickListener{[]() {}},
      _prevState{NORMAL},
      _pressed{false},
      _buttonIdFilter{UI_BUTTON_ENTER_ID}
{
    setTextColor(UI_BLACK);
    setBgColor(UI_CYAN);
    setAlignment(CENTER);
    setVAlignment(MIDDLE);
}

void Button::setClickListener(std::function<void(void)> listener, uint8_t buttonIdFilter)
{
    _buttonIdFilter = buttonIdFilter;
    _clickListener = listener;
}

bool Button::handleEvent(Event &event)
{
    if (event.type == BUTTON && event.data.button.buttonId == _buttonIdFilter)
    {
        switch (event.data.button.state)
        {
        case InputState::PRESSED:
            if (!_pressed)
            {
                _prevState = getState();
                setState(ViewState::ACTIVE);
                _pressed = true;
            }
            break;
        case InputState::RELEASED:
        default:
            if (_pressed)
            {
                setState(_prevState);
                _pressed = false;
                _clickListener();
            }
            break;
        }
        return true;
    }
    return false;
}