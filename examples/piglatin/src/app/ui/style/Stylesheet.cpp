#include "Stylesheet.h"

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
    label.setStateListener([this](ViewState state, Label &label) {
        
    });
}