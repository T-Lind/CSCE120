# ifndef _PASSPORT_H
# define _PASSPORT_H

# include "StatePark.h"

class Passport {
	private:
		std::string camperName;
		bool isJuniorPassport;

    double getMilesHiked();

	public:
		Passport(std::string camperName, bool isJuniorPassport);
		std::string getCamperName();
		bool checkJuniorPassport();
		void addParkVisited(StatePark* park);
		int getHikerLevel();

		StatePark* getParkAt(unsigned int i) { return parksVisited.at(i); }

    std::vector<StatePark*> parksVisited;
};

# endif
