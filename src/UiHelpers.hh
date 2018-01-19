#pragma once
#include <functional>
#include "Card.hh"

class UiHelpers {
public:
  static bool yesOrNoPrompt(std::function<void()> printPrompt);
  static unsigned int numberPrompt(std::function<void()> printPrompt,
    std::function<bool(unsigned int)> validate);
  static void cardNumbers(unsigned int min, unsigned int max, unsigned int digits);
  static void cardColorName(CardColor color);
private:
  UiHelpers();
};
