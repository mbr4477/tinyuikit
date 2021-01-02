#include "TextRouter.h"

using namespace ui;

TextRouter::TextRouter()
    : _textFields{}
{
}

void TextRouter::add(TextField &textField)
{
    _textFields.push_back(&textField);
}

void TextRouter::write(char c)
{
    for (auto tf : _textFields)
    {
        if (tf->hasFocus())
        {
            tf->write(c);
        }
    }
}