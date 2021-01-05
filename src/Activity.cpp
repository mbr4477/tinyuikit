#include "Activity.h"

using namespace ui;

Activity::Activity(Canvas &canvas)
    : _canvas{&canvas},
      _clickRouter{},
      _keyRouter{},
      _focusManager{},
      _root{NULL},
      _focusCounter{0}
{
}

void Activity::setRoot(View &root)
{
    _root = &root;
}

void Activity::registerButton(Button &button)
{
    _clickRouter.add(button);
    button.setFocusIndex(_focusCounter);
    _focusCounter++;
    _focusManager.add(button);
}

void Activity::registerTextField(TextField &textField)
{
    _keyRouter.add(textField);
    textField.setFocusIndex(_focusCounter);
    _focusCounter++;
    _focusManager.add(textField);
}

void Activity::draw()
{
    if (_root != NULL)
    {
        _root->draw(_canvas);
    }
}

void Activity::focusNext()
{
    _focusManager.next();
}

void Activity::focusPrev()
{
    _focusManager.prev();
}

void Activity::selectDown()
{
    _clickRouter.press();
}

void Activity::selectUp()
{
    _clickRouter.release();
}

void Activity::handleKey(char c)
{
    _keyRouter.write(c);
}