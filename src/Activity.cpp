#include "Activity.h"

using namespace ui;

Activity::Activity()
    : _root{NULL}
{
}

void Activity::setRoot(View &root)
{
    if (!_root)
    {
        _root = &root;
    }
}

View &Activity::getRoot()
{
    return *_root;
}