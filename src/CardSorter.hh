#pragma once
#include "Card.hh"

class CardSorter {
public:
  CardSorter(CardColor trumpColor=CardColor::None, bool highTen=true, bool trump=true);
  bool operator()(Card x, Card y) const;
private:
  CardColor m_trumpColor;
  bool m_highTen;
  bool m_trump;
};
