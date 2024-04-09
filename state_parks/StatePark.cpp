# include "Passport.h"

using std::string, std::vector;

StatePark::StatePark(string parkName, double entranceFee, double trailMiles) : parkName(parkName), entranceFee(entranceFee), trailMiles(trailMiles), camperLog() {}

string StatePark::getParkName() {
    return parkName;
}

double StatePark::getEntranceFee() {
    return entranceFee;
}

double StatePark::getTrailMiles() {
    return trailMiles;
}

void StatePark::addCamper(Passport* camper) {
    INFO(camper)

    // Check if camper is nullptr
    if (camper == nullptr) {
        std::cout << "Failed to add Camper: nullptr provided" << std::endl;
        return;
    }

    // Check if camper has already been added
    for (auto &existingCamper : camperLog) {
        if (existingCamper == camper) {
            std::cout << "Failed to add Camper: Camper already added" << std::endl;
            return;
        }
    }

    camperLog.push_back(camper);
}

double StatePark::getRevenue() {
    double revenue = 0;
    for (auto & i : camperLog) {
        if (i->checkJuniorPassport()) {
            revenue += entranceFee * 0.5;
        } else {
            revenue += entranceFee;
        }
    }
    return revenue;
}
