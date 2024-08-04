#include "pch.h"
#include "DoublyLinkedList.h"

/**
 * @brief ノードのコンストラクタ
 * @param rd 格納するデータ
 */
DoublyLinkedList::Node::Node(const ResultData& rd) : data(rd), prev(nullptr), next(nullptr) {}

/**
 * @brief ConstIteratorクラスのコンストラクタ
 * @param node 現在のノード
 */
DoublyLinkedList::ConstIterator::ConstIterator(Node* node) : current(node) {}

/**
* @brief コピーコンストラクタ
* @param other 他のイテレータ
*/
DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current) {}

/**
 * @brief リストの先頭に向かって一つ進める
 */
void DoublyLinkedList::ConstIterator::operator--() {
    if (current) current = current->prev;
    else throw std::exception();
}

/**
 * @brief リストの末尾に向かって一つ進める
 */
void DoublyLinkedList::ConstIterator::operator++() {
    if (current) current = current->next;
    else throw std::exception();
}

/**
 * @brief イテレータの指す要素を取得する
 * @return 成績データへの定数参照
 */
const ResultData& DoublyLinkedList::ConstIterator::operator*() const {
    if (!current) throw std::exception();
    return current->data;
}

/**
 * @brief 代入を行う
 * @return 他のイテレータ
 */
void  DoublyLinkedList::ConstIterator::operator=(const ConstIterator& other) {
    current = other.current;
}

/**
 * @brief 同一か比較する
 * @param other 比較対象のイテレータ
 * @return 同一ならtrue、異なればfalse
 */
bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}

/**
 * @brief 異なるか比較する
 * @param other 比較対象のイテレータ
 * @return 異なればtrue、同一ならfalse
 */
bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

/**
 * @brief Iteratorクラスのコンストラクタ
 * @param node 現在のノード
 */
DoublyLinkedList::Iterator::Iterator(Node* node) : ConstIterator(node) {}

/**
 * @brief イテレータの指す要素を取得する
 * @return データへの参照
 */
ResultData& DoublyLinkedList::Iterator::operator*() {
    return this->current->data;
}

/**
 * @brief コンストラクタ
 */
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), dataNum(0) {}

/**
 * @brief データ数の取得
 * @return データ数
 */
int DoublyLinkedList::GetDataNum() const {
    return dataNum;
}

/**
 * @brief データの挿入
 * @param iter 挿入位置のイテレータ
 * @param data 挿入するデータ
 */
bool DoublyLinkedList::Insert(const Iterator& iter, const ResultData& data) {
    Node* newNode = new Node(data);
    Node* current = iter.current;

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

/**
 * @brief データの削除
 * @param iter 削除する位置のイテレータ
 */
bool DoublyLinkedList::Erase(const Iterator& iter) {
    Node* current = iter.current;

    if (current == nullptr) return false;

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

/**
* @brief データの中身の表示
*/
void DoublyLinkedList::PrintList() const {
    Node* current = head;

    while (current) {
        std::cout << current->data.score << "\t" << current->data.username << std::endl;
        current = current->next;
    }
}

/**
 * @brief 先頭イテレータ取得
 * @return 先頭イテレータ
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetBegin() {
    return Iterator(head);
}

/**
 * @brief 先頭コンストイテレータ取得
 * @return 先頭コンストイテレータ
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetBegin() const {
    return ConstIterator(head);
}

/**
 * @brief 末尾イテレータ取得
 * @return 末尾イテレータ
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetEnd() {
    return Iterator(nullptr);
}

/**
 * @brief 末尾コンストイテレータ取得
 * @return 末尾コンストイテレータ
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEnd() const {
    return ConstIterator(nullptr);
}

/**
 * @brief デストラクタ
 */
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}