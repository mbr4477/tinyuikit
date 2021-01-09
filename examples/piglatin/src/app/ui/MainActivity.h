#ifndef _MAIN_ACTIVITY_H_
#define _MAIN_ACTIVITY_H_
#include "ui.h"
#include "MainPresenter.h"
#include "style/Stylesheet.h"

using namespace ui;

class MainActivity : public Activity, public MainPresenter::MainActivity
{
public:
    MainActivity(uint16_t width, uint16_t height);
    virtual void showTranslation(std::string translation);

private:
    MainPresenter presenter;
    View root;
    TextField inputField;
    Label translationLabel;
    Button translateButton;
    Stylesheet buttonStyles;
};

#endif
