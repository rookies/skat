#include <cstdlib>
#include <ctime>
#include <vector>
#include "cards.hh"

int main() {
  /* Create a list of all cards: */
  std::vector<Card> cards;
  for (unsigned int i=0; i < 4; ++i) {
    for (unsigned int j=0; j < 8; ++j) {
      cards.push_back(Card(CardColor(i), CardValue(j)));
    }
  }
  /* Split them randomly: */
  srand(time(NULL));
  std::vector<Card> playerCards[3];
  for (int i=0; i < 3; ++i) {
    for (int j=0; j < 10; ++j) {
      int idx = rand() % cards.size();
      playerCards[i].push_back(cards.at(idx));
      cards.erase(cards.begin()+idx);
    }
    printCards(playerCards[i]);
  }
  printCards(cards);
}
