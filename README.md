# Tiny UI Kit
A tiny UI kit for embedded devices.

:warning: **API is NOT stable!!!** :warning:
Once I start tagging releases, you should still probably stick with a single release and be wary of upgrading until a 1.0.0 version shows up, since pre-v1.0.0 may involve breaking changes.

## Problem
- `TODO`

## Minimal Example
- `TODO`

## Supported UI Components
- `TODO`

## User Input
- `TODO`

## Adding to Your Project
1. Download the source and add the source to your project's build and include paths
2. Download (or write) an implementation of `Canvas.h` that interacts with the display driver. This is the bridge between tinyuikit and your display. If you have a an Adafruit GFX display, you can use the drivers at https://github.com/mbr4477/tinyuikit-gfx.
3. Download (or write) code that interacts with UI elements to feed in user input. For example, call `TextRouter` based on serial or keyboard input or call `ClickRouter` methods when hardware buttons are pressed.

## Creating a Custom Display Driver
- `TODO`

## A Note on Memory Management
- `TODO`

## FAQ
### Why don't you include an Arduino `Serial` driver for `TextRouter`?
Because the driver is 3 lines of code. Assuming you have setup a `TextRouter`:
```c++
while (Serial.available())
{
    char c = Serial.read();
    textRouter.write(c);
}
```

### Why don't you include Adafruit GFX drivers?
Because this library is designed to be completely platform agnostic. If you have a C++11 toolchain for your target, you can use this library. However, I have provided GFX drivers at https://github.com/mbr4477/tinyuikit-gfx.

### Can I use this with a touchscreen or mouse input?
Yes.

However, I haven't attempted a driver yet. Following the `ClickRouter` and `TextRouter` paradigms, this should be a new `TouchRouter` class that could convert touch positions into clicks based on intersection with button bounding boxes. The major "gotcha" might be the need to make the router also take some responsibilities of a focus manager, giving focus to text fields on tap instead of only handling button-style inputs. But it is 100% possible.

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