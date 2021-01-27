#ifndef _UI_INIT_H_
#define _UI_INIT_H_
#include "View.h"
#include "FocusManager.h"

namespace ui
{
    /** An activity that holds a view.
     * Currently, this is no more than a view holder, 
     * however, it provides a future avenue for lifecycle
     * callbacks.
     * 
     * TODO: Is having the user subclass this really better 
     * than just subclassing View (which could also support 
     * lifecycle events)?
     */
    class Activity
    {
    public:
        Activity(uint16_t width, uint16_t height);
        View &getRoot();

    private:
        View _root;
    };
} // namespace ui

#endif