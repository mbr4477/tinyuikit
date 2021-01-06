#include "Window.h"

using namespace ui;

Window *Window::main()
{
    static Window window;
    return &window;
}

Window::Window()
    : _canvas{NULL},
      _activity{NULL}
{
}

void Window::setCanvas(Canvas *canvas)
{
    _canvas = canvas;
}

void Window::setActivity(Activity *activity)
{
    if (activity != NULL)
    {
        _activity = activity;
        FocusManager::shared()->setRoot(_activity->getRoot());
    }
}

Activity *Window::getActivity()
{
    return _activity;
}

void Window::draw()
{
    if (_activity != NULL && _canvas != NULL)
    {
        _activity->getRoot()->draw(_canvas);
    }
}
