#pragma once
#include <functional>

class UiHelpers {
public:
  static bool yesOrNoPrompt(std::function<void()> printPrompt);
  static unsigned int numberPrompt(std::function<void()> printPrompt,
    std::function<bool(unsigned int)> validate);
private:
  UiHelpers();
};
