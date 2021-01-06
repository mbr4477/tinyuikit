#ifndef _UI_INIT_H_
#define _UI_INIT_H_
#include "View.h"
#include "FocusManager.h"

namespace ui
{
    class Activity
    {
    public:
        Activity(Canvas &canvas);
        View *getRoot();

    protected:
        /** If root has already been set, this does nothing */
        void setRoot(View &view);

    private:
        View *_root;
    };
} // namespace ui

#endif