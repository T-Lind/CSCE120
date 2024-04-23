
# include "linked_list.h"
# include <iostream>
# include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string &name, int score) {
    MyNode *newNode = new MyNode(name, score);
    if (_head == nullptr) {
        _head = newNode;
        _tail = newNode;
        _size++;
        return;
    }

    _tail->next = newNode;
    _tail = newNode;
    _size++;
}

void MyList::clear() {
    // TODO
    MyNode *current = _head;
    while (current != nullptr) {
        MyNode *next = current->next;
        delete current;
        current = next;
    }
    _head = nullptr;
    _tail = nullptr;
    _size = 0;

}

bool MyList::remove(const std::string &name) {
    // TODO
    MyNode *current = _head;
    MyNode *prev = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (prev == nullptr) {
                _head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            _size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

bool MyList::insert(const std::string &name, int score, size_t index) {
    if (index > _size) {
        return false;
    }

    MyNode *newNode = new MyNode(name, score);

    if (index == 0) {
        newNode->next = _head;
        newNode->prev = nullptr;
        if (_head != nullptr) {
            _head->prev = newNode;
        }
        _head = newNode;
        _size++;
        return true;
    }

    MyNode *current = _head;
    size_t i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    _size++;
    return true;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode *MyList::head() const {
    return _head;
}

MyList::MyList(const MyList &other) : _size(other._size), _head(nullptr), _tail(nullptr) {
    MyNode *current = other._head;
    while (current != nullptr) {
        add(current->name, current->score);
        current = current->next;
    }
}

MyList &MyList::operator=(const MyList &other) {
    if (this == &other) {
        return *this;
    }

    clear();
    _size = other._size;
    _head = nullptr;
    _tail = nullptr;

    MyNode *current = other._head;
    while (current != nullptr) {
        add(current->name, current->score);
        current = current->next;
    }

    return *this;
}

ostream &operator<<(ostream &os, const MyList &myList) {
    MyNode *_current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }

    return os;
}

MyNode::MyNode(const std::string &name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}

MyNode::MyNode(const MyNode &other) : name(other.name), score(other.score), next(other.next), prev(other.prev) {}

MyNode &MyNode::operator=(const MyNode &other) {
    if (this == &other) {
        return *this;
    }

    name = other.name;
    score = other.score;
    next = other.next;
    prev = other.prev;

    return *this;
}
