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

bool HumanPlayer::bid(unsigned int currentBid) {
  int response = -1;
  do {
    std::cout << m_name << ", " << currentBid << "? (y/n) " << std::flush;
    std::string answer;
    std::cin >> answer;
    if (answer == "y") {
      response = 1;
    } else if (answer == "n") {
      response = 0;
    };
  } while (response == -1);
  return (response == 1);
}

void HumanPlayer::biddingDone(PlayerPosition winner, unsigned int lastBid) {
  
}
