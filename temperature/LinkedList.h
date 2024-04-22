# ifndef LINKEDLIST
# define LINKEDLIST

# include <iostream>
# include <string>
# include "Node.h"

class LinkedList {
	private:
		Node* head;
		Node* tail;

	public:
		LinkedList(); // default constructor
		~LinkedList(); // destructor
		LinkedList(const LinkedList& other); // copy constructor
		LinkedList& operator=(const LinkedList& other); // copy assignment
		void insert(std::string location, int year, int month, double temperature); // insert a record to the linked list
		void clear(); // clear the content of this linked list
		std::string print() const;
		Node* getHead() const;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);

# endif
