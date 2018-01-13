#include <iostream>
#include <algorithm>
#include <array>
#include "Card.hh"
#include "CardHelpers.hh"
#include "CardSorter.hh"
#include "HumanPlayer.hh"

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
  std::array<HumanPlayer,3> players {
    HumanPlayer("Alice"),
    HumanPlayer("Bob"),
    HumanPlayer("Carol")
  };
  /* Tell them their cards & position: */
  players[0].init(cards[0], PlayerPosition::Vorderhand);
  players[1].init(cards[1], PlayerPosition::Mittelhand);
  players[2].init(cards[2], PlayerPosition::Hinterhand);
  /* Bidding: */
  std::array<unsigned int,63> bids {
     18, 20, 22, 23, 24, 27, 30, 33, 35, 36, 40, 44, 45, 46, 48, 50, 54, 55, 59, 60, 63,
     66, 70, 72, 77, 80, 81, 84, 88, 90, 96, 99,100,108,110,117,120,121,126,130,132,135,
    140,143,144,150,153,154,156,160,162,165,168,170,176,180,187,192,198,204,216,240,264
  };
  int lastBid = -1;
  int player = -1;
  bool answer1, answer2;
  /* First round, Mittelhand tells & Vorderhand listens: */
  do {
    answer1 = players[1].bid(bids[lastBid+1]);
    if (answer1) {
      ++lastBid;
      player = 1;
      answer2 = players[0].bid(bids[lastBid]);
      if (answer2) {
        player = 0;
      };
    };
  } while (answer1 && answer2);
  /* Second round, Hinterhand tells and winner of first round (or Vorderhand, if none) listens: */
  int finalWinner = -1;
  unsigned int finalBid = 0;
  if (player == -1) {
    answer1 = players[2].bid(bids[0]);
    if (answer1) {
      do {
        answer1 = players[0].bid(bids[lastBid+1]);
        if (answer1) {
          player = 0;
          ++lastBid;
          answer2 = players[2].bid(bids[lastBid+1]);
          if (answer2) {
            player = 2;
          } else {
            /* Vorderhand wins */
            finalWinner = 0;
            finalBid = bids[lastBid];
          };
        } else {
          /* Hinterhand wins */
          finalWinner = 2;
          finalBid = bids[lastBid+1];
        };
      } while (answer1 && answer2);
    } else {
      answer2 = players[0].bid(bids[0]);
      if (answer2) {
        /* Vorderhand wins */
        finalWinner = 0;
        finalBid = bids[0];
      } else {
        /* Ramsch */
        finalWinner = -1;
      };
    };
  } else {
    int firstwinner = player;
    do {
      answer1 = players[2].bid(bids[lastBid]);
      if (answer1) {
        player = 2;
        ++lastBid;
        answer2 = players[firstwinner].bid(bids[lastBid]);
        if (answer2) {
          player = firstwinner;
        } else {
          /* Hinterhand wins */
          finalWinner = 2;
          finalBid = bids[lastBid-1];
        };
      } else {
        /* Winner of first round wins */
        finalWinner = firstwinner;
        finalBid = bids[lastBid];
      };
    } while (answer1 && answer2);
  };
  /* Bidding done, print result: */
  if (finalWinner == -1) {
    std::cout << "Nobody wants to play, time for Ramsch." << std::endl;
    /* TODO */
  } else {
    std::cout << players[finalWinner].getName() << " plays, last bid was " << finalBid << "." << std::endl;
    if (players[finalWinner].biddingWon(finalBid, cards[finalWinner])) {
      /* normal game */
      players[finalWinner].selectCards(cards[finalWinner], cards[3]);
      /* TODO */
    } else {
      /* hand game */
      /* TODO */
    };
  };
}
