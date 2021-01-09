#ifndef _MAIN_ACTIVITY_H_
#define _MAIN_ACTIVITY_H_
#include "ui.h"
#include "MainPresenter.h"

using namespace ui;

class MainActivity : public Activity, public MainPresenter::MainActivity
{
public:
    MainActivity(int width, int height);
    virtual void showTranslation(std::string translation);

private:
    MainPresenter presenter;
    View root;
    TextField inputField;
    Label translationLabel;
    Button translateButton;
};

#endif
