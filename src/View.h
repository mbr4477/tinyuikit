#ifndef _UI_VIEW_H_
#define _UI_VIEW_H_
#include <stdint.h>
#include <vector>
#include <functional>

#include "Box.h"
#include "Canvas.h"
#include "Color.h"
#include "Event.h"

namespace ui
{
    enum ViewState
    {
        NORMAL,
        FOCUSED,
        ACTIVE
    };
    class View
    {
    public:
        View(const Box bounds, bool focusable = false);

        Box getBounds() const;
        void setBounds(Box bounds);

        std::vector<View *> getChildren() const;

        void addChild(View &child);

        void setBgColor(Color color);
        Color getBgColor() const;

        void setBorderColor(Color color);
        Color getBorderColor() const;

        void setState(ViewState state);
        ViewState getState() const;

        /** @brief Set the state listener.
         * The state listener is called when the view changes
         * state and can be used to modify the view style
         * based on the state.
         */
        void setStateListener(std::function<void(ViewState)> listener);

        /** Draw to the given canvas. */
        virtual void draw(Canvas *canvas);

        bool isDirty() const;
        void markDirty();

        bool isFocusable() const;
        bool hasFocus() const;

        /** @brief Set the focus. Note that this does NOT
         * guarantee that this is the only item focused.
         */
        void setFocus(bool focus);

        void setFocusIndex(uint8_t focusIndex);
        uint8_t getFocusIndex() const;

        virtual bool handleEvent(Event *event);

    protected:
        bool propagate(Event *event);
        void requestFocus();

    private:
        Box _bounds;
        ViewState _state;
        Color _bgColor;
        Color _borderColor;
        bool _dirty;
        bool _focused;
        uint8_t _focusIndex;
        bool _focusable;
        std::function<void(ViewState)> _stateListener;
        std::vector<View *> _children;
        void drawSelf(Canvas *canvas);

    protected:
        void drawChildren(Canvas *canvas);
        void drawBackground(Canvas *canvas);
        void clearDirty();
    };
} // namespace ui

#endif