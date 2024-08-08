#pragma once

#include <functional>

/**
 * @brief �o�������X�g�N���X
 * @tparm T ���X�g�Ɋi�[����f�[�^�^
 */
template<typename T>
class DoublyLinkedList {
private:
    /**
     * @brief �m�[�h
     */
    struct Node {
        T data;  /**< �f�[�^ */
        Node* prev;       /**< �O�̃m�[�h�ւ̃|�C���^ */
        Node* next;       /**< ���̃m�[�h�ւ̃|�C���^ */

        /**
         * @brief �R���X�g���N�^
         * @param rd �i�[����f�[�^
         */
        Node(const T& rd);
    };

    Node* head;  /**< ���X�g�̐擪 */
    Node* tail;  /**< ���X�g�̖��� */
    int dataNum;    /**< �f�[�^�� */

public:
    /**
     * @brief �o�������X�g�̒萔�C�e���[�^�N���X
     */
    class ConstIterator {
    public:
        Node* current;  /**< ���݂̃m�[�h */
        const DoublyLinkedList* list; /**< �������X�g�ւ̃|�C���^ */

        /**
         * @brief �R���X�g���N�^
         * @param node ���݂̃m�[�h
         * @param list �������郊�X�g
         */
        ConstIterator(Node* node, const DoublyLinkedList* list);

        /**
         * @brief �R�s�[�R���X�g���N�^
         * @param other ���̃C�e���[�^
         */
        ConstIterator(const ConstIterator& other);

        /**
         * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        ConstIterator& operator--();

        /**
        * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
        * @return �f�[�^�ւ̎Q��
        */
        ConstIterator operator--(int);

        /**
         * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        ConstIterator& operator++();

        /**
         * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        ConstIterator operator++(int);

        /**
         * @brief �C�e���[�^�̎w���v�f���擾����
         * @return �f�[�^�ւ̒萔�Q��
         */
        const T& operator*() const;

        /**
         * @brief ������s��
         * @param other ���̃C�e���[�^
         */
        void operator=(const ConstIterator& other);

        /**
         * @brief ���ꂩ��r����
         * @param other ��r�Ώۂ̃C�e���[�^
         * @return ����Ȃ�true�A�قȂ��false
         */
        bool operator==(const ConstIterator& other) const;

        /**
         * @brief �قȂ邩��r����
         * @param other ��r�Ώۂ̃C�e���[�^
         * @return �قȂ��true�A����Ȃ�false
         */
        bool operator!=(const ConstIterator& other) const;
    };

    /**
     * @brief �o�������X�g�̃C�e���[�^�N���X
     */
    class Iterator : public ConstIterator {
    public:
        /**
         * @brief �R���X�g���N�^
         * @param node ���݂̃m�[�h
         * @param list �������郊�X�g
         */
        Iterator(Node* node, const DoublyLinkedList* list);

        /**
         * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        Iterator& operator--();

        /**
        * @brief ���X�g�̐擪�Ɍ������Ĉ�i�߂�
        * @return �f�[�^�ւ̎Q��
        */
        Iterator operator--(int);

        /**
         * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        Iterator& operator++();

        /**
         * @brief ���X�g�̖����Ɍ������Ĉ�i�߂�
         * @return �f�[�^�ւ̎Q��
         */
        Iterator operator++(int);

        /**
         * @brief �C�e���[�^�̎w���v�f���擾����
         * @return �f�[�^�ւ̎Q��
         */
        T& operator*();
    };

    /**
     * @brief �R���X�g���N�^
     */
    DoublyLinkedList();

    /**
     * @brief �f�[�^���̎擾
     * @return �f�[�^��
     */
    int GetDataNum() const;

    /**
     * @brief �f�[�^�̑}��
     * @param iter �}���ʒu�̃C�e���[�^
     * @tparam data �}������f�[�^
     * @return �}�������������true�A�ʂ̃��X�g�̃C�e���[�^���w�肷���false
     */
    bool Insert(const Iterator& iter, const T& data);

    /**
     * @brief �f�[�^�̍폜
     * @param iter �폜����ʒu�̃C�e���[�^
     * @return �폜�����������true�A�C�e���[�^��null�܂��͕ʂ̃��X�g�̃C�e���[�^���w�肷���false
     */
    bool Erase(const Iterator& iter);

    /**
     * @brief ���X�g�̐擪�C�e���[�^���擾����
     * @return �擪�C�e���[�^
     */
    Iterator GetBegin();

    /**
     * @brief �擪�R���X�g�C�e���[�^�擾
     * @return �擪�R���X�g�C�e���[�^
     */
    ConstIterator GetBeginConst() const;

    /**
     * @brief �I�[�C�e���[�^�擾
     * @return �I�[�C�e���[�^
     */
    Iterator GetEnd();

    /**
     * @brief �I�[�R���X�g�C�e���[�^�擾
     * @return �I�[�R���X�g�C�e���[�^
     */
    ConstIterator GetEndConst() const;

    /**
     * @brief �f�X�g���N�^
     */
    ~DoublyLinkedList();
};

#include "DoublyLinkedList.inl"
