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

        virtual bool handleEvent(Event *event);

        void setClickListener(std::function<void(void)> listener);

    private:
        std::function<void(void)> _clickListener;
        ViewState _prevState;
        bool _pressed;
    };
} // namespace ui

#endif