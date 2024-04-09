# include "Passport.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list

string Passport::getCamperName() {
	// TODO: implement getter
    return camperName;
}

bool Passport::checkJuniorPassport() {
    return isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
	INFO(park)
    parksVisited.push_back(park);
}

double Passport::getMilesHiked() {
	// TODO: (optional) implement function
    double miles = 0;
    for (auto & i : parksVisited) {
        miles += i->getTrailMiles();
    }
    return miles;
}

int Passport::getHikerLevel() {
// 100 miles = 1 level
    double milesHiked = getMilesHiked();
    return milesHiked / 100;
}
