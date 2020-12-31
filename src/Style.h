#ifndef _UI_STYLE_H_
#define _UI_STYLE_H_
#include <stdint.h>

namespace ui
{
    class Color
    {
    public:
        Color(uint8_t red, uint8_t green, uint8_t blue);
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
    const Color BLACK(0, 0, 0);

    class Style
    {
    public:
        Style(const Color bgColor, const Color borderColor);

        void setBgColor(const Color bgColor);
        Color getBgColor() const;

        void setBorderColor(const Color borderColor);
        Color getBorderColor() const;

    private:
        Color _bgColor;
        Color _borderColor;
    };
} // namespace ui

#endif