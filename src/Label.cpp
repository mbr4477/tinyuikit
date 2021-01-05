#include "Label.h"
using namespace ui;

Label::Label(
    std::string text,
    Box bounds,
    bool focusable)
    : View{bounds, focusable},
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

void Label::drawTextInBounds(
    Canvas *canvas,
    std::string text,
    Box bounds,
    Alignment halign,
    VAlignment valign,
    Color color)
{
    Box textBounds = canvas->getTextBounds(text);
    unsigned int yOffset = 0;
    unsigned int xOffset = 0;
    switch (halign)
    {
    case LEFT:
        break;
    case CENTER:
        xOffset = (bounds.getWidth() - textBounds.getWidth()) / 2;
        break;
    case RIGHT:
        xOffset = bounds.getWidth() - textBounds.getWidth();
        break;
    }
    switch (valign)
    {
    case TOP:
        break;
    case MIDDLE:
        yOffset = (bounds.getHeight() - textBounds.getHeight()) / 2;
        break;
    case BOTTOM:
        yOffset = bounds.getHeight() - textBounds.getHeight();
        break;
    }
    canvas->addText(
        text,
        bounds.getX() + xOffset,
        bounds.getY() + yOffset,
        color);
}

void Label::draw(Canvas *canvas)
{
    if (isDirty())
    {
        drawBackground(canvas);
        drawTextInBounds(
            canvas,
            _text,
            getBounds(),
            getAlignment(),
            getVAlignment(),
            getTextColor());

        clearDirty();
    }
    // no children to draw
}