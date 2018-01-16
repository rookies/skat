#include <iostream>
#include "CardHelpers.hh"
#include "UiHelpers.hh"
#include "HumanPlayer.hh"

HumanPlayer::HumanPlayer(std::string name) : m_name{name} { }

std::string HumanPlayer::getName() {
  return m_name;
}

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
  std::cout << " and here are your cards (";
  auto spitzen = CardHelpers::getSpitzenValue(cards);
  if (std::get<0>(spitzen)) {
    std::cout << "with ";
  } else {
    std::cout << "without ";
  };
  std::cout << std::get<1>(spitzen);
  std::cout << ", " << CardHelpers::getPoints(cards) << " points):" << std::endl;
  CardHelpers::print(cards);
}

bool HumanPlayer::bid(unsigned int currentBid) {
  return UiHelpers::yesOrNoPrompt([&]() {
    std::cout << m_name << ", " << currentBid << "? (y/n) " << std::flush;
  });
}

bool HumanPlayer::biddingWon(unsigned int finalBid, std::vector<Card> const &cards) {
  std::cout << m_name << ", here are your cards again:" << std::endl;
  CardHelpers::print(cards);
  std::cout << "   01      02      03      04      05      06";
  std::cout << "      07      08      09      10" << std::endl;
  std::cout << "Your last bid was " << finalBid << "." << std::endl;
  return UiHelpers::yesOrNoPrompt([&]() {
    std::cout << "Do you want to see the skat? (y/n) " << std::flush;
  });
}

std::array<unsigned int,2> HumanPlayer::selectCards(std::vector<Card> const &cards,
  std::vector<Card> const &skat)
{
  std::cout << "Okay " << m_name << ", here is the skat:" << std::endl;
  CardHelpers::print(skat);
  std::cout << "   11      12" << std::endl;
  unsigned int card1 = UiHelpers::numberPrompt([&]() {
    std::cout << "What's the first card you want to put away? (1..12) " << std::flush;
  }, [&](unsigned int n) {
    return (n >= 1 && n <= 12);
  });
  unsigned int card2 = UiHelpers::numberPrompt([&]() {
    std::cout << "What's the second card you want to put away? (1..12, except " << card1 << ") " << std::flush;
  }, [&](unsigned int n) {
    return (n >= 1 && n <= 12 && n != card1);
  });
  return std::array<unsigned int,2> {card1, card2};
}

GameOptions HumanPlayer::selectGameOptions() {
  /* Print prompt: */
  std::cout << "Okay, " << m_name << ", what do you want to play?" << std::endl;
  Card(CardColor::Bells, CardValue::Ace).printColorCode();
  std::cout << " 1 - ♦ Bells" << std::endl;
  Card(CardColor::Hearts, CardValue::Ace).printColorCode();
  std::cout << " 2 - ♥ Hearts" << std::endl;
  Card(CardColor::Leaves, CardValue::Ace).printColorCode();
  std::cout << " 3 - ♠ Leaves" << std::endl;
  Card(CardColor::Acorns, CardValue::Ace).printColorCode();
  std::cout << " 4 - ♣ Acorns" << std::endl;
  std::cout << "\033[36m 5 - U Grand" << std::endl;
  std::cout << " 6 - 0 Null\033[0m" << std::endl;
  /* Get the answer: */
  unsigned int type = UiHelpers::numberPrompt([&]() {
    std::cout << "-> " << std::flush;
  }, [&](unsigned int n) {
    return (n >= 1 && n <= 6);
  });
  /* Ask for ouvert: */
  bool ouvert = UiHelpers::yesOrNoPrompt([&]() {
    std::cout << "Ouvert? (y/n) " << std::flush;
  });
  /* Ask for schneider & schwarz: */
  bool schneider, schwarz = false;
  if (type != 6) {
    schneider = UiHelpers::yesOrNoPrompt([&]() {
      std::cout << "Schneider? (y/n) " << std::flush;
    });
    if (schneider) {
      schwarz = UiHelpers::yesOrNoPrompt([&]() {
        std::cout << "Schwarz? (y/n) " << std::flush;
      });
    };
  };
  /* Return GameOptions: */
  switch (type) {
    case 1:
      return GameOptions(CardColor::Bells, false, ouvert, schneider, schwarz);
    case 2:
      return GameOptions(CardColor::Hearts, false, ouvert, schneider, schwarz);
    case 3:
      return GameOptions(CardColor::Leaves, false, ouvert, schneider, schwarz);
    case 4:
      return GameOptions(CardColor::Acorns, false, ouvert, schneider, schwarz);
    case 5:
      return GameOptions(false, ouvert, schneider, schwarz);
    default:
      return GameOptions(false, ouvert);
  }
}
