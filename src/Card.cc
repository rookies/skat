#include <iostream>
#include "Card.hh"

Card::Card(CardColor c, CardValue v) : color{c}, value{v} { }

void Card::printColor() const {
  switch (color) {
    case CardColor::Acorns:
      std::cout << "♣";
      break;
    case CardColor::Leaves:
      std::cout << "♠";
      break;
    case CardColor::Hearts:
      std::cout << "♥";
      break;
    case CardColor::Bells:
      std::cout << "♦";
      break;
  }
}

void Card::printValue(bool alignRight) const {
  if (alignRight && value != CardValue::Ten) {
    std::cout << " ";
  };
  switch (value) {
    case CardValue::Seven:
      std::cout << "7";
      break;
    case CardValue::Eight:
      std::cout << "8";
      break;
    case CardValue::Nine:
      std::cout << "9";
      break;
    case CardValue::Jack:
      std::cout << "U";
      break;
    case CardValue::Queen:
      std::cout << "O";
      break;
    case CardValue::King:
      std::cout << "K";
      break;
    case CardValue::Ten:
      std::cout << "10";
      break;
    case CardValue::Ace:
      std::cout << "A";
      break;
  }
  if (!alignRight && value != CardValue::Ten) {
    std::cout << " ";
  };
}

void Card::printColorCode() const {
  switch (color) {
    case CardColor::Acorns:
      std::cout << "\033[37;40m";
      break;
    case CardColor::Leaves:
      std::cout << "\033[32;40m";
      break;
    case CardColor::Hearts:
      std::cout << "\033[31;40m";
      break;
    case CardColor::Bells:
      std::cout << "\033[33;40m";
      break;
  }
}
