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
     * @param data �|�b�v�����f�[�^���i�[����ϐ�
     * @return �|�b�v�����������true�A���X�g���󂾂�false
     */
    bool pop(T& data);
};

#include "Stack.inl"