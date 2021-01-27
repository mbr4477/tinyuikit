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
      _valign{TOP},
      _lineHeight{20}
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

void Label::setLineHeight(uint16_t height)
{
    _lineHeight = height;
    markDirty();
}

uint16_t Label::getLineHeight() const
{
    return _lineHeight;
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

void Label::drawWordWrappedText(Canvas &canvas,
                                std::string text,
                                Box bounds,
                                Alignment halign,
                                VAlignment valign,
                                Color color)
{
    uint8_t lineNumber;
    std::vector<uint16_t> lineSplits{};
    int lastSplit, nextSplit, possibleNextSplit;
    uint16_t possibleLineWidth;

    lineNumber = 0;
    lastSplit = 0;
    do
    {
        possibleNextSplit = lastSplit;
        do
        {
            nextSplit = possibleNextSplit;                     // save the split before checking the next possible split
            possibleNextSplit = text.find(' ', nextSplit + 1); // find the next possible word wrap split
            if (possibleNextSplit == std::string::npos)
            {
                possibleNextSplit = text.length(); // set split to end of line if no more breaks detected
            }
            possibleLineWidth = canvas.getTextBounds(
                                          text.substr(lastSplit, possibleNextSplit - lastSplit))
                                    .getWidth(); // find out how wide this line would be

        } while (possibleLineWidth < bounds.getWidth() && nextSplit < text.length());

        lineSplits.push_back(nextSplit + 1); // add one to skip space
        lastSplit = nextSplit;
        lineNumber++;
    } while (lineNumber * _lineHeight < bounds.getHeight() && nextSplit < text.length());

    uint16_t totalHeight = lineNumber * _lineHeight;
    if (lineNumber == 1)
    {
        totalHeight = canvas.getTextBounds(text).getHeight();
    }

    int16_t yOffset = 0;
    switch (valign)
    {
    case TOP:
        break;
    case MIDDLE:
        yOffset = (bounds.getHeight() - totalHeight) / 2;
        break;
    case BOTTOM:
        yOffset = bounds.getHeight() - totalHeight;
        break;
    }

    lastSplit = 0;
    for (std::size_t i = 0; i != lineSplits.size(); i++)
    {
        drawSingleLineText(canvas,
                           text.substr(lastSplit, lineSplits[i] - lastSplit),
                           {bounds.getX(),
                            bounds.getY() + yOffset + i * _lineHeight,
                            bounds.getWidth(),
                            _lineHeight},
                           getAlignment(),
                           color);
        lastSplit = lineSplits[i];
    }
}

void Label::drawSingleLineText(
    Canvas &canvas,
    std::string text,
    Box bounds,
    Alignment halign,
    Color color)
{
    Box textBounds = canvas.getTextBounds(text);
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
    xOffset -= textBounds.getX();
    yOffset -= textBounds.getY();
    canvas.addText(
        text,
        bounds.getX() + xOffset,
        bounds.getY() + yOffset,
        color);
}

void Label::draw(Canvas &canvas)
{
    if (isDirty())
    {
        drawBackground(canvas);
        drawWordWrappedText(
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