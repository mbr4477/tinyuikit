#include "Style.h"
using namespace ui;

Color::Color(uint8_t red, uint8_t green, uint8_t blue)
    : _red(red), _green(green), _blue(blue), _transparent(false)
{
}

Color::Color()
    : _red(0), _green(0), _blue(0), _transparent(true)
{
}

uint8_t Color::getRed() const
{
    return _red;
}

uint8_t Color::getGreen() const
{
    return _green;
}

uint8_t Color::getBlue() const
{
    return _blue;
}

uint32_t Color::getRGB() const
{
    return (_red << 16) | (_green << 8) | _blue;
}

bool Color::isTransparent() const
{
    return _transparent;
}

Style::Style(const Color bgColor, const Color borderColor)
    : _bgColor(bgColor), _borderColor(borderColor)
{
}

void Style::setBgColor(const Color bgColor)
{
    _bgColor = bgColor;
}

Color Style::getBgColor() const
{
    return _bgColor;
}

void Style::setBorderColor(const Color borderColor)
{
    _borderColor = borderColor;
}

Color Style::getBorderColor() const
{
    return _borderColor;
}
