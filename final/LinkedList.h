//
// Created by tenant on 4/30/2024.
//

#ifndef CSCE120_LINKEDLIST_H
#define CSCE120_LINKEDLIST_H

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {

public:
    LinkedList() : head{nullptr} {}

    LinkedList(int *init, int size) {
        for (int i = 0; i < size; i++) {
            this->insertAtEnd(init[i]);
        }
    }

    LinkedList(const LinkedList &other) : head{nullptr} {
        if (other.head) {
            head = new Node(other.head->value);
            Node *current = head;
            Node *otherCurrent = other.head->next;
            while (otherCurrent) {
                current->next = new Node(otherCurrent->value);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    LinkedList &operator=(const LinkedList &other) {
        if (this != &other) {
            clear();
            if (other.head) {
                head = new Node(other.head->value);
                Node *current = head;
                Node *otherCurrent = other.head->next;
                while (otherCurrent) {
                    current->next = new Node(otherCurrent->value);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    ~LinkedList() {
        clear();
    }

    void insertAtBeginning(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr) { current = current->next; }
            current->next = newNode;
        }
    }

    void remove(int value) {
        if (head == nullptr) { return; }
        if (head->value == value) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next && current->next->value != value) {
            current = current->next;
        }
        if (current->next) {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void reverse() {
        Node *prev = nullptr;
        Node *current = head;
        Node *next;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    bool detectCycle(){
        vector<Node*> visited;

        Node *current = head;
        while(current != nullptr){
            for(Node* node : visited){
                if(node == current){
                    return true;
                }
            }
            visited.push_back(current);
            current = current->next;
        }
        return false;
    }

    void clear() {
        Node *current = head;
        while (current) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void print() const {
        Node *current = head;
        if (head == nullptr)
            return;
        cout << "printing" << endl;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node *head = nullptr;
};


#endif //CSCE120_LINKEDLIST_H
