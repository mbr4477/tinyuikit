#include "MainActivity.h"

MainActivity::MainActivity(uint16_t width, uint16_t height)
    : Activity(),
      root{{0, 0, width, height}},
      translationLabel{"", {10, 10, width - 20, 30}},
      inputField{"Enter text to translate", {10, 50, width - 20, 30}},
      translateButton{"Translate", {10, height - 40, width - 20, 30}},
      presenter{*this},
      buttonStyles{}
{
    root.addChild(translationLabel);
    root.addChild(inputField);
    root.addChild(translateButton);
    setRoot(root);

    translateButton.setClickListener([this]() {
        presenter.didUpdateInputText(inputField.getText());
        presenter.didClickTranslateButton();
    });

    buttonStyles.add({NORMAL, UI_BLUE, UI_TRANSPARENT, UI_WHITE});
    buttonStyles.add({ACTIVE, UI_WHITE, UI_TRANSPARENT, UI_BLUE});
    buttonStyles.add({FOCUSED, UI_BLUE, UI_WHITE, UI_WHITE});
    buttonStyles.applyTo(translateButton);
}

void MainActivity::showTranslation(std::string translation)
{
    translationLabel.setText(translation);
}
