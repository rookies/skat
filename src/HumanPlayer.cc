#include <iostream>
#include "CardHelpers.hh"
#include "HumanPlayer.hh"

HumanPlayer::HumanPlayer(std::string name) : m_name{name} { }

void HumanPlayer::init(std::vector<Card> const &cards, PlayerPosition position) {
  std::cout << m_name << ", your position is ";
  switch (position) {
    case PlayerPosition::Vorderhand:
      std::cout << "Vorderhand";
      break;
    case PlayerPosition::Mittelhand:
      std::cout << "Mittelhand";
      break;
    case PlayerPosition::Hinterhand:
      std::cout << "Hinterhand";
      break;
  }
  std::cout << " and here are your cards:" << std::endl;
  CardHelpers::print(cards);
}

bool HumanPlayer::bid(unsigned int lastBid) {
  
}

void HumanPlayer::biddingDone(PlayerPosition winner, unsigned int lastBid) {
  
}
