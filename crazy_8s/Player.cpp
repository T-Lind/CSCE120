#include <iostream>
#include <sstream>

#include "Player.h"

using std::vector, std::string, std::size_t;

Player::Player(bool isAI) : isAI(isAI), hand({}) {
}

void Player::addToHand(Card* c) {
  hand.push_back(c);
}

size_t Player::getHandSize() {
    return hand.size();
}

std::string Player::getHandString() {
    std::stringstream ss;
    for (size_t i = 0; i < hand.size(); i++) {
        ss << hand.at(i)->getRank() << " " << hand.at(i)->getSuit();
        if (i != hand.size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}

Card* Player::playCard(vector<string> const& suits, string& currentRank, string& currentSuit) {
    for (size_t i = 0; i < hand.size(); i++) {
        if (hand.at(i)->canBePlayed(currentRank, currentSuit)) {
            Card* c = hand.at(i);
            hand.erase(hand.begin() + i);
            c->play();
            currentRank = c->getRank();
            currentSuit = c->getSuit();
            return c;
        }
    }

    return nullptr;
}