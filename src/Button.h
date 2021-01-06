#ifndef _UI_BUTTON_H_
#define _UI_BUTTON_H_
#include <functional>
#include "Label.h"
#include "InputDevice.h"

namespace ui
{
    class Button : public Label
    {
    public:
        Button(std::string text, Box bounds);

        virtual bool handleEvent(Event &event);

        void setClickListener(std::function<void(void)> listener, uint8_t buttonIdFilter = UI_BUTTON_ENTER_ID);

    private:
        std::function<void(void)> _clickListener;
        ViewState _prevState;
        uint8_t _buttonIdFilter;
        bool _pressed;
    };
} // namespace ui

#endif