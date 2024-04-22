# ifndef NODE
# define NODE

# include "TemperatureData.h"

struct Node {
	public:
		TemperatureData data;
		Node* next;

		Node();
		Node(std::string id, int year, int month, double temperature);
		bool operator<(const Node& b);
		virtual ~Node() {}
};

# endif
