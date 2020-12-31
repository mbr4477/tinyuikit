#include "Label.h"
using namespace ui;

LabelStyle::LabelStyle(
    Color textColor,
    Alignment halign,
    VAlignment valign,
    Color bgColor,
    Color borderColor)
    : ViewStyle(bgColor, borderColor)
{
    _halign = halign;
    _valign = valign;
    _textColor = textColor;
}

void LabelStyle::setAlignment(Alignment align)
{
    _halign = align;
}

Alignment LabelStyle::getAlignment()
{
    return _halign;
}

void LabelStyle::setVAlignment(VAlignment align)
{
    _valign = align;
}

VAlignment LabelStyle::getVAlignment()
{
    return _valign;
}

void LabelStyle::setTextColor(Color color)
{
    _textColor = color;
}

Color LabelStyle::getTextColor()
{
    return _textColor;
}

Label::Label(
    std::string text,
    Box bounds,
    LabelStyle *style)
    : View(bounds, style), _text(text)
{
}

void Label::setText(std::string text)
{
    _text = text;
    markDirty();
}

std::string Label::getText()
{
    return _text;
}

LabelStyle *Label::getStyle()
{
    return static_cast<LabelStyle *>(View::getStyle());
}

void Label::setStyle(LabelStyle *style, State state)
{
    setStyle(style, state);
    markDirty();
}

void Label::drawSelf(Canvas &canvas)
{
    drawBackground(canvas);
    Box textBounds = canvas.getTextBounds(_text);
    unsigned int yOffset = 0;
    unsigned int xOffset = 0;
    switch (getStyle()->getAlignment())
    {
    case LEFT:
        break;
    case CENTER:
        xOffset = (getBounds().getWidth() - textBounds.getWidth()) / 2;
        break;
    case RIGHT:
        xOffset = getBounds().getWidth() - textBounds.getWidth();
        break;
    }
    switch (getStyle()->getVAlignment())
    {
    case TOP:
        break;
    case MIDDLE:
        yOffset = (getBounds().getHeight() - textBounds.getHeight()) / 2;
        break;
    case BOTTOM:
        yOffset = getBounds().getHeight() - textBounds.getHeight();
        break;
    }
    canvas.addText(
        _text,
        getBounds().getX() + xOffset,
        getBounds().getY() + yOffset,
        getStyle()->getTextColor());
}

void Label::draw(Canvas &canvas)
{
    if (isDirty())
    {
        drawSelf(canvas);
        clearDirty();
    }
    // no children to draw
}