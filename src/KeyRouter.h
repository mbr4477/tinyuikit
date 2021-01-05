#ifndef _UI_KEYROUTER_H_
#define _UI_KEYROUTER_H_
#include "TextField.h"

namespace ui
{
    /** @brief Route a single text input source to
     * the active text field
     */
    class KeyRouter
    {
    public:
        KeyRouter();

        void add(TextField &textField);
        void clear();

        void write(char c);

    private:
        std::vector<TextField *> _textFields;
    };
} // namespace ui

#endif