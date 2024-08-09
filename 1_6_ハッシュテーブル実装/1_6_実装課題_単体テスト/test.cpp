#include "pch.h"
#include "HashTable.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        std::string key = "User";
        std::string key1 = "User1";
        std::string sameKey = "Same";
        int value = 100;
        int value1 = 200;
        int sValue;

        struct HashFunction {
            size_t operator()(const std::string& key) const {
                return key.length() % 10;
            }
        };

        struct HashFunction1 {
            size_t operator()(const std::string& key) const {
                return key.length() % 2;
            }
        };

        struct InvalidHashFunction {
            void operator()(const std::string& key) const {
                return;
            }
        };

        //=================================== �N���X�̋��� ===================================

        /**********************************************************************************//**
            @brief		�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ���̋���
            @details	ID:-0(�蓮)\n
                        �s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ���̋������m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTableInvalid)
        {
#if defined TT_TEST_MANUAL
            HashTable<std::string, int, InvalidHashFunction, 10> table;
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief		�Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̋���
            @details	ID:-1\n
                        �Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̋������m�F���Ă��܂��B\n
                        �}���A�T���A�폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTable)
        {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
            success = table.Search(key, sValue);
            EXPECT_TRUE(success);
            success = table.Erase(key);
            EXPECT_TRUE(success);

            HashTable<std::string, int, HashFunction1, 10> table1;
            success = table1.Insert(key, value);
            EXPECT_TRUE(success);
            success = table1.Search(key, sValue);
            EXPECT_TRUE(success);
            success = table1.Erase(key);
            EXPECT_TRUE(success);
        }

        //=================================== �f�[�^���̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
            @details    ID:-2\n
                        ���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f��}���������̃f�[�^���̎擾�e�X�g
            @details    ID:-3\n
            @brief      �v�f��}���������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterPush) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f��}�����A���̃L�[�ō폜�������̃f�[�^���̎擾�e�X�g
            @details    ID:-4\n
            @brief      �v�f��}�����A���̃L�[�ō폜�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterErase) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���ɑ��݂���L�[�ŗv�f�̑}���������s�������̃f�[�^���̎擾�e�X�g
            @details    ID:-5\n
            @brief      ���ɑ��݂���L�[�ŗv�f�̑}���������s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterInsertFailedWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key, value1);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɗv�f�����鎞�ɑ��݂��Ȃ��L�[���w�肵�v�f�̍폜�Ɏ��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:-6\n
            @brief      ���X�g�ɗv�f�����鎞�ɑ��݂��Ȃ��L�[���w�肵�v�f�̍폜�Ɏ��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseFailedWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key1);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�폜���s������̃f�[�^���̎擾�e�X�g
            @details    ID:-7\n
                        ���X�g����ł���ꍇ�ɁA�폜���s������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumAfterEraseWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Erase(key);
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����̃f�[�^���̎擾�e�X�g
            @details    ID:-8\n
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����2�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataWhenNonChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            EXPECT_EQ(2, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜�������̃f�[�^���̎擾�e�X�g
            @details    ID:-9\n
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseWhenNonChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            table.Erase(key);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ�����̃f�[�^���̎擾�e�X�g
            @details    ID:-10\n
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ�����̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����2�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            EXPECT_EQ(2, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��鎞�Ɉ�����폜�������̃f�[�^���̎擾�e�X�g
            @details    ID:-11\n
            @brief      �v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            table.Erase(key);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:-12(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure