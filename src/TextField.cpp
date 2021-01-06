#include "TextField.h"
#define _UI_TEXTFIELD_BKSP 8
#define _UI_TEXTFIELD_DEL 127

using namespace ui;

TextField::TextField(std::string placeholder, const Box bounds)
    : Label{"", bounds, true},
      _placeholder{placeholder}
{
    setVAlignment(MIDDLE);
    setStateListener([this](ViewState state) {
        switch (state)
        {
        case NORMAL:
            setBgColor({0, 0, 0});
            setBorderColor({128, 128, 128});
            break;
        case FOCUSED:
            setBgColor({0, 0, 0});
            setBorderColor({255, 255, 255});
            break;
        case ACTIVE:
            break;
        }
    });
}

void TextField::setPlaceholder(std::string placeholder)
{
    _placeholder = placeholder;
    markDirty();
}

void TextField::draw(Canvas &canvas)
{
    Box bounds = getBounds();
    if (isDirty())
    {
        canvas.fillRect(bounds, getBgColor());
        canvas.strokeLine(
            bounds.getX(),
            bounds.getY() + bounds.getHeight(),
            bounds.getX() + bounds.getWidth(),
            bounds.getY() + bounds.getHeight(),
            getBorderColor());
        if (getText().length() > 0)
        {
            drawTextInBounds(
                canvas,
                getText(),
                getBounds(),
                getAlignment(),
                getVAlignment(),
                getTextColor());
        }
        else
        {
            drawTextInBounds(
                canvas,
                _placeholder,
                getBounds(),
                getAlignment(),
                getVAlignment(),
                {128, 128, 128});
        }
        clearDirty();
    }
}

bool TextField::handleEvent(Event &event)
{
    if (event.type != KEYBOARD)
        return false;

    if (event.type == KEYBOARD && hasFocus() && event.data.keyboard.state == PRESSED)
    {
        char c = event.data.keyboard.key;
        std::string text = getText();
        if (c >= ' ' && c < '~')
        {
            // printable character
            setText(text + c);
        }
        else if (c == _UI_TEXTFIELD_BKSP || c == _UI_TEXTFIELD_DEL)
        {
            // backspace
            if (text.length() > 0)
            {
                setText(text.substr(0, text.length() - 1));
            }
        }
        return true;
    }
    return false;
}