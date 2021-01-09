#ifndef _UI_INPUTDEVICE_H_
#define _UI_INPUTDEVICE_H_
#include <functional>
#include "Event.h"

#define UI_BUTTON_ENTER_ID 0
#define UI_BUTTON_NEXT_ID 1
#define UI_BUTTON_PREV_ID 2

namespace ui
{
    typedef std::function<void(ButtonEventData)> ButtonEventHandler;
    typedef std::function<void(ButtonEventHandler)> ButtonDriver;

    typedef std::function<void(KeyboardEventData)> KeyboardEventHandler;
    typedef std::function<void(KeyboardEventHandler)> KeyboardDriver;

    typedef std::function<void(PointerEventData)> PointerEventHandler;
    typedef std::function<void(PointerEventHandler)> PointerDriver;

    class InputDevice
    {
    public:
        /** Access the input device driver singleton */
        static InputDevice &shared();
        void setButtonDriver(ButtonDriver driver);
        void setKeyboardDriver(KeyboardDriver driver);
        void setPointerDriver(PointerDriver driver);

        /** Poll the device, sending events via the given dispatcher */
        void poll(EventDispatcher &dispatcher);

    private:
        InputDevice();
        ButtonDriver _pollButtons;
        KeyboardDriver _pollKeyboard;
        PointerDriver _pollPointer;

        void handleButtonEvent(ButtonEventData data, EventDispatcher dispatcher);
        void handleKeyboardEvent(KeyboardEventData data, EventDispatcher dispatcher);
        void handlePointerEvent(PointerEventData data, EventDispatcher dispatcher);
    };
} // namespace ui

#endif