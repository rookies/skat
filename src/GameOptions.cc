#include "GameOptions.hh"

GameOptions::GameOptions(CardColor tr, bool h, bool ouv, bool schn, bool schw) :
  type{GameType::Suit}, trump{tr}, hand{h}, ouvert{ouv}, schneider{schn}, schwarz{schw} { }

GameOptions::GameOptions(bool h, bool ouv, bool schn, bool schw) :
  type{GameType::Grand}, trump{CardColor::None}, hand{h}, ouvert{ouv}, schneider{schn}, schwarz{schw} { }

GameOptions::GameOptions(bool h, bool ouv) :
  type{GameType::Null}, trump{CardColor::None}, hand{h}, ouvert{ouv}, schneider{false}, schwarz{false} { }
