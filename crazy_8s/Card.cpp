#include <iostream>
#include <cctype>
#include "Card.h"

using std::string;

Card::Card(string rank, string suit) : rank(rank), suit(suit), timesPlayed(0) {
    if (rank.empty() || suit.empty()) {
        throw std::invalid_argument("Rank and suit must not be empty");
    }

    for (char c : rank) {
        if (!std::isalnum(c)) {
            throw std::invalid_argument("Rank must only contain alphanumeric characters");
        }
    }

    for (char c : suit) {
        if (!std::isalnum(c)) {
            throw std::invalid_argument("Suit must only contain alphanumeric characters");
        }
    }
}

string Card::getRank() {
    return rank;
}

string Card::getSuit() {
    return suit;
}

int Card::getTimesPlayed() {
    return timesPlayed;
}

bool Card::canBePlayed(string currentRank, string currentSuit) {
    if (rank == "8") {
        return true;
    }
    return rank == currentRank || suit == currentSuit;
}

void Card::play() {
    timesPlayed++;
}
