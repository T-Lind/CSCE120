# include "Passport.h"

using std::string, std::vector;

Passport::Passport(std::string camperName, bool isJuniorPassport) : camperName(camperName), isJuniorPassport(isJuniorPassport), parksVisited() {}

string Passport::getCamperName() {
    return camperName;
}

bool Passport::checkJuniorPassport() {
    return isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
	INFO(park)

    if (park == nullptr) {
        return;
    }
    parksVisited.push_back(park);
    park->addCamper(this);
}

double Passport::getMilesHiked() {
    double miles = 0;
    for (auto & i : parksVisited) {
        miles += i->getTrailMiles();
    }
    return miles;
}

int Passport::getHikerLevel() {
    double miles = getMilesHiked();
    if (isJuniorPassport) {
        miles *= 2;
    }
    return static_cast<int>(miles / 100);
}

