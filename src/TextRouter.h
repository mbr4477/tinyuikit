#ifndef _UI_TEXTROUTER_H_
#define _UI_TEXTROUTER_H_
#include "TextField.h"

namespace ui
{
    /** @brief Route a single text input source to
     * the active text field
     */
    class TextRouter
    {
    public:
        TextRouter();

        void add(TextField &textField);

        void write(char c);

    private:
        std::vector<TextField *> _textFields;
    };
} // namespace ui

#endif