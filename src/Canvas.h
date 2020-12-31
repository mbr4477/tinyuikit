#ifndef _UI_CANVAS_H_
#define _UI_CANVAS_H_
#include <string>
#include "Box.h"
#include "Color.h"

namespace ui
{
    class Canvas
    {
    public:
        Canvas(Box bounds) : _inset(bounds)
        {
        }
        virtual void clearRect(Box rect) = 0;
        virtual void fillRect(Box rect, Color fill) = 0;
        virtual void strokeRect(Box rect, Color border) = 0;
        virtual void addText(std::string text, unsigned int x, unsigned int y, Color color) = 0;
        virtual Box getTextBounds(std::string text);
        void setInset(Box inset)
        {
            _inset = inset;
        }
        Box getInset()
        {
            return _inset;
        }

    private:
        Box _inset;
    };
} // namespace ui

#endif