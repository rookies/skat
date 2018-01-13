#include "CardSorter.hh"

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
