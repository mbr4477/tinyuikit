#include "View.h"
#include <vector>
#include "Color.h"

using namespace ui;

View::View(const Box bounds, bool focusable)
    : _bounds{bounds},
      _children{},
      _dirty{true},
      _bgColor{0, 0, 0},
      _borderColor{},
      _state{NORMAL},
      _focused{false},
      _focusIndex{0},
      _focusable{focusable},
      _stateListener{[](ViewState state) {}}
{
}

Box View::getBounds() const
{
    return _bounds;
}

void View::setBounds(Box bounds)
{
    _bounds = bounds;
    markDirty();
}

void View::setBgColor(Color color)
{
    _bgColor = color;
    markDirty();
}

Color View::getBgColor() const
{
    return _bgColor;
}

void View::setBorderColor(Color color)
{
    _borderColor = color;
    markDirty();
}

Color View::getBorderColor() const
{
    return _borderColor;
}

void View::setState(ViewState state)
{
    _state = state;
    _stateListener(_state);
    markDirty();
}

ViewState View::getState() const
{
    return _state;
}

void View::setStateListener(std::function<void(ViewState)> listener)
{
    _stateListener = listener;
    _stateListener(_state);
}

bool View::isDirty() const
{
    return _dirty;
}

void View::markDirty()
{
    _dirty = true;
    for (auto v : _children)
    {
        v->markDirty();
    }
}

void View::clearDirty()
{
    _dirty = false;
}

std::vector<View *> View::getChildren() const
{
    return _children;
}

void View::addChild(View &child)
{
    _children.push_back(&child);
    markDirty();
}

void View::drawBackground(Canvas *canvas)
{
    if (!getBgColor().isTransparent())
    {
        canvas->fillRect(_bounds, getBgColor());
    }

    if (!getBorderColor().isTransparent())
    {
        canvas->strokeRect(_bounds, getBorderColor());
    }
}

void View::drawChildren(Canvas *canvas)
{
    Box canvasInset = canvas->getInset();
    for (auto v : _children)
    {
        canvas->setInset(_bounds.offsetBy(canvasInset));
        v->draw(canvas);
    }
}

void View::draw(Canvas *canvas)
{
    if (_dirty)
    {
        drawBackground(canvas);
        clearDirty();
    }
    drawChildren(canvas);
}

void View::setFocus(bool focus)
{
    _focused = focus;
    if (_focused)
    {
        setState(ui::FOCUSED);
    }
    else
    {
        setState(ui::NORMAL);
    }
}

bool View::hasFocus() const
{
    return _focused;
}

void View::setFocusIndex(unsigned int focusIndex)
{
    _focusIndex = focusIndex;
}

unsigned int View::getFocusIndex() const
{
    return _focusIndex;
}

bool View::isFocusable() const
{
    return _focusable;
}