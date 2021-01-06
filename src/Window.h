#ifndef _UI_WINDOW_H_
#define _UI_WINDOW_H_
#include "Activity.h"
#include "Canvas.h"

namespace ui
{
    class Window
    {
    public:
        static Window &main();

        Window();

        void setCanvas(Canvas &canvas);

        Activity &getActivity();
        void setActivity(Activity &activity);

        void requestFocus();

        void update();

    private:
        void draw();
        Activity *_activity;
        Canvas *_canvas;
    };
} // namespace ui

#endif