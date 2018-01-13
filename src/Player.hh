#pragma once
#include <vector>
#include "Card.hh"

enum class PlayerPosition {
  Vorderhand,
  Mittelhand,
  Hinterhand
};

class Player {
public:
  /* Called at the beginning of a game, params: cards & position of the player: */
  virtual void init(std::vector<Card> const &cards, PlayerPosition position) = 0;
  /* Called when the player has to give or answer a bid, param: value of the last bid: */
  virtual bool bid(unsigned int lastBid) = 0;
  /* Called when the bidding is done, params: player who won, value of the last bid: */
  virtual void biddingDone(PlayerPosition winner, unsigned int lastBid) = 0;
};
