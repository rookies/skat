#include <vector>
#include "cards.hh"

int main() {
  std::vector<Card> cards;
  for (unsigned int i=0; i < 4; ++i) {
    for (unsigned int j=0; j < 8; ++j) {
      cards.push_back(Card(CardColor(i), CardValue(j)));
    }
    printCards(cards);
    cards.clear();
  }
}
