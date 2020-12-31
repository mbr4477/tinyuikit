#include "GFXCanvas.h"
#include "Adafruit_GFX.h"
#include "ui.h"

using namespace ui;

uint16_t color565(Color color)
{
    uint8_t red = color.getRed();
    uint8_t green = color.getGreen();
    uint8_t blue = color.getBlue();
    red = (0x1F * red / 255) & 0x1F;
    green = (0x3F * green / 255) & 0x3F;
    blue = (0x1F * blue / 255) & 0x1F;
    return (blue << 11) | (green << 5) | red;
}

GFXCanvas::GFXCanvas(Adafruit_GFX &gfx)
    : Canvas(Box(0, 0, gfx.width(), gfx.height())), _gfx(&gfx)
{
}

void GFXCanvas::clearRect(Box rect)
{
    fillRect(rect, BLACK);
}

void GFXCanvas::fillRect(Box rect, Color fill)
{
    auto offset = rect.offsetBy(getInset());
    _gfx->fillRect(
        offset.getX(),
        offset.getY(),
        offset.getWidth(),
        offset.getHeight(),
        color565(fill));
}

void GFXCanvas::strokeRect(Box rect, Color border)
{
    auto offset = rect.offsetBy(getInset());
    _gfx->drawRect(
        offset.getX(),
        offset.getY(),
        offset.getWidth(),
        offset.getHeight(),
        color565(border));
}

Box GFXCanvas::getTextBounds(std::string text)
{
    int16_t x, y;
    uint16_t width, height;
    _gfx->getTextBounds(text.c_str(), 0, 0, &x, &y, &width, &height);
    return Box(x, y, width, height);
}

void GFXCanvas::addText(std::string text, unsigned int x, unsigned int y, Color color)
{
    Serial.println("Add text");
    _gfx->setCursor(x, y);
    _gfx->setTextColor(color565(color));
    _gfx->print(text.c_str());
}