#ifndef _GFXCANVAS_H_
#define _GFXCANVAS_H_
#include "Adafruit_GFX.h"
#include "ui.h"

namespace ui
{
    class GFXCanvas : public Canvas
    {
    public:
        GFXCanvas(Adafruit_GFX &gfx);
        void clearRect(Box rect);
        void fillRect(Box rect, Color fill);
        void strokeRect(Box rect, Color border);
        void addText(std::string text, unsigned int x, unsigned int y, Color color);
        Box getTextBounds(std::string text);

    private:
        Adafruit_GFX *_gfx;
    };
} // namespace ui

#endif