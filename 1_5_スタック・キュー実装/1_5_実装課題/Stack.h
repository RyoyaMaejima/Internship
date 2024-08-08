#include "DoublyLinkedList.h"

/**
 * @brief �X�^�b�N����������N���X
 * @tparam T �X�^�b�N�Ɋi�[����f�[�^�^
 */
template<typename T>
class Stack {
private:
    DoublyLinkedList<T> list;

public:
    using ConstIterator = typename DoublyLinkedList<T>::ConstIterator;
    using Iterator = typename DoublyLinkedList<T>::Iterator;

    /**
     * @brief �X�^�b�N�̃f�[�^�����擾����
     * @return �f�[�^��
     */
    int GetDataNum() const;

    /**
     * @brief �X�^�b�N�Ƀf�[�^���v�b�V������
     * @param data �v�b�V������f�[�^
     * @return �v�b�V�������������true�A���s�����false
     */
    bool push(const T& data);

    /**
     * @brief �X�^�b�N����f�[�^���|�b�v����
     * @return �|�b�v�����������true�A���X�g���󂾂�false
     */
    bool pop();

    /**
     * @brief �X�^�b�N�̐擪�C�e���[�^���擾����
     * @return �擪�C�e���[�^
     */
    Iterator GetBegin();

    /**
     * @brief �X�^�b�N�̐擪�R���X�g�C�e���[�^���擾����
     * @return �擪�R���X�g�C�e���[�^
     */
    ConstIterator GetBeginConst() const;

    /**
     * @brief �X�^�b�N�̏I�[�C�e���[�^���擾����
     * @return �I�[�C�e���[�^
     */
    Iterator GetEnd();

    /**
     * @brief �X�^�b�N�̏I�[�R���X�g�C�e���[�^���擾����
     * @return �I�[�R���X�g�C�e���[�^
     */
    ConstIterator GetEndConst() const;
};

#include "Stack.inl"