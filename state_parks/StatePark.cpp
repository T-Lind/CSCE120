# include "Passport.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list

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
    camperLog.push_back(camper);

}

double StatePark::getRevenue() {
	// TODO: (optional) implement function
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
