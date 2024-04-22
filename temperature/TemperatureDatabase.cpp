# include "TemperatureDatabase.h"
# include <fstream>
#include <sstream>
#include <cmath>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
    std::ifstream dataIn(filename);
    if (!dataIn.is_open()) {
        std::cout << "Error: Unable to open " << filename << std::endl;
        exit(1);
    }

    string id;
    int year, month;
    double temperature;
    string line;
    while (getline(dataIn, line)) {
        std::istringstream iss(line);
        if (!(iss >> id >> year >> month >> temperature)) {
            std::cout << "Error: Other invalid input" << std::endl;
            continue;
        }
        if (year < 1800 || year > 2024) {
            std::cout << "Error: Invalid year " << year << std::endl;
            continue;
        }
        if (month < 1 || month > 12) {
            std::cout << "Error: Invalid month " << month << std::endl;
            continue;
        }
        if (temperature < -50.0 || temperature > 50.0) {
            std::cout << "Error: Invalid temperature " << temperature << std::endl;
            continue;
        }

        // If no errors, insert the data into the linked list
        records.insert(id, year, month, temperature);
    }
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

double LinkedList::calculateAverage(const std::string& id, int year1, int year2) {
    Node* current = head;
    double sum = 0.0;
    int count = 0;

    while (current != nullptr) {
        if (current->data.id == id && current->data.year >= year1 && current->data.year <= year2) {
            sum += current->data.temperature;
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        return -99.99; // Return -99.99 if no data is available
    } else {
        return sum / count;
    }
}

int LinkedList::calculateMode(const std::string& id, int year1, int year2) {
    int frequency[101] = {0}; // Array to store the frequency of temperatures from -50 to 50
    Node* current = head;

    while (current != nullptr) {
        if (current->data.id == id && current->data.year >= year1 && current->data.year <= year2) {
            int temp = round(current->data.temperature);
            frequency[temp + 50]++; // Add 50 to handle negative temperatures
        }
        current = current->next;
    }

    int maxFreq = 0;
    int mode = -99;
    for (int i = 0; i < 101; i++) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            mode = i - 50; // Subtract 50 to get the original temperature
        }
    }

    if (maxFreq == 0) {
        return -99; // Return -99 if no data is available
    } else {
        return mode;
    }
}

void TemperatureDatabase::performQuery(const string& filename) {
    std::ifstream queryIn(filename);
    if (!queryIn.is_open()) {
        std::cout << "Error: Unable to open " << filename << std::endl;
        exit(1);
    }

    std::ofstream resultOut("result.dat");
    if (!resultOut.is_open()) {
        std::cout << "Error: Unable to open result.dat" << std::endl;
        exit(1);
    }

    string id, queryType;
    int year1, year2;
    string line;
    while (getline(queryIn, line)) {
        std::istringstream iss(line);
        if (!(iss >> id >> queryType >> year1 >> year2)) {
            std::cout << "Error: Other invalid query" << std::endl;
            continue;
        }

        if (queryType == "AVG") {
            double avg = records.calculateAverage(id, year1, year2);
            if (avg == -99.99) {
                resultOut << id << " " << year1 << " " << year2 << " AVG unknown\n";
            } else {
                resultOut << id << " " << year1 << " " << year2 << " AVG " << avg << "\n";
            }
        } else if (queryType == "MODE") {
            int mode = records.calculateMode(id, year1, year2);
            if (mode == -99) {
                resultOut << id << " " << year1 << " " << year2 << " MODE unknown\n";
            } else {
                resultOut << id << " " << year1 << " " << year2 << " MODE " << mode << "\n";
            }
        } else {
            std::cout << "Error: Unsupported query " << queryType << std::endl;
        }
    }

    queryIn.close();
    resultOut.close();
}
