#include <iostream>
#include <utility>
#include "cards.hh"

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

CardSorter::CardSorter(CardColor trumpColor, bool highTen, bool trump) :
  m_trumpColor{trumpColor}, m_highTen{highTen}, m_trump{trump} { }

bool CardSorter::operator()(Card x, Card y) const {
  if (m_trump && x.value == CardValue::Jack && y.value != CardValue::Jack) {
    return false;
  } else if (m_trump && y.value == CardValue::Jack && x.value != CardValue::Jack) {
    return true;
  } else if (x.color == y.color) {
    /* Sort according to value: */
    CardValue xval = x.value;
    CardValue yval = y.value;
    if (!m_highTen && x.value == CardValue::Ten) {
      xval = CardValue::LowTen;
    };
    if (!m_highTen && y.value == CardValue::Ten) {
      yval = CardValue::LowTen;
    };
    return (xval < yval);
  } else {
    /* Check if one card is trump: */
    if (m_trump && x.color == m_trumpColor && x.value != CardValue::Jack) return false;
    if (m_trump && y.color == m_trumpColor && y.value != CardValue::Jack) return true;
    /* If not, sort according to color: */
    return (x.color < y.color);
  };
}

CardHelpers::CardHelpers() { }

void CardHelpers::print(std::vector<Card> cards) {
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
  return result;
}

const CardColor CardHelpers::colors[] {
  CardColor::Acorns, CardColor::Leaves, CardColor::Hearts, CardColor::Bells
};

const CardValue CardHelpers::values[] {
  CardValue::Seven, CardValue::Eight, CardValue::Nine, CardValue::Jack,
  CardValue::Queen, CardValue::King, CardValue::Ten, CardValue::Ace
};
