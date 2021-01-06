#include "FocusManager.h"

using namespace ui;

FocusManager *FocusManager::shared()
{
    static FocusManager manager;
    return &manager;
}

FocusManager::FocusManager()
    : _focusIndex{0},
      _root{NULL},
      _focused{NULL}
{
}

void FocusManager::setRoot(View *root)
{
    _root = root;
}

void FocusManager::setFocused(View *focused)
{
    if (_focused != NULL)
    {
        _focused->setFocus(false);
    }
    if (focused != NULL)
    {
        _focusIndex = focused->getFocusIndex();
    }
    _focused = focused;
}

View *FocusManager::getFocused()
{
    return _focused;
}

void FocusManager::next()
{
    // TODO
}

void FocusManager::prev()
{
    // TODO
}

void FocusManager::reset()
{
    // TODO
}

View *FocusManager::findByIndex(uint8_t focusIndex)
{
    return NULL;
}
