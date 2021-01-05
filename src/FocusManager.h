#ifndef _UI_FOCUSMANAGER_H_
#define _UI_FOCUSMANAGER_H_
#include "View.h"
#include <vector>

namespace ui
{
    class FocusManager
    {
    public:
        FocusManager();

        /** @brief Add a view to the focus manager. 
         * If this is the first view added, it takes focus.
         */
        void add(View &focusable);

        void clear();

        /** Returns false if already at last focusable element */
        bool next();

        /** Returns false if already at first focusable element */
        bool prev();

        /** Reset to first focusable element */
        void reset();

    private:
        unsigned int _focusIndex;
        View *_focused;
        std::vector<View *> _focusables;

        /** Find the focused item or NULL if none found */
        View *findFocusedByIndex(unsigned int focusIndex);
        void setFocused(unsigned int focusIndex);
        unsigned int getMaxFocusIndex();
        unsigned int getMinFocusIndex();
    };
} // namespace ui

#endif