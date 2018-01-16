#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include "Card.hh"
#include "CardHelpers.hh"
#include "CardSorter.hh"
#include "HumanPlayer.hh"
#include "Game.hh"

int main() {
  std::cout << "Welcome to skat." << std::endl;
  /* Deal the cards: */
  std::cout << "Dealing the cards..." << std::endl;
  auto cards = CardHelpers::deal();
  /* Sort them: */
  CardSorter sorter(CardColor::None, true, true);
  for (auto &cardset : cards) {
    std::sort(cardset.begin(), cardset.end(), sorter);
  }
  /* Create human players: */
  std::array<std::shared_ptr<Player>,3> players {
    std::make_shared<HumanPlayer>("Alice"),
    std::make_shared<HumanPlayer>("Bob"),
    std::make_shared<HumanPlayer>("Carol")
  };
  /* Tell them their cards & position: */
  players[0]->init(cards[0], PlayerPosition::Vorderhand);
  players[1]->init(cards[1], PlayerPosition::Mittelhand);
  players[2]->init(cards[2], PlayerPosition::Hinterhand);
  /* Bidding: */
  Game game;
  int finalWinner, finalBid;
  std::tie(finalWinner, finalBid) = game.bidding(players);
  /* Bidding done, print result: */
  if (finalWinner == -1) {
    std::cout << "Nobody wants to play, time for Ramsch." << std::endl;
    std::cout << "Sorry, but that's not implemented, yet." << std::endl;
    /* TODO: Implement Ramsch. */
  } else {
    std::cout << players[finalWinner]->getName() << " plays, last bid was " << finalBid << "." << std::endl;
    /* Ask the winner if (s)he wants to see the skat: */
    if (players[finalWinner]->biddingWon(finalBid, cards[finalWinner])) {
      /* normal game */
      auto putaway = players[finalWinner]->selectCards(cards[finalWinner], cards[3]);
      /* TODO: Check and remember putaway. */
    } else {
      /* hand game */
      /* TODO: Set flag for hand game and inform players. */
    };
    /* Ask the winner what (s)he wants to play: */
    players[finalWinner]->selectGameOptions();
  };
}
