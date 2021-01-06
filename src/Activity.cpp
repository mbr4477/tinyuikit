#include "Activity.h"

using namespace ui;

Activity::Activity(Canvas &canvas)
    : _root{NULL}
{
}

void Activity::setRoot(View &root)
{
    if (_root == NULL)
    {
        _root = &root;
    }
}

View *Activity::getRoot()
{
    return _root;
}