#include "DoublyLinkedList.h"

/**
 * @brief �L���[����������N���X
 * @tparam T �L���[�Ɋi�[����f�[�^�^
 */
template<typename T>
class Queue {
private:
    DoublyLinkedList<T> list;

public:
    /**
     * @brief �f�[�^���̎擾
     * @return �f�[�^��
     */
    int GetDataNum() const;

    /**
     * @brief �L���[�Ƀf�[�^���G���L���[����
     * @param data �G���L���[����f�[�^
     * @return �G���L���[�����������true�A���s�����false
     */
    bool enqueue(const T& data);

    /**
     * @brief �L���[����f�[�^���f�L���[����
     * @return �f�L���[�����������true�A���X�g���󂾂�false
     */
    bool dequeue();
};

#include "Queue.inl"
