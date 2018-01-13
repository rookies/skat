#pragma once
#include <vector>
#include <array>
#include "Card.hh"

class CardHelpers {
public:
  /* Public methods: */
  static void print(std::vector<Card> const &cards);
  static std::vector<Card> getDeck();
  static std::array<std::vector<Card>,4> deal();
  /* Public member variables: */
  static const CardColor colors[4];
  static const CardValue values[8];
private:
  CardHelpers();
};
