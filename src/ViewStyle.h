#ifndef _UI_STYLE_H_
#define _UI_STYLE_H_
#include <stdint.h>
#include "Color.h"

namespace ui
{
    class ViewStyle
    {
    public:
        ViewStyle(const Color bgColor, const Color borderColor);

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