#include "InputDevice.h"
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

void InputDevice::setButtonDriver(ButtonDriver driver)
{
    _pollButtons = driver;
}

void InputDevice::setKeyboardDriver(KeyboardDriver driver)
{
    _pollKeyboard = driver;
}

void InputDevice::setPointerDriver(PointerDriver driver)
{
    _pollPointer = driver;
}

void InputDevice::handleButtonEvent(ButtonEventData data, Window &target)
{
    Event e;
    e.type = BUTTON;
    e.data.button = data;
    switch (data.buttonId)
    {
    case UI_BUTTON_ENTER_ID:
        target.sendEventToFocused(e);
        break;
    case UI_BUTTON_NEXT_ID:
        FocusManager::shared().next();
        break;
    case UI_BUTTON_PREV_ID:
        FocusManager::shared().prev();
        break;
    default:
        target.sendEvent(e);
        break;
    }
}

void InputDevice::handleKeyboardEvent(KeyboardEventData data, Window &target)
{
    Event e;
    e.type = KEYBOARD;
    e.data.keyboard = data;
    target.sendEvent(e);
}

void InputDevice::handlePointerEvent(PointerEventData data, Window &target)
{
    Event e;
    e.type = POINTER;
    e.data.pointer = data;
    target.sendEvent(e);
}

void InputDevice::poll(Window &target)
{
    ButtonEventData buttons;
    KeyboardEventData keyboard;
    PointerEventData pointer;

    if (_pollButtons)
    {
        _pollButtons([this, &target](ButtonEventData data) {
            handleButtonEvent(data, target);
        });
    }

    if (_pollKeyboard)
    {
        _pollKeyboard([this, &target](KeyboardEventData data) {
            handleKeyboardEvent(data, target);
        });
    }

    if (_pollPointer)
    {
        _pollPointer([this, &target](PointerEventData data) {
            handlePointerEvent(data, target);
        });
    }
}