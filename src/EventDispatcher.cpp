#include "EventDispatcher.h"
#include "FocusManager.h"
#include "Window.h"

using namespace ui;

EventDispatcher &EventDispatcher::main()
{
    static EventDispatcher driver(Window::main());
    return driver;
}

EventDispatcher::EventDispatcher(Window &window)
    : _window{window}
{
}

void EventDispatcher::sendEvent(Event event)
{
    _window.getActivity().getRoot().handleEvent(event);
}

void EventDispatcher::sendEventToFocused(Event event)
{
    FocusManager::shared().getFocused().handleEvent(event);
}