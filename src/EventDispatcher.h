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
        static EventDispatcher &main();
        EventDispatcher(Window &window);

        void sendEvent(Event event);
        void sendEventToFocused(Event event);

    private:
        Window &_window;
    };
} // namespace ui

#endif