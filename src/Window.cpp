#include "Window.h"
#include "InputDevice.h"

using namespace ui;

Window &Window::main()
{
    static Window window;
    return window;
}

Window::Window()
    : _canvas{NULL},
      _activity{NULL}
{
}

void Window::setCanvas(Canvas &canvas)
{
    _canvas = &canvas;
}

void Window::requestFocus()
{
    if (_activity)
    {
        FocusManager::shared().setRoot(_activity->getRoot());
    }
}

void Window::setActivity(Activity &activity)
{

    _activity = &activity;
    requestFocus();
}

Activity &Window::getActivity()
{
    return *_activity;
}

void Window::draw()
{
    if (_activity && _canvas)
    {
        _activity->getRoot().draw(*_canvas);
    }
}

void Window::update()
{
    InputDevice::shared().poll(*this);
    draw();
}

void Window::sendEvent(Event event)
{
    if (_activity)
    {
        _activity->getRoot().handleEvent(event);
    }
}

void Window::sendEventToFocused(Event event)
{
    FocusManager::shared().getFocused().handleEvent(event);
}
