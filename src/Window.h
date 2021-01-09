#ifndef _UI_WINDOW_H_
#define _UI_WINDOW_H_
#include "Activity.h"
#include "Canvas.h"
#include "EventDispatcher.h"

namespace ui
{
    class Window
    {
    public:
        static Window &main();

        void setCanvas(Canvas &canvas);

        Activity &getActivity();
        void setActivity(Activity &activity);

        void requestFocus();

        void update();

    private:
        Window();
        void draw();
        Activity *_activity;
        Canvas *_canvas;
        EventDispatcher _dispatcher; // The dispatcher used to send events to this window.
    };
} // namespace ui

#endif