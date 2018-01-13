#pragma once
#include <vector>
#include <array>

enum CardColor {
  Bells = 0,  // Diamonds
  Hearts = 1,
  Leaves = 2, // Spades
  Acorns = 3, // Clubs
  None = 4
};

enum CardValue {
  Seven = 0,
  Eight = 1,
  Nine = 2,
  LowTen = 3,
  Jack = 4,
  Queen = 5,
  King = 6,
  Ten = 7,
  Ace = 8
};

struct Card {
  /* Constructor: */
  Card(CardColor c, CardValue v);
  /* Methods: */
  void printColor() const;
  void printValue(bool alignRight) const;
  void printColorCode() const;
  /* Member variables: */
  CardColor color;
  CardValue value;
};

class CardSorter {
public:
  CardSorter(CardColor trumpColor=CardColor::None, bool highTen=true, bool trump=true);
  bool operator()(Card x, Card y) const;
private:
  CardColor m_trumpColor;
  bool m_highTen;
  bool m_trump;
};

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
