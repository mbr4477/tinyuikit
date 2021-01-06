#ifndef _UI_TEXTFIELD_H_
#define _UI_TEXTFIELD_H_
#include <string>
#include "Label.h"
#include "Event.h"

namespace ui
{
    class TextField : public Label
    {
    public:
        TextField(std::string placeholder, const Box bounds);

        void setPlaceholder(std::string placeholder);

        virtual void draw(Canvas *canvas);

        virtual bool handleEvent(Event *event);

    private:
        std::string _placeholder;
    };
} // namespace ui

#endif