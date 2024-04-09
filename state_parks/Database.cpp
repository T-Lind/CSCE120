# include "Database.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list


Database::~Database() {
	for (unsigned int i = 0; i < stateParkList.size(); ++i) {
		delete stateParkList.at(i);
	}
	
	for (unsigned int i = 0; i < camperList.size(); ++i) {
		delete camperList.at(i);
	}
}

void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
	INFO(parkName)
	INFO(entranceFee)
	INFO(trailMiles)

	// TODO: implement function

    StatePark* park = new StatePark(parkName, entranceFee, trailMiles);
    stateParkList.push_back(park);
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
	INFO(camperName)
	INFO(isJuniorPassport)

	// TODO: implement function

    Passport* camper = new Passport(camperName, isJuniorPassport);
    camperList.push_back(camper);
}

void Database::addParkToPassport(string camperName, string parkName) {
	INFO(camperName)
	INFO(parkName)


        StatePark* park = nullptr;
        Passport* camper = nullptr;

        for (auto & i : stateParkList) {
            if (i->getParkName() == parkName) {
                park = i;
                break;
            }
        }

        for (auto & i : camperList) {
            if (i->getCamperName() == camperName) {
                camper = i;
                break;
            }
        }

        if (park != nullptr && camper != nullptr) {
            park->addCamper(camper);
            camper->addParkVisited(park);
        }
}

vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) {
	INFO(lowerBound)
	INFO(upperBound)

	// TODO: (optional) implement function
	
	return {};
}

vector<string> Database::getHikersAtLeastLevel(int level) {
	INFO(level)

	// TODO: (optional) implement function

	return {};
}
