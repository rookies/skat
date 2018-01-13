#pragma once
#include <vector>
#include "Card.hh"

enum class PlayerPosition {
  Vorhand,
  Mittelhand,
  Hinterhand
};

class Player {
public:
  virtual Player() = 0;
  virtual ~Player() = 0;
  /* Called at the beginning of a game, params: cards & position of the player: */
  virtual bool init(std::vector<Card> const &cards, PlayerPosition position) = 0;
  /* Called when the player has to give or answer a bid, param: value of the last bid: */
  virtual bool bid(unsigned int lastBid) = 0;
  /* Called when the bidding is done, params: player who won, value of the last bid: */
  virtual bool biddingDone(PlayerPosition winner, unsigned int lastBid) = 0;
};
