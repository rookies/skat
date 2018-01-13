#pragma once
#include <string>
#include "Player.hh"

class HumanPlayer : public Player {
public:
  HumanPlayer(std::string name);
  void init(std::vector<Card> const &cards, PlayerPosition position) override;
  bool bid(unsigned int currentBid) override;
  void biddingDone(PlayerPosition winner, unsigned int lastBid) override;
private:
  std::string m_name;
};
