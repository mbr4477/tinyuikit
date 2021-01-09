#ifndef _DRIVERS_H_
#define _DRIVERS_H_
#include "ui.h"
#include "Arduino.h"
#include <vector>

using namespace ui;

class ArduinoDriver
{
public:
    enum ButtonLogic
    {
        NEGATIVE = LOW,
        POSITIVE = HIGH
    };
    ArduinoDriver();
    void setupButton(uint8_t buttonPin, uint8_t buttonId, ButtonLogic logic = POSITIVE);
    static KeyboardDriver getSerialKeyboardDriver();
    ButtonDriver getButtonDriver();

private:
    struct GPIOButton
    {
        uint8_t buttonPin;
        uint8_t buttonId;
        ButtonLogic logic;
        bool pressed;
    };

    std::vector<struct ArduinoDriver::GPIOButton> _buttons;
};

#endif