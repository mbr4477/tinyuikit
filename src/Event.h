#ifndef _UI_EVENT_H_
#define _UI_EVENT_H_
#include <stdint.h>

namespace ui
{
    enum EventType
    {
        POINTER = 0,
        KEYBOARD,
        BUTTON
    };

    enum InputState
    {
        PRESSED = 0,
        RELEASED
    };

    struct PointerEventData
    {
        InputState state;
        uint16_t x;
        uint16_t y;
    };

    struct KeyboardEventData
    {
        InputState state;
        char key;
    };

    struct ButtonEventData
    {
        InputState state;
        uint8_t buttonId;
    };

    union EventData
    {
        PointerEventData pointer;
        ButtonEventData button;
        KeyboardEventData keyboard;
    };

    struct Event
    {
        EventType type;
        EventData data;
    };

} // namespace ui

#endif