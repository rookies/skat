#pragma once
#include <vector>
#include <string>
#include <array>
#include "Card.hh"
#include "GameOptions.hh"

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
   * params: cards of the player, cards in the skat
   * return value: array of two card numbers (1..12) the player wants to put away */
  virtual std::array<unsigned int,2> selectCards(std::vector<Card> const &cards,
    std::vector<Card> const &skat) = 0;
  /* Called when the player has to select the game options.
   * return value: game options the player choose (hand is ignored) */
  virtual GameOptions selectGameOptions() = 0;
  /* Called after game options have been selected if the player lost the bidding.
   * params: the game options, name of the winner */
  /* TODO: Pass position of the winner */
  virtual void biddingLost(GameOptions const &options, std::string const &name) = 0;
};
