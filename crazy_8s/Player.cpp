#include <iostream>
#include <sstream>

#include "Player.h"

using std::vector, std::string, std::size_t;

Player::Player(bool isAI) : isAI(isAI), hand({}) {
}

void Player::addToHand(Card *c) {
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

Card *Player::playCard(vector<string> const &suits, string &currentRank, string &currentSuit) {
    if (isAI) {
        for (auto it = hand.begin(); it != hand.end(); it++) {
            if ((*it)->canBePlayed(currentRank, currentSuit)) {
                Card *cardToPlay = *it;
                hand.erase(it);
                cardToPlay->play();
                currentRank = cardToPlay->getRank();
                if (currentRank == "8") {
                    if (!hand.empty()) {
                        currentSuit = hand.front()->getSuit();
                    } else {
                        currentSuit = suits.front();
                    }
                } else {
                    currentSuit = cardToPlay->getSuit();
                }
                return cardToPlay;
            }
        }
        return nullptr;
    } else {
        std::cout << "Your hand contains: " << getHandString() << "\n";
        std::cout << "The next card played must be a " << currentRank << " or " << currentSuit << "\n";
        std::cout << "What would you like to play? (enter \"draw card\" to draw a card)\n";
        while (true) {
            string input;
            std::getline(std::cin, input);

            if (input == "draw card") {
                return nullptr;
            }
            for (auto it = hand.begin(); it != hand.end(); it++) {
                std::istringstream iss(input);
                std::string inputRank, inputSuit;
                iss >> inputRank >> inputSuit;

                if ((*it)->getRank() == inputRank && (*it)->getSuit() == inputSuit) {
                    if ((*it)->canBePlayed(currentRank, currentSuit)) {
                        Card *cardToPlay = *it;
                        hand.erase(it);
                        cardToPlay->play();
                        currentRank = cardToPlay->getRank();
                        currentSuit = cardToPlay->getSuit();
                        if (currentRank == "8") {
                            std::cout << "What suit would you like to declare?\n";
                            while (true) {
                                string newSuit;
                                std::getline(std::cin, newSuit);

                                bool found = false;
                                for (const auto &suit: suits) {
                                    if (suit == newSuit) {
                                        found = true;
                                        break;
                                    }
                                }

                                if (found) {
                                    currentSuit = newSuit;
                                    break;
                                } else {
                                    std::cout << "That's not a suit in this deck. Try again.\n";
                                }
                            }
                        }
                        return cardToPlay;
                    } else {
                        std::cout << "You can't play that card. Try again.\n";
                        return nullptr;
                    }
                }
            }
            std::cout << "That's not a card you have. Try again.\n";

        }
    }
    return nullptr;
}