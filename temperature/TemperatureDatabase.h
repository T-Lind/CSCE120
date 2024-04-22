# ifndef TEMP_DB
# define TEMP_DB

# include <string>
# include "LinkedList.h"

class TemperatureDatabase {
	public:
		TemperatureDatabase();
		~TemperatureDatabase();
		void loadData(const std::string& data_file);
		void outputData(const std::string& out_file);
		void performQuery(const std::string& query_filename);

	private:
		LinkedList records;
};

# endif
