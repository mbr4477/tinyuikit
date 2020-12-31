#ifndef _UI_VIEW_H_
#define _UI_VIEW_H_
#include "Box.h"
#include "Style.h"
#include <vector>
#include "Canvas.h"

namespace ui
{
    class View
    {
    public:
        enum State
        {
            NORMAL = 0,
            ACTIVE,
            HOVER
        };

        View(const Box bounds, Style *style);

        Box getBounds() const;
        void setBounds(Box bounds);

        virtual Style *getStyle();
        virtual void setStyle(Style *style, State state = NORMAL);

        void setState(State state);
        State getState() const;

        std::vector<View *> getChildren() const;
        void addChild(View &child);

        virtual void draw(Canvas &canvas);

        bool isDirty();
        void markDirty();

    private:
        Box _bounds;
        Style *_styles[3];
        State _state;
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