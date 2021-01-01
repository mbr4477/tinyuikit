#ifndef _COLOR_H_
#define _COLOR_H_
#include <stdint.h>

namespace ui
{
    class Color
    {
    public:
        Color(uint8_t red, uint8_t green, uint8_t blue);
        Color(const Color &other);
        Color();
        uint32_t getRGB() const;
        uint8_t getRed() const;
        uint8_t getGreen() const;
        uint8_t getBlue() const;
        bool isTransparent() const;

    private:
        uint8_t _red;
        uint8_t _green;
        uint8_t _blue;
        bool _transparent;
    };
    const Color WHITE(255, 255, 255);
    const Color GRAY(128, 128, 128);
    const Color BLACK(0, 0, 0);
    const Color RED(255, 0, 0);
    const Color GREEN(0, 255, 0);
    const Color BLUE(0, 0, 255);
    const Color YELLOW(255, 255, 0);
    const Color CYAN(0, 200, 255);
    const Color MAGENTA(255, 0, 255);
    const Color TRANSPARENT;
} // namespace ui

#endif