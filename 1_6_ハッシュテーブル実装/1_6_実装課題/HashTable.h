#pragma once

#include "DoublyLinkedList.h"
#include "Pair.h"

/**
 * @brief �`�F�C�����n�b�V���e�[�u���N���X
 * @tparam K �L�[�̌^
 * @tparam V �l�̌^
 * @tparam HF �n�b�V���֐��̌^
 * @tparam BucketSize �n�b�V���e�[�u���̃o�P�b�g�T�C�Y
 */
template<typename K, typename V, typename HF, size_t BucketSize>
class HashTable {
private:
    DoublyLinkedList<Pair<K, V>> table[BucketSize];    /**< �`�F�C�����n�b�V���e�[�u�� */
    HF hashFunction;    /**< �n�b�V���֐� */
    size_t dataNum;    /**< �f�[�^�� */

public:
    /**
     * @brief �R���X�g���N�^
     */
    HashTable();

    /**
     * @brief �f�[�^���̎擾
     * @return �f�[�^��
     */
    size_t GetDataNum() const;

    /**
     * @brief �L�[�ƒl�̃y�A���n�b�V���e�[�u���ɑ}������
     * @param key �L�[
     * @param value �l
     * @return �}�������������true�A�L�[���d�������false
     */
    bool Insert(const K& key, const V& value);

    /**
     * @brief �L�[�ɑΉ�����l���폜����
     * @param key �L�[
     * @return �폜�����������true�A�L�[�����݂��Ȃ���false
     */
    bool Erase(const K& key);

    /**
     * @brief �L�[�ɑΉ�����l����������
     * @param key �L�[
     * @param value �T�������l���i�[����ϐ�
     * @return �L�[���������true�A������Ȃ����false
     */
    bool Search(const K& key, V& value) const;
};

#include "HashTable.inl"