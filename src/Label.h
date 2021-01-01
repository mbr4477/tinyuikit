#ifndef _UI_LABEL_H_
#define _UI_LABEL_H_
#include <string>
#include "View.h"

namespace ui
{
    enum Alignment
    {
        LEFT,
        CENTER,
        RIGHT
    };
    enum VAlignment
    {
        TOP,
        MIDDLE,
        BOTTOM
    };
    class Label : public View
    {
    public:
        Label(
            std::string text,
            Box bounds);

        void setText(std::string text);
        std::string getText() const;

        void setTextColor(Color color);
        Color getTextColor() const;

        void setAlignment(Alignment align);
        Alignment getAlignment() const;

        void setVAlignment(VAlignment align);
        VAlignment getVAlignment() const;

        virtual void draw(Canvas &canvas);

    protected:
        virtual void drawSelf(Canvas &canvas);

    private:
        std::string _text;
        Color _textColor;
        Alignment _halign;
        VAlignment _valign;
    };
} // namespace ui

#endif