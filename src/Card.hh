#pragma once

enum class CardColor {
  Bells = 0,  // Diamonds
  Hearts = 1,
  Leaves = 2, // Spades
  Acorns = 3, // Clubs
  None = 4
};

enum class CardValue {
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
