//
// Created by tenant on 4/18/2024.
//

#ifndef CSCE120_LIST_H
#define CSCE120_LIST_H

#include<string>
#include<iostream>

using namespace std;

class listNode {
private:
    string data;
    listNode *next;
    listNode *prev;

public:
    listNode() :
            data(""),
            next(nullptr),
            prev(nullptr) {}

    listNode(string data) :
            data(data),
            next(nullptr),
            prev(nullptr) {}

    listNode(const listNode &copy) :
            data(copy.data),
            next(copy.next),
            prev(copy.prev) {}

    listNode &operator=(const listNode &copy) {
        if (this != &copy) {
            this->data = copy.data;
            this->next = copy.next;
            this->prev = copy.next;
        }
        return *this;
    }

    ~listNode() {
    }

    friend class list;

};

class list {
private:
    listNode *head;
    listNode *tail;

public:
    list() : head(nullptr), tail(nullptr) {
    }

    list(const list &to_be_copied) : head(nullptr), tail(nullptr) {
        if (to_be_copied.head != nullptr) {
            this->head = new listNode(to_be_copied.head->data);
            listNode *this_next = this->head;
            listNode *copy_next = to_be_copied.head;

            copy_next = to_be_copied.head->next;
            while (copy_next) {
                this_next->next = new listNode(copy_next->data);
                copy_next = copy_next->next;
                this_next = this_next->next;
            }
        }
    }

    list &operator=(const list &to_be_copied) {
        if (this != &to_be_copied) {
            while (head) {
                listNode *next = head->next;
                delete head;
                head = next;
            }
            head = nullptr;
        }

        if (to_be_copied.head != nullptr) {
            this->head = new listNode(to_be_copied.head->data);
            listNode *this_next = this->head;
            listNode *copy_next = to_be_copied.head;

            copy_next = to_be_copied.head->next;
            copy_next = to_be_copied.head->next;
            while (copy_next) {
                this_next->next = new listNode(copy_next->data);
                copy_next = copy_next->next;
                this_next = this_next->next;
            }
        }

        return *this;
    }

    ~list() {
        cout << "In list destructor" << endl;
        while (head) {
            listNode *temp = head->next;
            delete head;
            head = temp;
        }
    }

    void prepend(string data) {
        listNode *newNode = new listNode(data); // create a new node
        if (head == NULL) { // if the list is empty
            head = newNode; // set the head to the new node
            tail = newNode; // set the tail to the new node
        } else { // if the list is not empty
            head->prev = newNode; // link the head to the new node
            newNode->next = head; // link the new node to the head
            head = newNode; // set the head to the new node
        }

        // insertAfter(nullptr, dataValue);
    }

    string pop() {
        string data = head->data;

        listNode *temp = head;
        head = head->next;
        delete temp;

        return data;
    }

    void insertAfter(listNode *insertAfterNode, string data) { // O(1)
        if (insertAfterNode == nullptr) {
            insertAfterNode = head;
        }
        listNode *to_be_inserted = new listNode(data);
        to_be_inserted->next = insertAfterNode->next;
        insertAfterNode->next = to_be_inserted;
    }

    void deleteAfter(listNode *deleteAfterNode) {  // O(1)
        if (deleteAfterNode != nullptr) {
            listNode *temp = deleteAfterNode->next;
            deleteAfterNode->next = deleteAfterNode->next->next;
            delete temp;
        }
    }

    void deleteGivenNode(listNode *node) {   // O(n)
        if (node == head) { // if the given node is the head
            listNode *temp = head; // store the head node in a temporary variable
            head = head->next; // set the head to the next node
            head->prev = NULL; // unlink the head from the previous node
            delete temp; // delete the temporary node
        } else if (node == tail) { // if the given node is the tail
            listNode *temp = tail; // store the tail node in a temporary variable
            tail = tail->prev; // set the tail to the previous node
            tail->next = NULL; // unlink the tail from the next node
            delete temp; // delete the temporary node
        } else { // if the given node is neither the head nor the tail
            node->prev->next = node->next; // link the previous node of the given node to the next node of the given node
            node->next->prev = node->prev; // link the next node of the given node to the previous node of the given node
            delete node; // delete the given node
        }
    }

    void print() {
        for (listNode *temp = head; temp != nullptr; temp = temp->next) {
            cout << temp->data << endl;
        }
    }

    listNode *find(const string& string_to_find) {
        for (listNode *searchNode = head; searchNode != nullptr; searchNode = searchNode->next) {
            if (searchNode->data == string_to_find) {
                return searchNode;
            }
        }
        return nullptr;
    }

    void insertBefore(listNode *node, string data) {
        // link the given node to the new node

    }
};


#endif //CSCE120_LIST_H
