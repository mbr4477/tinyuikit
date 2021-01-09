#include "EventDispatcher.h"
#include "FocusManager.h"
#include "Window.h"

using namespace ui;

EventDispatcher::EventDispatcher(Window &target)
    : _targetWindow{target}
{
}

void EventDispatcher::sendEvent(Event event)
{
    _targetWindow.getActivity().getRoot().handleEvent(event);
}

void EventDispatcher::sendEventToFocused(Event event)
{
    FocusManager::shared().getFocused().handleEvent(event);
}