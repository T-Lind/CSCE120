#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Card.h"

class Player {
 private:
    std::vector<Card*> hand;

 public:
  explicit Player(bool isAI);
  void addToHand(Card* c);
  std::size_t getHandSize();
  std::string getHandString();
  Card* playCard(std::vector<std::string> const& suits, std::string& currentRank, std::string& currentSuit);

    bool isAI;
};

#endif