#include "FocusManager.h"

using namespace ui;

FocusManager::FocusManager()
    : _focusIndex{0},
      _focusables{},
      _focused{NULL}
{
}

void FocusManager::setFocused(unsigned int focusIndex)
{
    if (_focused != NULL)
    {
        _focused->setFocus(false);
    }
    _focusIndex = focusIndex;
    View *candidate = findFocusedByIndex(_focusIndex);
    if (candidate != NULL)
    {
        candidate->setFocus(true);
    }
    _focused = candidate;
}

bool FocusManager::next()
{
    if (_focusables.size() > 0)
    {
        unsigned int maxIndex = getMaxFocusIndex();
        if (_focusIndex < maxIndex)
        {
            unsigned int nextFocused = maxIndex;
            unsigned int possibleNext;
            for (unsigned int i = 0; i < _focusables.size(); i++)
            {
                possibleNext = _focusables[i]->getFocusIndex();
                if (possibleNext > _focusIndex && possibleNext < nextFocused)
                {
                    nextFocused = possibleNext;
                }
            }
            setFocused(nextFocused);
            return true;
        }
    }
    return false;
}

bool FocusManager::prev()
{
    if (_focusables.size() > 0)
    {
        unsigned int minIndex = getMinFocusIndex();
        if (_focusIndex > minIndex)
        {
            unsigned int nextFocused = minIndex;
            unsigned int possiblePrev;
            for (unsigned int i = 0; i < _focusables.size(); i++)
            {
                possiblePrev = _focusables[i]->getFocusIndex();
                if (possiblePrev < _focusIndex && possiblePrev > nextFocused)
                {
                    nextFocused = possiblePrev;
                }
            }
            setFocused(nextFocused);
            return true;
        }
    }
    return false;
}

void FocusManager::reset()
{
    if (_focusables.size() > 0)
    {
        setFocused(getMinFocusIndex());
    }
}

void FocusManager::add(View &focusable)
{
    if (!focusable.isFocusable())
        return;

    _focusables.push_back(&focusable);
    if (_focusables.size() == 1)
    {
        setFocused(focusable.getFocusIndex());
    }
}

View *FocusManager::findFocusedByIndex(unsigned int focusIndex)
{
    for (auto f : _focusables)
    {
        if (f->getFocusIndex() == focusIndex)
        {
            return f;
        }
    }
    return NULL;
}

unsigned int FocusManager::getMaxFocusIndex()
{
    unsigned int maxFocusIndex = 0;
    for (unsigned int i = 0; i < _focusables.size(); i++)
    {
        if (_focusables[i]->getFocusIndex() > maxFocusIndex)
        {
            maxFocusIndex = _focusables[i]->getFocusIndex();
        }
    }
    return maxFocusIndex;
}

unsigned int FocusManager::getMinFocusIndex()
{
    unsigned int minFocusIndex = 0;
    for (unsigned int i = 0; i < _focusables.size(); i++)
    {
        if (_focusables[i]->getFocusIndex() < minFocusIndex)
        {
            minFocusIndex = _focusables[i]->getFocusIndex();
        }
    }
    return minFocusIndex;
}