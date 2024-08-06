#include "DoublyLinkedList.h"

DoublyLinkedList::Node::Node(const ResultData& rd) : data(rd), prev(nullptr), next(nullptr) {}

DoublyLinkedList::ConstIterator::ConstIterator(Node* node, const DoublyLinkedList* list) : current(node), list(list) {}

DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current), list(other.list) {}

void DoublyLinkedList::ConstIterator::operator--() {
    if (current) current = current->prev;
    else exit(1);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int) {
    ConstIterator temp = *this;
    --(*this);
    return temp;
}

void DoublyLinkedList::ConstIterator::operator++() {
    if (current) current = current->next;
    else exit(1);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int) {
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}

const ResultData& DoublyLinkedList::ConstIterator::operator*() const {
    if (current) return current->data;
    else exit(1);
}

void  DoublyLinkedList::ConstIterator::operator=(const ConstIterator& other) {
    current = other.current;
}

bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}

bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

DoublyLinkedList::Iterator::Iterator(Node* node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

ResultData& DoublyLinkedList::Iterator::operator*() {
    if (current) return current->data;
    else exit(1);
}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), dataNum(0) {}

int DoublyLinkedList::GetDataNum() const {
    return dataNum;
}

bool DoublyLinkedList::Insert(const Iterator& iter, const ResultData& data) {
    Node* newNode = new Node(data);
    Node* current = iter.current;

    if (iter.list != this) return false;

    if (current == nullptr) {
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    else {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        }
        else {
            head = newNode;
        }
        current->prev = newNode;
    }

    dataNum++;

    return true;
}

bool DoublyLinkedList::Erase(const Iterator& iter) {
    Node* current = iter.current;

    if (current == nullptr || iter.list != this) return false;

    if (current->prev) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    delete current;
    dataNum--;

    return true;
}

DoublyLinkedList::Iterator DoublyLinkedList::GetBegin() {
    return Iterator(head, this);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetBegin() const {
    return ConstIterator(head, this);
}

DoublyLinkedList::Iterator DoublyLinkedList::GetEnd() {
    return Iterator(nullptr, this);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetEnd() const {
    return ConstIterator(nullptr, this);
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
