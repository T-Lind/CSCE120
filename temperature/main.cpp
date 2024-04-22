# include "TemperatureDatabase.h"
# include <iostream>

using std::cout, std::endl;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		database.outputData(argv[1]); // comment out before submitting Part 2
		database.performQuery(argv[2]); // will be done in Part 2
	}
}
