#include "View.h"
#include <vector>

using namespace ui;

View::View(const Box bounds, Style *style)
    : _bounds(bounds), _state(State::NORMAL)
{
    setStyle(style, State::NORMAL);
    markDirty();
}

Box View::getBounds() const
{
    return _bounds;
}

void View::setBounds(Box bounds)
{
    _bounds = bounds;
}

Style *View::getStyle()
{
    return _styles[_state];
}

void View::setStyle(Style *style, State state)
{
    _styles[state] = style;
    markDirty();
}

View::State View::getState() const
{
    return _state;
}

void View::setState(State state)
{
    _state = state;
    markDirty();
}

bool View::isDirty()
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

std::vector<View *> View::getChildren() const
{
    return _children;
}

void View::addChild(View &child)
{
    _children.push_back(&child);
    markDirty();
}

void View::clearDirty()
{
    _dirty = false;
}

void View::drawBackground(Canvas &canvas)
{
    Style *style = getStyle();
    if (!style->getBgColor().isTransparent())
    {
        canvas.fillRect(_bounds, style->getBgColor());
    }

    if (!style->getBorderColor().isTransparent())
    {
        canvas.strokeRect(_bounds, style->getBorderColor());
    }
}

void View::drawSelf(Canvas &canvas)
{
    drawBackground(canvas);
}

void View::drawChildren(Canvas &canvas)
{
    Box canvasInset = canvas.getInset();
    for (auto v : _children)
    {
        canvas.setInset(_bounds.offsetBy(canvasInset));
        v->draw(canvas);
    }
}

void View::draw(Canvas &canvas)
{
    if (_dirty)
    {
        drawSelf(canvas);
        clearDirty();
    }
    drawChildren(canvas);
}