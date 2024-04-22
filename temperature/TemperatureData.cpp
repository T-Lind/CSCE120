# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() /* TODO */ {
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) /* TODO */ {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) const {
    if (id < b.id) return true;
    if (id > b.id) return false;
    if (year < b.year) return true;
    if (year > b.year) return false;
    if (month < b.month) return true;
    if (month > b.month) return false;
    return false;
}