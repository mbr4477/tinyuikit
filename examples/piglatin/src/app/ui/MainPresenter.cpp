#include "MainPresenter.h"
#include "../domain/TranslateIntoPigLatin.h"

MainPresenter::MainPresenter(MainPresenter::MainActivity &activity)
    : _activity{activity}
{
}

void MainPresenter::didUpdateInputText(std::string input)
{
    _input = input;
}

void MainPresenter::didClickTranslateButton()
{
    _activity.showTranslation(TranslateIntoPigLatin(_input));
}