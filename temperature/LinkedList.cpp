# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"
#include <sstream>
#include <cmath>

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr){
	// TODO: implement this function

}

LinkedList::~LinkedList() {
	// TODO: implement this function
    clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// TODO: implement this function
    // Copy the source linked list
    Node* current = source.head;
    while (current != nullptr) {
        insert(current->data.id, current->data.year, current->data.month, current->data.temperature);
        current = current->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
    // Clear the current linked list
    clear();
    // Copy the source linked list
    Node* current = source.head;
    while (current != nullptr) {
        insert(current->data.id, current->data.year, current->data.month, current->data.temperature);
        current = current->next;
    }
    return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
    // Create a new node
    Node* newNode = new Node(location, year, month, temperature);
    // If the linked list is empty, set the head to the new node
    if (head == nullptr) {
        head = newNode;
    } else {
        // Find the correct position to insert the new node
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data < newNode->data) {
            previous = current;
            current = current->next;
        }
        // Insert the new node
        if (previous == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            previous->next = newNode;
            newNode->next = current;
        }
    }
}

void LinkedList::clear() {
	// TODO: implement this function
    // Go through and delete each node
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
    return head;
}
string LinkedList::print() const {
    std::ostringstream outputString;

    // Go through and print each node
    Node* current = head;
    while (current != nullptr) {
        outputString << current->data.id << " " << current->data.year << " " << current->data.month << " ";
        // Manually format the temperature to one digit after the decimal point
        double roundedTemperature = round(current->data.temperature * 10) / 10;
        outputString << roundedTemperature << "\n";
        current = current->next;
    }

    return outputString.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
