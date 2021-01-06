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
    if (_pollButtons && _pollButtons(buttons))
    {
        switch (buttons.buttonId)
        {
        case UI_BUTTON_ENTER_ID:
            EventDispatcher::main().sendEventToFocused({BUTTON,
                                                        buttons.state,
                                                        buttons.buttonId});
            break;
        case UI_BUTTON_NEXT_ID:
            FocusManager::shared().next();
            break;
        case UI_BUTTON_PREV_ID:
            FocusManager::shared().prev();
            break;
        default:
            EventDispatcher::main().sendEvent({BUTTON,
                                               buttons.state,
                                               buttons.buttonId});
            break;
        }
    }

    if (_pollKeyboard && _pollKeyboard(keyboard))
    {
        EventDispatcher::main().sendEvent({KEYBOARD,
                                           keyboard.state,
                                           keyboard.key});
    }
    
    if (_pollPointer && _pollPointer(pointer))
    {
        EventDispatcher::main().sendEvent({POINTER,
                                           pointer.state,
                                           pointer.x,
                                           pointer.y});
    }
}