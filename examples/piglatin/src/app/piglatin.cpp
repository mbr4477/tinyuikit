#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "ui.h"
#include "GFXCanvas.h"
#include "ui/MainActivity.h"
#include "drivers/ArduinoDriver.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define TFT_LITE A16
#define TFT_RST 7
#define TFT_DC 8
#define TFT_CS A15

#define BTN_PREV_PIN 4
#define BTN_ENTER_PIN A5
#define BTN_NEXT_PIN 6

using namespace ui;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
GFXCanvas canvas(tft);
MainActivity mainActivity(SCREEN_WIDTH, SCREEN_HEIGHT);
ArduinoDriver driver;

void setup()
{
    Serial.begin(115200);

    pinMode(TFT_LITE, OUTPUT);
    digitalWrite(TFT_LITE, HIGH);
    tft.begin();
    tft.setRotation(1);
    tft.setTextSize(2);

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