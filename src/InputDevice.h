#ifndef _UI_INPUTDEVICE_H_
#define _UI_INPUTDEVICE_H_
#include <functional>
#include "Event.h"

#define UI_BUTTON_ENTER_ID 0
#define UI_BUTTON_NEXT_ID 1
#define UI_BUTTON_PREV_ID 2

namespace ui
{
    class InputDevice
    {
    public:
        static InputDevice &shared();
        InputDevice();
        void setButtonDriver(std::function<bool(ButtonEventData &)> driver);
        void setKeyboardDriver(std::function<bool(KeyboardEventData &)> driver);
        void setPointerDriver(std::function<bool(PointerEventData &)> driver);

        void poll();

    private:
        std::function<bool(ButtonEventData &)> _pollButtons;
        std::function<bool(KeyboardEventData &)> _pollKeyboard;
        std::function<bool(PointerEventData &)> _pollPointer;
    };
} // namespace ui

#endif