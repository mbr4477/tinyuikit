#ifndef _UI_BUTTON_H_
#define _UI_BUTTON_H_
#include "Label.h"

namespace ui
{
    class Button : public Label
    {
    public:
        Button(std::string text, Box bounds);
        // Button(std::string text, Box bounds, LabelStyle style);
    };
} // namespace ui

#endif