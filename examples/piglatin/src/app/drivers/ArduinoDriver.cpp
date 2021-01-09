#include "ArduinoDriver.h"
#include "Arduino.h"

ArduinoDriver::ArduinoDriver()
    : _buttons{}
{
}

void ArduinoDriver::setupButton(uint8_t buttonPin, uint8_t buttonId, ButtonLogic logic)
{
    _buttons.push_back({buttonPin, buttonId, logic, false});
}

KeyboardDriver ArduinoDriver::getSerialKeyboardDriver()
{
    return [](KeyboardEventHandler handler) {
        KeyboardEventData e;
        while (Serial.available())
        {
            e.key = Serial.read();
            e.state = PRESSED;
            handler(e);
        }
    };
}

ButtonDriver ArduinoDriver::getButtonDriver()
{
    return [this](ButtonEventHandler handler) {
        ButtonEventData e;
        for (auto b : _buttons)
        {
            if (!b.pressed && digitalRead(b.buttonPin) == b.logic)
            {
                e.buttonId = b.buttonId;
                e.state = PRESSED;
                b.pressed = true;
                handler(e);
            }
            else if (b.pressed && digitalRead(b.buttonPin) != b.logic)
            {
                e.buttonId = b.buttonId;
                e.state = RELEASED;
                b.pressed = false;
                handler(e);
            }
        }
    };
}