#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "cards.hh"

int main() {
  /* Deal the cards: */
  auto cards = CardHelpers::deal();
  /* Sort and print them: */
  CardSorter sorter(CardColor::None, true, true);
  for (auto &cardset : cards) {
    std::sort(cardset.begin(), cardset.end(), sorter);
    CardHelpers::print(cardset);
  }
}
