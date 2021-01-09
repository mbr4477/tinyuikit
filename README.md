# Tiny UI Kit
A tiny UI kit for embedded devices.

:warning: **API is NOT stable!!!** :warning:
Once I start tagging releases, you should still probably stick with a single release and be wary of upgrading until a 1.0.0 version shows up, since pre-v1.0.0 may involve breaking changes.

## Problem 
You want a usable GUI with user input on a tiny microcontroller without having write your own code to draw UI elements, handle styles, manage focus, route key presses to the right text fields, etc.

You could use LVGL, but you need something even more lightweight and very simple with little setup needed. Plus, you'd like to leverage the objective-oriented capabilities of C++.

## Architecture

- A `Canvas` is an interface to drawing functions. Subclasses of `Canvas` implement the drawing functions for specific displays. 
- A `View` has style attributes, event handlers, focus, states, and (given a `Canvas`) can draw itself to the display.
- An `Activity` has a root `View`. Subclasses of `Activity` allow you to create a screen, with its root and subviews.
- The `FocusManager` is given a root `View` and manages focus, stepping through the focus order and providing access to the focused `View`. 
- An `EventManager` routes events to the root `View` of a `Window`'s `Activity` or to the currently focused `View`.
- An `InputDevice` holds callback functions to poll input devices for events and send these events to an `EventManager` or to the `FocusManager`.
- A `Window` is given a `Canvas` and an `Activity`, polls the `InputDevice`, and draws the `Activity` to the `Canvas`.

## Using In Your Project

1. Download the source and add the source to your project's build and include paths
2. Download (or write) an implementation of `Canvas.h` that interacts with the display driver. This is the bridge between tinyuikit and your display. If you have a an Adafruit GFX display, you can use the drivers at https://github.com/mbr4477/tinyuikit-gfx. I haven't used buffer-based rendering since this requires the microcontroller to have enough RAM.
3. Subclass `Activity` to write your UI code. (This is analogous to an Android Activity.)
4. Set the main window's canvas (`Window::main().setCanvas`) so the window knows *how* to draw to the display
5. Set the main window's activity (`Window::main().setActivity`) so the window knows *what* to draw to the display
6. Provide an input driver callback using the shared input device (`InputDevice::shared()`) so hardware can generate input events that get passed to the views
7. In your main loop, call `Window::main().update()`

## FAQ

### Why don't you include Adafruit GFX drivers in this repo?

Because this library is designed to be completely platform agnostic. If you have a C++11 toolchain for your target, you can use this library. However, I have provided GFX drivers at https://github.com/mbr4477/tinyuikit-gfx.

### Does this work with the Arduino IDE?
I don't know :smile: (I use PlatformIO and VS Code)

## Roadmap
- Support multi-view applications (i.e., view switching)
- Additional UI components: toggle switch, list view, progress bar, status bar
- Animations :thinking:
- Test on Arduino Uno 
- Layouts!
- 100% static memory version?
- Pre-stylized components for quick, good-looking UIs (probably a separate repo)
- Font support
- Bitmap support
- Examples folder
- Arduino input drivers for buttons and Serial text input (a separate repo)
- Stylesheets or something similar to make styling easier
- Clipping :thinking: