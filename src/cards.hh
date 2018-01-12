#pragma once
#include <vector>

enum CardColor {
  Schellen = 0, // Bells / Diamonds
  Herz = 1,     // Hearts
  Blatt = 2,    // Leaves / Spades
  Eichel = 3    // Acorns / Clubs
};

enum CardValue {
  Sieben = 0, // Seven
  Acht = 1,   // Eight
  Neun = 2,   // Nine
  Unter = 3,  // Jack
  Ober = 4,   // Queen
  Koenig = 5, // King
  Zehn = 6,   // Ten
  Ass = 7     // Ace
};

struct Card {
  Card(CardColor c, CardValue v);
  void printColor() const;
  void printValue(bool alignRight) const;
  void printColorCode() const;
  CardColor color;
  CardValue value;
};

void printCards(std::vector<Card> cards);
