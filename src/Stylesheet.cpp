#include "Stylesheet.h"
using namespace ui;

Stylesheet::Stylesheet()
    : _styles{}
{
}

void Stylesheet::add(Style style)
{
    _styles.push_back(style);
}

void Stylesheet::applyTo(View &view)
{
    view.setStateListener([this](ViewState state, View &view) {
        for (auto s : _styles)
        {
            if (s.selector == state)
            {
                view.setBgColor(s.background);
                view.setBorderColor(s.border);
            }
        }
    });
}

void Stylesheet::applyTo(Label &label)
{
    label.setStateListener([this](ViewState state, View &view) {
        // should be safe since the listener is known to
        // be for a Label
        Label &label = static_cast<Label &>(view);
        for (auto s : _styles)
        {
            if (s.selector == state)
            {
                label.setBgColor(s.background);
                label.setBorderColor(s.border);
                label.setTextColor(s.color);
            }
        }
    });
}