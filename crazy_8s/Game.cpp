#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>


using namespace std;

Game::Game() : players({}), suits({}), ranks({}), deck({}), drawPile({}), discardPile({}) {}

void Game::loadDeckFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("File could not be opened");
    }

    string line;
    getline(file, line);
    stringstream ss(line);
    string suit;
    while (ss >> suit) {
        suits.push_back(suit);
    }

    getline(file, line);
    ss.clear();
    ss.str(line);
    string rank;
    while (ss >> rank) {
        ranks.push_back(rank);
    }

    while (getline(file, line)) {
        ss.clear();
        ss.str(line);
        string rank, suit;
        if (!(ss >> rank >> suit)) {
            throw std::runtime_error("Invalid line format");
        }

        bool rankFound = false;
        for (const auto& r : ranks) {
            if (r == rank) {
                rankFound = true;
                break;
            }
        }

        bool suitFound = false;
        for (const auto& s : suits) {
            if (s == suit) {
                suitFound = true;
                break;
            }
        }

        if (!rankFound || !suitFound) {
            throw std::runtime_error("Invalid rank or suit");
        }

        try {
            Card* card = new Card(rank, suit);
            deck.push_back(card);
            drawPile.insert(drawPile.begin(), card);
        } catch (std::invalid_argument& e) {
            throw std::runtime_error("Invalid card");
        }

        // If a card has extra data, throw exception
        if (ss >> rank) {
            throw std::runtime_error("Extra data on line");
        }
    }

    file.close();
}

void Game::addPlayer(bool isAI) {
    Player* newPlayer = new Player(isAI);
    players.push_back(newPlayer);
}

void Game::drawCard(Player* p) {
    if (drawPile.empty()) {
        if (discardPile.empty()) {
            throw std::runtime_error("Both draw pile and discard pile are empty");
        } else {
            std::cout << "Draw pile, empty, flipping the discard pile." << std::endl;
            while (!discardPile.empty()) {
                drawPile.push_back(discardPile.back());
                discardPile.pop_back();
            }
        }
    }

    Card* card = drawPile.back();
    drawPile.pop_back();
    p->addToHand(card);
}

Card* Game::deal(int numCards) {
    if (drawPile.empty()) {
        throw std::runtime_error("Draw pile is empty");
    }

    Card* initialDiscard = drawPile.back();
    drawPile.pop_back();
    discardPile.push_back(initialDiscard);

    for (int i = 0; i < numCards; i++) {
        for (Player* player : players) {
            drawCard(player);
        }
    }

    return initialDiscard;
}

string Game::mostPlayedSuit() {
    int maxCount = -1;
    string mostPlayedSuit;

    for (const auto& suit : suits) {
        int count = 0;
        for (Card* card : deck) {
            if (card->getSuit() == suit) {
                count += card->getTimesPlayed();
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostPlayedSuit = suit;
        }
    }

    return mostPlayedSuit;
}

int Game::runGame() {
    int currentPlayer = 0;
    while (true) {
        for (Player* player : players) {
            std::cout << "Player " << currentPlayer << "'s turn!" << std::endl;
            std::string currentRank = discardPile.back()->getRank();
            std::string currentSuit = discardPile.back()->getSuit();
            Card* card = player->playCard(suits, currentRank, currentSuit);
            if (card) {
                if (card->getRank() == "8") {
                    std::cout << "Player " << currentPlayer << " plays " << card->getRank() << " " << card->getSuit() << " and changes the suit to " << card->getSuit() << "." << std::endl;
                } else {
                    std::cout << "Player " << currentPlayer << " plays " << card->getRank() << " " << card->getSuit() << "." << std::endl;
                }
                discardPile.push_back(card);
                if (player->getHandSize() == 0) {
                    return currentPlayer;
                }
            } else {
                try {
                    drawCard(player);
                    std::cout << "Player " << currentPlayer << " draws a card." << std::endl;
                } catch (std::runtime_error& e) {
                    std::cout << "Player " << currentPlayer << " cannot draw a card." << std::endl;
                    return -1;
                }
            }
            currentPlayer = (currentPlayer + 1) % players.size();
        }
    }
}

// Destructor--Deallocates all the dynamic memory we allocated
Game::~Game() {
  for (unsigned int i = 0; i < deck.size(); i++) {
    delete deck.at(i);
  }
  for (unsigned int i = 0; i < players.size(); i++) {
    delete players.at(i);
  }
}
