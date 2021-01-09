#include "MainActivity.h"

MainActivity::MainActivity(int width, int height)
    : Activity(),
      root{{0, 0, width, height}},
      translationLabel{"", {10, 10, width - 20, 30}},
      inputField{"Enter text to translate", {10, 50, width - 20, 30}},
      translateButton{"Translate", {10, height - 40, width - 20, 30}},
      presenter{*this}
{
    root.addChild(translationLabel);
    root.addChild(inputField);
    root.addChild(translateButton);
    setRoot(root);
    translateButton.setClickListener([this]() {
        presenter.didUpdateInputText(inputField.getText());
        presenter.didClickTranslateButton();
    });
}

void MainActivity::showTranslation(std::string translation)
{
    translationLabel.setText(translation);
}
