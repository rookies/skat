#include <iostream>
#include <string>
#include <limits>
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
