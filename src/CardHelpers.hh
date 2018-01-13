#pragma once
#include <vector>
#include <array>
#include <tuple>
#include "Card.hh"

class CardHelpers {
public:
  /* Public methods: */
  static void print(std::vector<Card> const &cards);
  static std::vector<Card> getDeck();
  static std::array<std::vector<Card>,4> deal();
  static std::tuple<bool,unsigned int> getSpitzenValue(std::vector<Card> const &cards);
  static unsigned int getPoints(std::vector<Card> const &cards);
  /* Public member variables: */
  static const CardColor colors[4];
  static const CardValue values[8];
private:
  CardHelpers();
};
