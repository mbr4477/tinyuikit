#include "InputDriver.h"
#include "FocusManager.h"
#include "Window.h"

using namespace ui;

InputDriver *InputDriver::main()
{
    static InputDriver driver(Window::main());
    return &driver;
}

InputDriver::InputDriver(Window *window)
    : _window{window}
{
}

void InputDriver::sendEvent(Event event)
{
    _window->getActivity()->getRoot()->handleEvent(&event);
}

void InputDriver::tabNext()
{
    FocusManager::shared()->next();
}

void InputDriver::tabPrev()
{
    FocusManager::shared()->prev();
}