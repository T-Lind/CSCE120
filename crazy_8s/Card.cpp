#include <iostream>

#include "Card.h"

using std::string;

Card::Card(string rank, string suit) /* TODO: initialize */ {
    if (rank.empty() || suit.empty()) {
        throw std::invalid_argument("Rank and suit must not be empty");
    }
    this->rank = rank;
    this->suit = suit;
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
