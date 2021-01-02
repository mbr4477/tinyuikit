#ifndef _UI_BUTTON_H_
#define _UI_BUTTON_H_
#include <functional>
#include "Label.h"

namespace ui
{
    class Button : public Label
    {
    public:
        Button(std::string text, Box bounds);

        /** @brief Send a press event that is suppressed
         * if the button is respecting focus and does not
         * have it.
         */
        void press(bool respectFocus = true);
        void release();

        void setClickListener(std::function<void(void)> listener);

    private:
        std::function<void(void)> _clickListener;
        ViewState _prevState;
        bool _pressed;
    };
} // namespace ui

#endif