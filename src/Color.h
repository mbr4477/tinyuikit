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

#define UI_WHITE (Color(255, 255, 255))
#define UI_GRAY (Color(128, 128, 128))
#define UI_RED (Color(255, 0, 0))
#define UI_BLACK (Color(0, 0, 0))
#define UI_GREEN (Color(0, 255, 0))
#define UI_BLUE (Color(0, 0, 255))
#define UI_YELLOW (Color(255, 255, 0))
#define UI_CYAN (Color(0, 200, 255))
#define UI_MAGENTA (Color(255, 0, 255))
#define UI_TRANSPARENT (Color())

} // namespace ui

#endif