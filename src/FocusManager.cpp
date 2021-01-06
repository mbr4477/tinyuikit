#include "FocusManager.h"

using namespace ui;

FocusManager &FocusManager::shared()
{
    static FocusManager manager;
    return manager;
}

FocusManager::FocusManager()
    : _focusIndex{0},
      _root{NULL},
      _focused{NULL}
{
}

void FocusManager::setRoot(View &root)
{
    _root = &root;
    reset();
}

void FocusManager::setFocused(View &focused)
{
    if (_focused != NULL)
    {
        _focused->setFocus(false);
    }
    _focusIndex = focused.getFocusIndex();
    focused.setFocus(true);
    _focused = &focused;
}

View &FocusManager::getFocused()
{
    return *_focused;
}

View *FocusManager::findNeighbor(bool greater)
{
    if (!_root)
        return NULL;
    // adapted from https://stackoverflow.com/questions/5278580/non-recursive-depth-first-search-algorithm
    std::vector<std::reference_wrapper<View>> unvisited;
    unvisited.push_back(*_root);
    View *top;
    View *next = _focused;
    while (unvisited.size() > 0)
    {
        top = &(unvisited.back().get());
        unvisited.pop_back();
        for (auto c : top->getChildren())
        {
            unvisited.push_back(c);
        }

        if (!top->isFocusable())
        {
            continue;
        }

        if ((greater &&                            // looking for greater
             top->getFocusIndex() > _focusIndex && // the candidate is greater
             // the candidate is less the the previous bets match,
             // if another view has been found
             (next == _focused || top->getFocusIndex() < next->getFocusIndex())) ||
            (!greater &&                           // looking for less
             top->getFocusIndex() < _focusIndex && // the candidate is less
             // the candidate is greater the the previous best match,
             // if another view has been found
             (next == _focused || top->getFocusIndex() > next->getFocusIndex())))
        {
            next = top;
        }
    }
    return next;
}

void FocusManager::next()
{
    if (!_root)
        return;
    View *next = findNeighbor(true);
    if (next)
    {
        setFocused(*next);
    }
}

void FocusManager::prev()
{
    if (!_root)
        return;
    View *next = findNeighbor(false);
    if (next)
    {
        setFocused(*next);
    }
}

void FocusManager::reset()
{
    if (!_root)
        return;
    std::vector<std::reference_wrapper<View>> unvisited;
    unvisited.push_back(*_root);
    View *top;
    View *next = NULL;
    uint8_t lowestFocusIndex = 255;
    while (unvisited.size() > 0)
    {
        top = &(unvisited.back().get());
        unvisited.pop_back();
        for (auto c : top->getChildren())
        {
            unvisited.push_back(c);
        }

        if (!top->isFocusable())
        {
            continue;
        }

        if (top->getFocusIndex() < lowestFocusIndex)
        {
            next = top;
        }
    }
    if (next)
    {
        setFocused(*next);
    }
}
