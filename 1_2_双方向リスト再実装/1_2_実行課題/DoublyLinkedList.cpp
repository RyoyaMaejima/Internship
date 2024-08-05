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
DoublyLinkedList::ConstIterator::ConstIterator(Node* node, const DoublyLinkedList* list) : current(node), list(list) {}

/**
* @brief �R�s�[�R���X�g���N�^
* @param other ���̃C�e���[�^
*/
DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& other) : current(other.current), list(other.list) {}

/**
 * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
 */
void DoublyLinkedList::ConstIterator::operator--() {
    if (current) current = current->prev;
    else exit(1);
}

/**
 * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int) {
    ConstIterator temp = *this;
    --(*this);
    return temp;
}

/**
 * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
 */
void DoublyLinkedList::ConstIterator::operator++() {
    if (current) current = current->next;
    else exit(1);
}

/**
 * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int) {
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief �C�e���[�^�̎w���v�f���擾����
 * @return ���уf�[�^�ւ̒萔�Q��
 */
const ResultData& DoublyLinkedList::ConstIterator::operator*() const {
    if (current) return current->data;
    else exit(1);
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
DoublyLinkedList::Iterator::Iterator(Node* node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

/**
 * @brief �C�e���[�^�̎w���v�f���擾����
 * @return �f�[�^�ւ̎Q��
 */
ResultData& DoublyLinkedList::Iterator::operator*() {
    if (current) return current->data;
    else exit(1);
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
 * @return �}�������������true�A���s�����false
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
 * @brief �f�[�^�̍폜
 * @param iter �폜����ʒu�̃C�e���[�^
 * @return �폜�����������true�A���s�����false
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
 * @brief �擪�C�e���[�^�擾
 * @return �擪�C�e���[�^
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetBegin() {
    return Iterator(head, this);
}

/**
 * @brief �擪�R���X�g�C�e���[�^�擾
 * @return �擪�R���X�g�C�e���[�^
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetBegin() const {
    return ConstIterator(head, this);
}

/**
 * @brief �����C�e���[�^�擾
 * @return �����C�e���[�^
 */
DoublyLinkedList::Iterator DoublyLinkedList::GetEnd() {
    return Iterator(nullptr, this);
}

/**
 * @brief �����R���X�g�C�e���[�^�擾
 * @return �����R���X�g�C�e���[�^
 */
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEnd() const {
    return ConstIterator(nullptr, this);
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