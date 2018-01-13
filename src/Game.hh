#pragma once
#include <tuple>
#include <array>
#include <memory>
#include "Player.hh"

class Game {
public:
  /* Public methods: */
  std::tuple<int,int> bidding(std::array<std::shared_ptr<Player>,3> const &players);
  /* Public member variables: */
  static const unsigned int bids[63];
private:
};
