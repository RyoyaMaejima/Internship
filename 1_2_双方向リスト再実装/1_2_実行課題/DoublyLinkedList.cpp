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
DoublyLinkedList::ConstIterator::ConstIterator(Node* node, const DoublyLinkedList* list) : current(node), list(list) {}

/**
* @brief コピーコンストラクタ
* @param other 他のイテレータ
*/
DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current), list(other.list) {}

/**
 * @brief リストの先頭に向かって一つ進める
 */
void DoublyLinkedList::ConstIterator::operator--() {
    if (current) current = current->prev;
    else exit(1);
}

/**
 * @brief リストの先頭に向かって一つ進める
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int) {
    ConstIterator temp = *this;
    --(*this);
    return temp;
}

/**
 * @brief リストの末尾に向かって一つ進める
 */
void DoublyLinkedList::ConstIterator::operator++() {
    if (current) current = current->next;
    else exit(1);
}

/**
 * @brief リストの末尾に向かって一つ進める
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int) {
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief イテレータの指す要素を取得する
 * @return 成績データへの定数参照
 */
const ResultData& DoublyLinkedList::ConstIterator::operator*() const {
    if (current) return current->data;
    else exit(1);
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
DoublyLinkedList::Iterator::Iterator(Node* node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

/**
 * @brief イテレータの指す要素を取得する
 * @return データへの参照
 */
ResultData& DoublyLinkedList::Iterator::operator*() {
    if (current) return current->data;
    else exit(1);
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
 * @return 挿入が成功すればtrue、失敗すればfalse
 */
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

/**
 * @brief データの削除
 * @param iter 削除する位置のイテレータ
 * @return 削除が成功すればtrue、失敗すればfalse
 */
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

/**
 * @brief 先頭イテレータ取得
 * @return 先頭イテレータ
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetBegin() {
    return Iterator(head, this);
}

/**
 * @brief 先頭コンストイテレータ取得
 * @return 先頭コンストイテレータ
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetBegin() const {
    return ConstIterator(head, this);
}

/**
 * @brief 末尾イテレータ取得
 * @return 末尾イテレータ
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetEnd() {
    return Iterator(nullptr, this);
}

/**
 * @brief 末尾コンストイテレータ取得
 * @return 末尾コンストイテレータ
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEnd() const {
    return ConstIterator(nullptr, this);
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