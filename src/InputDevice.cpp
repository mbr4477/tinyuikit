#include "InputDevice.h"
#include "EventDispatcher.h"

using namespace ui;

InputDevice::InputDevice()
    : _pollButtons{},
      _pollKeyboard{},
      _pollPointer{}
{
}

InputDevice &InputDevice::shared()
{
    static InputDevice inputDevice;
    return inputDevice;
}

void InputDevice::setButtonDriver(std::function<bool(ButtonEventData &)> driver)
{
    _pollButtons = driver;
}

void InputDevice::setKeyboardDriver(std::function<bool(KeyboardEventData &)> driver)
{
    _pollKeyboard = driver;
}

void InputDevice::setPointerDriver(std::function<bool(PointerEventData &)> driver)
{
    _pollPointer = driver;
}

void InputDevice::poll()
{
    ButtonEventData buttons;
    KeyboardEventData keyboard;
    PointerEventData pointer;
    Event e;

    if (_pollButtons && _pollButtons(buttons))
    {
        e.type = BUTTON;
        e.data.button = buttons;
        switch (buttons.buttonId)
        {
        case UI_BUTTON_ENTER_ID:
            EventDispatcher::main().sendEventToFocused(e);
            break;
        case UI_BUTTON_NEXT_ID:
            FocusManager::shared().next();
            break;
        case UI_BUTTON_PREV_ID:
            FocusManager::shared().prev();
            break;
        default:
            EventDispatcher::main().sendEvent(e);
            break;
        }
    }

    if (_pollKeyboard && _pollKeyboard(keyboard))
    {
        e.type = KEYBOARD;
        e.data.keyboard = keyboard;
        EventDispatcher::main().sendEvent(e);
    }

    if (_pollPointer && _pollPointer(pointer))
    {
        e.type = POINTER;
        e.data.pointer = pointer;
        EventDispatcher::main().sendEvent(e);
    }
}