#include "ViewStyle.h"
using namespace ui;

ViewStyle::ViewStyle(const Color bgColor, const Color borderColor)
    : _bgColor(bgColor), _borderColor(borderColor)
{
}

void ViewStyle::setBgColor(const Color bgColor)
{
    _bgColor = bgColor;
}

Color ViewStyle::getBgColor() const
{
    return _bgColor;
}

void ViewStyle::setBorderColor(const Color borderColor)
{
    _borderColor = borderColor;
}

Color ViewStyle::getBorderColor() const
{
    return _borderColor;
}
