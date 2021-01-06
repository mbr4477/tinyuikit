#ifndef _UI_INPUTDEVICE_H_
#define _UI_INPUTDEVICE_H_
#include <stdint.h>
#include "Event.h"
#include "Window.h"

namespace ui
{
    class InputDriver
    {
    public:
        static InputDriver *main();
        InputDriver(Window *window);

        void sendEvent(Event event);
        void tabNext();
        void tabPrev();

    private:
        Window *_window;
    };
} // namespace ui

#endif