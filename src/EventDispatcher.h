#ifndef _UI_EVENTDISPATCHER_H_
#define _UI_EVENTDISPATCHER_H_
#include <stdint.h>
#include "Event.h"
#include "Window.h"

namespace ui
{
    class EventDispatcher
    {
    public:
        EventDispatcher(Window &target);
        void sendEvent(Event event);
        void sendEventToFocused(Event event);

    private:
        Window &_targetWindow;
    };
} // namespace ui

#endif