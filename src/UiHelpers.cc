#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "UiHelpers.hh"

bool UiHelpers::yesOrNoPrompt(std::function<void()> printPrompt) {
  int response = -1;
  do {
    printPrompt();
    std::string answer;
    std::cin >> answer;
    if (answer == "y") {
      response = 1;
    } else if (answer == "n") {
      response = 0;
    };
  } while (response == -1);
  return (response == 1);
}

unsigned int UiHelpers::numberPrompt(std::function<void()> printPrompt,
  std::function<bool(unsigned int)> validate)
{
  unsigned int response;
  do {
    printPrompt();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> response;
  } while (std::cin.fail() || !validate(response));
  return response;
}

void UiHelpers::cardNumbers(unsigned int min, unsigned int max, unsigned int digits) {
  std::cout << "   ";
  for (unsigned int i=min; i <= max; ++i) {
    std::cout << std::setw(digits) << std::setfill('0') << i;
    if (i != max) {
      std::cout << "      ";
    };
  }
  std::cout << std::endl;
}

void UiHelpers::cardColorName(CardColor color) {
  switch (color) {
    case CardColor::Acorns:
      Card(CardColor::Acorns, CardValue::Ace).printColorCode();
      std::cout << "♣ Acorns\033[0m";
      break;
    case CardColor::Leaves:
      Card(CardColor::Leaves, CardValue::Ace).printColorCode();
      std::cout << "♠ Leaves\033[0m";
      break;
    case CardColor::Hearts:
      Card(CardColor::Hearts, CardValue::Ace).printColorCode();
      std::cout << "♥ Hearts\033[0m";
      break;
    case CardColor::Bells:
      Card(CardColor::Bells, CardValue::Ace).printColorCode();
      std::cout << "♦ Bells\033[0m";
      break;
    default:
      std::cout << "";
  }
}
