#include <iostream>
#include <algorithm>
#include "Card.hh"
#include "CardHelpers.hh"
#include "CardSorter.hh"

int main() {
  std::cout << "Welcome to skat." << std::endl;
  /* Deal the cards: */
  std::cout << "Dealing the cards..." << std::endl;
  auto cards = CardHelpers::deal();
  /* Sort and print them: */
  CardSorter sorter(CardColor::None, true, true);
  for (auto &cardset : cards) {
    std::sort(cardset.begin(), cardset.end(), sorter);
    CardHelpers::print(cardset);
  }
}
