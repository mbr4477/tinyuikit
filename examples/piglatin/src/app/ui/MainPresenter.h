#ifndef _MAIN_PRESENTER_H_
#define _MAIN_PRESENTER_H_
#include <string>

class MainPresenter
{
public:
    class MainActivity
    {
    public:
        virtual void showTranslation(std::string translation) = 0;
    };

    MainPresenter(MainActivity &activity);
    void didUpdateInputText(std::string text);
    void didClickTranslateButton();

private:
    MainActivity &_activity;
    std::string _input;
};

#endif
