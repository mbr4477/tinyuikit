#include "Activity.h"

using namespace ui;

Activity::Activity(uint16_t width, uint16_t height)
    : _root{{0, 0, width, height}}
{
}

View &Activity::getRoot()
{
    return _root;
}