#ifndef _UI_INIT_H_
#define _UI_INIT_H_
#include "View.h"
#include "FocusManager.h"
#include "ClickRouter.h"
#include "KeyRouter.h"

namespace ui
{
    class Activity
    {
    public:
        Activity(Canvas &canvas);
        void draw();

        void handleKey(char c);

        void focusNext();
        void focusPrev();
        void selectDown();
        void selectUp();

    protected:
        void setRoot(View &view);
        void registerButton(Button &button);
        void registerTextField(TextField &textField);

    private:
        ClickRouter _clickRouter;
        KeyRouter _keyRouter;
        FocusManager _focusManager;
        View *_root;
        Canvas *_canvas;
        uint8_t _focusCounter;
    };
} // namespace ui

#endif