#pragma once
#include <vector>
#include <string>
#include "Card.hh"

enum class PlayerPosition {
  Vorderhand,
  Mittelhand,
  Hinterhand
};

class Player {
public:
  virtual std::string getName() = 0;
  /* Called at the beginning of a game.
   * params: cards & position of the player */
  virtual void init(std::vector<Card> const &cards, PlayerPosition position) = 0;
  /* Called when the player has to give or answer a bid.
   * param: value of the current bid
   * return value: whether the player wants to give the bid or not */
  virtual bool bid(unsigned int currentBid) = 0;
  /* Called when the bidding is done and the player won.
   * params: value of the final bid, cards of the player
   * return value: whether the player wants to see the skat or not */
  virtual bool biddingWon(unsigned int finalBid, std::vector<Card> const &cards) = 0;
  /* Called when the player wants to see the skat.
   * params: cards of the player, cards in the skat */
  virtual void selectCards(std::vector<Card> const &cards, std::vector<Card> const &skat) = 0;
  /* TODO: Select gamemode */
  /* TODO: biddingLost */
};
