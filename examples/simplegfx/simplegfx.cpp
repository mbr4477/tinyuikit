/**
 * A simple Adafruit GFX example.
 * 
 * Requirements:
 *  - Adafruit_GFX
 *  - Adafruit display driver (e.g., Adafruit_ILI9341)
 *  - tinyuikit-gfx Canvas driver
 */

#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h" // Change to your display driver
#include "ui.h"               // Include tinyuikit
#include "GFXCanvas.h"        // Include tinuikit-gfx driver

/* Hardware Pin Definitions ***********/
#define TFT_LITE A16
#define TFT_RST 7
#define TFT_DC 8
#define TFT_CS A15

#define BUTTON_PREV 4
#define BUTTON_NEXT 6
#define BUTTON_ENTER A5
/**************************************/

/* Screen Dimensions ******************/
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
/**************************************/

using namespace ui; // Optional (use ui:: prefix if removed)

/* tinyuikit Declarations *************/
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST); // Create the display
GFXCanvas canvas(tft);                         // Create the tinyuikit-gfx canvas
Activity mainActivity;                         // Activity to hold the main view
/**************************************/

int counter;                                          // A counter to display in the view;
View root(Box(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));    // Create a root view to fill the screen
Label label("0", Box(10, 10, SCREEN_WIDTH - 20, 30)); // Create a label for the counter
// A button to increment the counter
Button addOneButton(
    "+1",
    Box(10, SCREEN_HEIGHT - 40, SCREEN_WIDTH / 2 - 20, 30));
// A button to reset the counter
Button resetButton(
    "Reset",
    Box(10, SCREEN_HEIGHT - 40, SCREEN_WIDTH / 2 - 20, 30));

void setup()
{
    // Setup and turn on the TFT lite
    pinMode(TFT_LITE, OUTPUT);
    pinMode(TFT_LITE, HIGH);

    tft.begin();        // Start the TFT
    tft.setRotation(1); // Display configuration
    tft.setTextSize(2);

    // Tell the main (default) window what canvas to use (our display)
    Window::main().setCanvas(canvas);

    // Setup the button hardware pins
    pinMode(BUTTON_PREV, INPUT);
    pinMode(BUTTON_NEXT, INPUT);
    pinMode(BUTTON_ENTER, INPUT);

    // Get a reference to the shared input driver so we can set it up
    InputDevice &input = InputDevice::shared();

    // Register a button driver function that
    // checks the input and calls the provided
    // button handler when an input event has occured
    input.setButtonDriver([](ButtonEventHandler sendButton) {
        ButtonEventData event;
        static bool enterPressed = false;
        if (digitalRead(BUTTON_NEXT))
        {
            event.buttonId = UI_BUTTON_NEXT_ID;
            event.state = PRESSED;
            sendButton(event);
            // No need to handle release event
            // because UI_BUTTON_NEXT_ID is sent
            // to the focus manager, not a view
            // that would need to update its state
            // on released.
        }
        else if (digitalRead(BUTTON_PREV))
        {
            event.buttonId = UI_BUTTON_PREV_ID;
            event.state = PRESSED;
            sendButton(event);
            // Comment from previous branch applies
        }
        else if (digitalRead(BUTTON_ENTER) && !enterPressed)
        {
            event.buttonId = UI_BUTTON_ENTER_ID;
            event.state = PRESSED;
            enterPressed = true;
            sendButton(event);
        }
        else if (digitalRead(BUTTON_ENTER) && enterPressed)
        {
            event.buttonId = UI_BUTTON_ENTER_ID;
            event.state = RELEASED;
            enterPressed = false;
            sendButton(event);
        }
    });

    // Create state listeners that will style the buttons
    // appropriately based on the state they are in
    addOneButton.setStateListener([](ViewState state) {
        switch (state)
        {
        case NORMAL:
            addOneButton.setBgColor(CYAN);
            addOneButton.setBorderColor(TRANSPARENT);
            addOneButton.setTextColor(WHITE);
            break;
        case FOCUSED:
            addOneButton.setBgColor(CYAN);
            addOneButton.setBorderColor(WHITE);
            addOneButton.setTextColor(WHITE);
            break;
        case ACTIVE: // Occurs when PRESSED
            addOneButton.setBgColor(WHITE);
            addOneButton.setBorderColor(TRANSPARENT);
            addOneButton.setTextColor(CYAN);
            break;
        }
    });
    resetButton.setStateListener([](ViewState state) {
        switch (state)
        {
        case NORMAL:
            resetButton.setBgColor(RED);
            resetButton.setBorderColor(TRANSPARENT);
            resetButton.setTextColor(WHITE);
            break;
        case FOCUSED:
            resetButton.setBgColor(RED);
            resetButton.setBorderColor(WHITE);
            resetButton.setTextColor(WHITE);
            break;
        case ACTIVE: // Occurs when PRESSED
            resetButton.setBgColor(WHITE);
            resetButton.setBorderColor(TRANSPARENT);
            resetButton.setTextColor(RED);
            break;
        }
    });

    counter = 0; // Reset the counter to 0

    // Create click listeners to handle click events
    // on both buttons and update the counter and label
    addOneButton.setClickListener([]() {
        counter++;
        label.setText(std::to_string(counter));
    });
    resetButton.setClickListener([]() {
        counter = 0;
        label.setText(std::to_string(counter));
    });

    // Add the views to the root
    root.addChild(label);
    root.addChild(addOneButton);
    root.addChild(resetButton);

    mainActivity.setRoot(root);               // Set the root view of the activity
    Window::main().setActivity(mainActivity); // Tell the window which activity to show
}

void loop()
{
    // Tell the main window to update
    Window::main().update();
}