#pragma once
#include "Player.hh"

class HumanPlayer : public Player {
public:
  HumanPlayer(std::string name);
  std::string getName() override;
  void init(std::vector<Card> const &cards, PlayerPosition position) override;
  bool bid(unsigned int currentBid) override;
  bool biddingWon(unsigned int finalBid, std::vector<Card> const &cards) override;
  std::array<unsigned int,2> selectCards(std::vector<Card> const &cards,
    std::vector<Card> const &skat) override;
  GameOptions selectGameOptions() override;
private:
  std::string m_name;
};
