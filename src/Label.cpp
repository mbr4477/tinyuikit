#include "Label.h"
using namespace ui;

Label::Label(
    std::string text,
    Box bounds)
    : View{bounds},
      _text{text},
      _textColor{255, 255, 255},
      _halign{LEFT},
      _valign{TOP}
{
}

void Label::setText(std::string text)
{
    _text = text;
    markDirty();
}

std::string Label::getText() const
{
    return _text;
}

void Label::setAlignment(Alignment align)
{
    _halign = align;
    markDirty();
}

Alignment Label::getAlignment() const
{
    return _halign;
}

void Label::setVAlignment(VAlignment align)
{
    _valign = align;
    markDirty();
}

VAlignment Label::getVAlignment() const
{
    return _valign;
}

void Label::setTextColor(Color color)
{
    _textColor = color;
    markDirty();
}

Color Label::getTextColor() const
{
    return _textColor;
}

void Label::drawSelf(Canvas &canvas)
{
    drawBackground(canvas);
    Box textBounds = canvas.getTextBounds(_text);
    unsigned int yOffset = 0;
    unsigned int xOffset = 0;
    switch (getAlignment())
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
    switch (getVAlignment())
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
        getTextColor());
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