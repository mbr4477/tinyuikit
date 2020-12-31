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
    class LabelStyle : public Style
    {
    public:
        LabelStyle(
            Color textColor,
            Alignment halign = Alignment::LEFT,
            VAlignment valign = VAlignment::TOP,
            Color bgColor = Color(),
            Color borderColor = Color());

        void setTextColor(Color color);
        Color getTextColor();

        void setAlignment(Alignment align);
        Alignment getAlignment();

        void setVAlignment(VAlignment align);
        VAlignment getVAlignment();

    private:
        Color _textColor;
        Alignment _halign;
        VAlignment _valign;
    };

    class Label : public View
    {
    public:
        Label(
            std::string text,
            Box bounds,
            LabelStyle *style);

        void setText(std::string text);
        std::string getText();

        virtual void setStyle(LabelStyle *style, State state = NORMAL);
        virtual LabelStyle *getStyle();

        virtual void draw(Canvas &canvas);

    protected:
        virtual void drawSelf(Canvas &canvas);

    private:
        std::string _text;
    };
} // namespace ui

#endif