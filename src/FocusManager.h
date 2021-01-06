#ifndef _UI_FOCUSMANAGER_H_
#define _UI_FOCUSMANAGER_H_
#include "View.h"
#include <vector>
#include "stdint.h"

namespace ui
{
    class FocusManager
    {
    public:
        static FocusManager &shared();

        void setRoot(View &view);

        void setFocused(View &view);
        View &getFocused();

        void next();
        void prev();
        void reset();

    private:
        FocusManager();

        uint8_t _focusIndex;
        View *_focused;
        View *_root;

        /** Find the neighboring focus index, either greater or less */
        View *findNeighbor(bool greater);
    };
} // namespace ui

#endif