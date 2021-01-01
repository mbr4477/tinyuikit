#ifndef _UI_VIEW_H_
#define _UI_VIEW_H_
#include <vector>
#include "Box.h"
#include "Canvas.h"
#include "Color.h"

namespace ui
{
    class View
    {
    public:
        View(const Box bounds);

        Box getBounds() const;
        void setBounds(Box bounds);

        std::vector<View *> getChildren() const;
        void addChild(View &child);

        void setBgColor(Color color);
        Color getBgColor() const;

        void setBorderColor(Color color);
        Color getBorderColor() const;

        virtual void draw(Canvas &canvas);

        bool isDirty() const;
        void markDirty();

    private:
        Box _bounds;
        Color _bgColor;
        Color _borderColor;
        bool _dirty;
        std::vector<View *> _children;

    protected:
        void drawChildren(Canvas &canvas);
        void drawBackground(Canvas &canvas);
        virtual void drawSelf(Canvas &canvas);
        void clearDirty();
    };
} // namespace ui

#endif