#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <algorithm>
#include "CardHelpers.hh"

CardHelpers::CardHelpers() { }

void CardHelpers::print(std::vector<Card> const &cards) {
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "┌──────┐";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "│ ";
    card.printValue(false);
    std::cout << " ";
    card.printColor();
    std::cout << " │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "│      │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "│      │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "│ ";
    card.printColor();
    std::cout << " ";
    card.printValue(true);
    std::cout << " │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto const &card : cards) {
    card.printColorCode();
    std::cout << "└──────┘";
  }
  std::cout << "\033[0m" << std::endl;
}

std::vector<Card> CardHelpers::getDeck() {
  std::vector<Card> result;
  for (auto const &color : colors) {
    for (auto const &value : values) {
      result.push_back(Card(color, value));
    }
  }
  return std::move(result);
}

std::array<std::vector<Card>,4> CardHelpers::deal() {
  /* Create a list of all cards: */
  auto cards = getDeck();
  /* Split them randomly: */
  srand(time(NULL));
  std::array<std::vector<Card>,4> result;
  for (int i=0; i < 3; ++i) {
    for (int j=0; j < 10; ++j) {
      int idx = rand() % cards.size();
      result[i].push_back(cards.at(idx));
      cards.erase(cards.begin()+idx);
    }
  }
  result[3] = std::move(cards);
  /* And return the result: */
  return std::move(result);
}

std::tuple<bool,unsigned int> CardHelpers::getSpitzenValue(std::vector<Card> const &cards) {
  bool without;
  /* Check if we have the acorns jack: */
  if (std::find(cards.begin(), cards.end(), Card(CardColor::Acorns, CardValue::Jack)) == cards.end()) {
    /* without */
    without = true;
  } else {
    /* with */
    without = false;
  };
  /* Check the other ones: */
  unsigned int result = 1;
  for (auto color : { CardColor::Leaves, CardColor::Hearts, CardColor::Bells }) {
    if ((std::find(cards.begin(), cards.end(), Card(color, CardValue::Jack)) == cards.end()) == without) {
      ++result;
    } else {
      break;
    };
  }
  return std::tuple<bool,unsigned int>(!without, result);
}

const CardColor CardHelpers::colors[] {
  CardColor::Acorns, CardColor::Leaves, CardColor::Hearts, CardColor::Bells
};

const CardValue CardHelpers::values[] {
  CardValue::Seven, CardValue::Eight, CardValue::Nine, CardValue::Jack,
  CardValue::Queen, CardValue::King, CardValue::Ten, CardValue::Ace
};
