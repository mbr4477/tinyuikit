#include "KeyRouter.h"

using namespace ui;

KeyRouter::KeyRouter()
    : _textFields{}
{
}

void KeyRouter::add(TextField &textField)
{
    _textFields.push_back(&textField);
}

void KeyRouter::clear()
{
    _textFields.clear();
}

void KeyRouter::write(char c)
{
    for (auto tf : _textFields)
    {
        if (tf->hasFocus())
        {
            tf->write(c);
        }
    }
}