#include <iostream>
#include <algorithm>
#include "Card.hh"
#include "CardHelpers.hh"
#include "CardSorter.hh"
#include "HumanPlayer.hh"

int main() {
  std::cout << "Welcome to skat." << std::endl;
  /* Deal the cards: */
  std::cout << "Dealing the cards..." << std::endl;
  auto cards = CardHelpers::deal();
  /* Sort them: */
  CardSorter sorter(CardColor::None, true, true);
  for (auto &cardset : cards) {
    std::sort(cardset.begin(), cardset.end(), sorter);
  }
  /* Create human players: */
  HumanPlayer p1("Alice");
  HumanPlayer p2("Bob");
  HumanPlayer p3("Carol");
  /* Tell them their cards & position: */
  p1.init(cards[0], PlayerPosition::Vorderhand);
  p2.init(cards[1], PlayerPosition::Mittelhand);
  p3.init(cards[2], PlayerPosition::Hinterhand);
}
