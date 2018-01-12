#pragma once
#include <vector>

enum CardColor {
  Schellen = 0, // Bells / Diamonds
  Herz = 1,     // Hearts
  Blatt = 2,    // Leaves / Spades
  Eichel = 3,   // Acorns / Clubs
  None = 4
};

enum CardValue {
  Sieben = 0, // Seven
  Acht = 1,   // Eight
  Neun = 2,   // Nine
  LowTen = 3, // Ten (low)
  Unter = 4,  // Jack
  Ober = 5,   // Queen
  Koenig = 6, // King
  Zehn = 7,   // Ten
  Ass = 8     // Ace
};

struct Card {
  Card(CardColor c, CardValue v);
  void printColor() const;
  void printValue(bool alignRight) const;
  void printColorCode() const;
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

void printCards(std::vector<Card> cards);
