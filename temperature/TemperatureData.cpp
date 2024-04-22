# include "TemperatureData.h"
using std::string;
TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0.0) {}

TemperatureData::TemperatureData(string id, int year, int month, double temperature)
    : id(id), year(year), month(month), temperature(temperature) {}

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