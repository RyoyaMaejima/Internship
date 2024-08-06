#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::Node::Node(const T& rd) : data(rd), prev(nullptr), next(nullptr) {}

template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(Node* node, const DoublyLinkedList* list) : current(node), list(list) {}

template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current), list(other.list) {}

template<typename T>
void DoublyLinkedList<T>::ConstIterator::operator--() {
    if (current) current = current->prev;
    else exit(1);
}

template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator--(int) {
    ConstIterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
void DoublyLinkedList<T>::ConstIterator::operator++() {
    if (current) current = current->next;
    else exit(1);
}

template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator++(int) {
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
const T& DoublyLinkedList<T>::ConstIterator::operator*() const {
    if (current) return current->data;
    else exit(1);
}

template<typename T>
void  DoublyLinkedList<T>::ConstIterator::operator=(const ConstIterator& other) {
    current = other.current;
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node* node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

template<typename T>
T& DoublyLinkedList<T>::Iterator::operator*() {
    if (current) return current->data;
    else exit(1);
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), dataNum(0) {}

template<typename T>
int DoublyLinkedList<T>::GetDataNum() const {
    return dataNum;
}

template<typename T>
bool DoublyLinkedList<T>::Insert(const Iterator& iter, const T& data) {
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

template<typename T>
bool DoublyLinkedList<T>::Erase(const Iterator& iter) {
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

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::GetBegin() {
    return Iterator(head, this);
}

template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::GetBegin() const {
    return ConstIterator(head, this);
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::GetEnd() {
    return Iterator(nullptr, this);
}

template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::GetEnd() const {
    return ConstIterator(nullptr, this);
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
