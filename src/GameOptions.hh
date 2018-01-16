#pragma once
#include "Card.hh"

enum class GameType {
  Suit,
  Grand,
  Null
};

struct GameOptions {
  GameOptions() = delete;
  /* Constructor for suit game: */
  GameOptions(CardColor tr, bool h, bool ouv, bool schn, bool schw);
  /* Constructor for grand game: */
  GameOptions(bool h, bool ouv, bool schn, bool schw);
  /* Constructor for null game: */
  GameOptions(bool h, bool ouv);
  /* Public member variables: */
  GameType type;
  CardColor trump; // only for suit game
  bool hand;
  bool ouvert;
  bool schneider;  // not for null game
  bool schwarz;    // not for null game
};
