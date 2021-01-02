#ifndef _UI_PRESSROUTER_H_
#define _UI_PRESSROUTER_H_
#include "Button.h"

namespace ui
{
    /** @brief A single interface by which to trigger button
     * clicks on the focused button.
     */
    class ClickRouter
    {
    public:
        ClickRouter();
        void add(Button &button);
        void press();
        void release();
        bool isPressed();

    private:
        std::vector<Button *> _buttons;
        bool _pressed;
    };
} // namespace ui

#endif
