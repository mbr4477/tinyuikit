#include "Color.h"
using namespace ui;

Color::Color(uint8_t red, uint8_t green, uint8_t blue)
    : _red{red}, _green{green}, _blue{blue}, _transparent{false}
{
}

Color::Color()
    : _red{0}, _green{0}, _blue{0}, _transparent{false}
{
}

Color::Color(const Color &other)
    : _red{other._red},
      _blue{other._blue},
      _green{other._green},
      _transparent{other._transparent}
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
