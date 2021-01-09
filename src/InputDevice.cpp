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

void InputDevice::handleButtonEvent(ButtonEventData data, EventDispatcher dispatcher)
{
    Event e;
    e.type = BUTTON;
    e.data.button = data;
    switch (data.buttonId)
    {
    case UI_BUTTON_ENTER_ID:
        dispatcher.sendEventToFocused(e);
        break;
    case UI_BUTTON_NEXT_ID:
        FocusManager::shared().next();
        break;
    case UI_BUTTON_PREV_ID:
        FocusManager::shared().prev();
        break;
    default:
        dispatcher.sendEvent(e);
        break;
    }
}

void InputDevice::handleKeyboardEvent(KeyboardEventData data, EventDispatcher dispatcher)
{
    Event e;
    e.type = KEYBOARD;
    e.data.keyboard = data;
    dispatcher.sendEvent(e);
}

void InputDevice::handlePointerEvent(PointerEventData data, EventDispatcher dispatcher)
{
    Event e;
    e.type = POINTER;
    e.data.pointer = data;
    dispatcher.sendEvent(e);
}

void InputDevice::poll(EventDispatcher &dispatcher)
{
    ButtonEventData buttons;
    KeyboardEventData keyboard;
    PointerEventData pointer;

    if (_pollButtons)
    {
        _pollButtons([this, dispatcher](ButtonEventData data) {
            handleButtonEvent(data, dispatcher);
        });
    }

    if (_pollKeyboard)
    {
        _pollKeyboard([this, dispatcher](KeyboardEventData data) {
            handleKeyboardEvent(data, dispatcher);
        });
    }

    if (_pollPointer)
    {
        _pollPointer([this, dispatcher](PointerEventData data) {
            handlePointerEvent(data, dispatcher);
        });
    }
}