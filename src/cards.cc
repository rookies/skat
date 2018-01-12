#include <iostream>
#include "cards.hh"

Card::Card(CardColor c, CardValue v) : color{c}, value{v} { }

void Card::printColor() const {
  switch (color) {
    case CardColor::Eichel:
      std::cout << "♣";
      break;
    case CardColor::Blatt:
      std::cout << "♠";
      break;
    case CardColor::Herz:
      std::cout << "♥";
      break;
    case CardColor::Schellen:
      std::cout << "♦";
      break;
  }
}

void Card::printValue(bool alignRight) const {
  if (alignRight && value != CardValue::Zehn) {
    std::cout << " ";
  };
  switch (value) {
    case CardValue::Sieben:
      std::cout << "7";
      break;
    case CardValue::Acht:
      std::cout << "8";
      break;
    case CardValue::Neun:
      std::cout << "9";
      break;
    case CardValue::Unter:
      std::cout << "U";
      break;
    case CardValue::Ober:
      std::cout << "O";
      break;
    case CardValue::Koenig:
      std::cout << "K";
      break;
    case CardValue::Ass:
      std::cout << "A";
      break;
    case CardValue::Zehn:
      std::cout << "10";
      break;
  }
  if (!alignRight && value != CardValue::Zehn) {
    std::cout << " ";
  };
}

void printCards(std::vector<Card> cards) {
  for (auto card : cards) {
    std::cout << "┌──────┐";
  }
  std::cout << std::endl;
  for (auto card : cards) {
    std::cout << "│ ";
    card.printValue(false);
    std::cout << " ";
    card.printColor();
    std::cout << " │";
  }
  std::cout << std::endl;
  for (auto card : cards) {
    std::cout << "│      │";
  }
  std::cout << std::endl;
  for (auto card : cards) {
    std::cout << "│      │";
  }
  std::cout << std::endl;
  for (auto card : cards) {
    std::cout << "│ ";
    card.printColor();
    std::cout << " ";
    card.printValue(true);
    std::cout << " │";
  }
  std::cout << std::endl;
  for (auto card : cards) {
    std::cout << "└──────┘";
  }
  std::cout << std::endl;
}
