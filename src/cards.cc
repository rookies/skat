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

void Card::printColorCode() const {
  switch (color) {
    case CardColor::Eichel:
      std::cout << "\033[37;40m";
      break;
    case CardColor::Blatt:
      std::cout << "\033[32;40m";
      break;
    case CardColor::Herz:
      std::cout << "\033[31;40m";
      break;
    case CardColor::Schellen:
      std::cout << "\033[33;40m";
      break;
  }
}

CardSorter::CardSorter(CardColor trumpColor, bool highTen, bool trump) :
  m_trumpColor{trumpColor}, m_highTen{highTen}, m_trump{trump} { }

bool CardSorter::operator()(Card x, Card y) const {
  if (m_trump && x.value == CardValue::Unter && y.value != CardValue::Unter) {
    return false;
  } else if (m_trump && y.value == CardValue::Unter && x.value != CardValue::Unter) {
    return true;
  } else if (x.color == y.color) {
    /* Sort according to value: */
    CardValue xval = x.value;
    CardValue yval = y.value;
    if (!m_highTen && x.value == CardValue::Zehn) {
      xval = CardValue::LowTen;
    };
    if (!m_highTen && y.value == CardValue::Zehn) {
      yval = CardValue::LowTen;
    };
    return (xval < yval);
  } else {
    /* Check if one card is trump: */
    if (m_trump && x.color == m_trumpColor && x.value != CardValue::Unter) return false;
    if (m_trump && y.color == m_trumpColor && y.value != CardValue::Unter) return true;
    /* If not, sort according to color: */
    return (x.color < y.color);
  };
}

void printCards(std::vector<Card> cards) {
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "┌──────┐";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "│ ";
    card.printValue(false);
    std::cout << " ";
    card.printColor();
    std::cout << " │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "│      │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "│      │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "│ ";
    card.printColor();
    std::cout << " ";
    card.printValue(true);
    std::cout << " │";
  }
  std::cout << "\033[0m" << std::endl;
  for (auto card : cards) {
    card.printColorCode();
    std::cout << "└──────┘";
  }
  std::cout << "\033[0m" << std::endl;
}
