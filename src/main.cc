#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "cards.hh"

int main() {
  /* Create a list of all cards: */
  const std::vector<CardColor> colors {
    CardColor::Eichel, CardColor::Blatt, CardColor::Herz, CardColor::Schellen
  };
  const std::vector<CardValue> values {
    CardValue::Sieben, CardValue::Acht, CardValue::Neun, CardValue::Unter,
    CardValue::Ober, CardValue::Koenig, CardValue::Zehn, CardValue::Ass
  };
  std::vector<Card> cards;
  for (auto color : colors) {
    for (auto value : values) {
      cards.push_back(Card(color, value));
    }
  }
  /* Split them randomly: */
  srand(time(NULL));
  CardSorter sorter(CardColor::None, true, true);
  std::vector<Card> playerCards[3];
  for (int i=0; i < 3; ++i) {
    for (int j=0; j < 10; ++j) {
      int idx = rand() % cards.size();
      playerCards[i].push_back(cards.at(idx));
      cards.erase(cards.begin()+idx);
    }
    std::sort(playerCards[i].begin(), playerCards[i].end(), sorter);
    printCards(playerCards[i]);
  }
  printCards(cards);
}
