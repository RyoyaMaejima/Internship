#include "pch.h"
#include "DoublyLinkedList.h"

/**
 * @brief �m�[�h�̃R���X�g���N�^
 * @param rd �i�[����f�[�^
 */
DoublyLinkedList::Node::Node(const ResultData& rd) : data(rd), prev(nullptr), next(nullptr) {}

/**
 * @brief ConstIterator�N���X�̃R���X�g���N�^
 * @param node ���݂̃m�[�h
 */
DoublyLinkedList::ConstIterator::ConstIterator(Node* node) : current(node) {}

/**
* @brief �R�s�[�R���X�g���N�^
* @param other ���̃C�e���[�^
*/
DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current) {}

/**
 * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
 */
void DoublyLinkedList::ConstIterator::operator--() {
    if (current) current = current->prev;
    else throw std::exception();
}

/**
 * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
 */
void DoublyLinkedList::ConstIterator::operator++() {
    if (current) current = current->next;
    else throw std::exception();
}

/**
 * @brief �C�e���[�^�̎w���v�f���擾����
 * @return ���уf�[�^�ւ̒萔�Q��
 */
const ResultData& DoublyLinkedList::ConstIterator::operator*() const {
    if (!current) throw std::exception();
    return current->data;
}

/**
 * @brief ������s��
 * @return ���̃C�e���[�^
 */
void  DoublyLinkedList::ConstIterator::operator=(const ConstIterator& other) {
    current = other.current;
}

/**
 * @brief ���ꂩ��r����
 * @param other ��r�Ώۂ̃C�e���[�^
 * @return ����Ȃ�true�A�قȂ��false
 */
bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}

/**
 * @brief �قȂ邩��r����
 * @param other ��r�Ώۂ̃C�e���[�^
 * @return �قȂ��true�A����Ȃ�false
 */
bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

/**
 * @brief Iterator�N���X�̃R���X�g���N�^
 * @param node ���݂̃m�[�h
 */
DoublyLinkedList::Iterator::Iterator(Node* node) : ConstIterator(node) {}

/**
 * @brief �C�e���[�^�̎w���v�f���擾����
 * @return �f�[�^�ւ̎Q��
 */
ResultData& DoublyLinkedList::Iterator::operator*() {
    return this->current->data;
}

/**
 * @brief �R���X�g���N�^
 */
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), dataNum(0) {}

/**
 * @brief �f�[�^���̎擾
 * @return �f�[�^��
 */
int DoublyLinkedList::GetDataNum() const {
    return dataNum;
}

/**
 * @brief �f�[�^�̑}��
 * @param iter �}���ʒu�̃C�e���[�^
 * @param data �}������f�[�^
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
 * @brief �f�[�^�̍폜
 * @param iter �폜����ʒu�̃C�e���[�^
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
* @brief �f�[�^�̒��g�̕\��
*/
void DoublyLinkedList::PrintList() const {
    Node* current = head;

    while (current) {
        std::cout << current->data.score << "\t" << current->data.username << std::endl;
        current = current->next;
    }
}

/**
 * @brief �擪�C�e���[�^�擾
 * @return �擪�C�e���[�^
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetBegin() {
    return Iterator(head);
}

/**
 * @brief �擪�R���X�g�C�e���[�^�擾
 * @return �擪�R���X�g�C�e���[�^
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetBegin() const {
    return ConstIterator(head);
}

/**
 * @brief �����C�e���[�^�擾
 * @return �����C�e���[�^
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetEnd() {
    return Iterator(nullptr);
}

/**
 * @brief �����R���X�g�C�e���[�^�擾
 * @return �����R���X�g�C�e���[�^
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEnd() const {
    return ConstIterator(nullptr);
}

/**
 * @brief �f�X�g���N�^
 */
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}