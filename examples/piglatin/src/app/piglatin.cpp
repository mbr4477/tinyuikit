#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "ui.h"
#include "GFXCanvas.h"
#include "ui/MainActivity.h"
#include "drivers/ArduinoDriver.h"

#define TFT_CS 7
#define TFT_DC 8
#define TFT_RST 9

#define BTN_PREV_PIN 10
#define BTN_ENTER_PIN 11
#define BTN_NEXT_PIN 12

using namespace ui;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
GFXCanvas canvas(tft);
MainActivity mainActivity;
ArduinoDriver driver;

void setup()
{
    driver.setupButton(BTN_PREV_PIN, UI_BUTTON_PREV_ID);
    driver.setupButton(BTN_ENTER_PIN, UI_BUTTON_ENTER_ID);
    driver.setupButton(BTN_NEXT_PIN, UI_BUTTON_NEXT_ID);
    InputDevice::shared().setButtonDriver(driver.getButtonDriver());
    InputDevice::shared().setKeyboardDriver(driver.getSerialKeyboardDriver());
    Window::main().setCanvas(canvas);
    Window::main().setActivity(mainActivity);
}

void loop()
{
    Window::main().update();
}