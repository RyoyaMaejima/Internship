#include "pch.h"
#include "HashTable.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        std::string key = "User";
        std::string key1 = "User1";
        std::string key2 = "User2";
        std::string sameKey = "Same";
        int value = 100;
        int value1 = 200;
        int value2 = 300;
        int seaValue;

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
                        �}���A�����A�폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTable)
        {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
            success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            success = table.Erase(key);
            EXPECT_TRUE(success);

            HashTable<std::string, int, HashFunction1, 10> table1;
            success = table1.Insert(key, value);
            EXPECT_TRUE(success);
            success = table1.Search(key, seaValue);
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

        //=================================== �f�[�^�̑}�� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�}���������̋����e�X�g
            @details    ID:-13\n
                        ���X�g����ł���ꍇ�ɁA�}���������̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����Ȃ��ő}���������̋����e�X�g
            @details    ID:-14\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����Ȃ��ő}���������̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenNonDuplicated) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Insert(key2, value2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����đ}�����悤�Ƃ������̋����e�X�g
            @details    ID:-15\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����đ}�����悤�Ƃ������̋������m�F���Ă��܂��B\n
                        �}��������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenDuplicated) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Insert(key, value2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���Ƀ��X�g�ɂ���v�f�ƃn�b�V���l�������ɂȂ�L�[�ő}���������̋����e�X�g
            @details    ID:-16\n
                        ���Ƀ��X�g�ɂ���v�f�ƃn�b�V���l�������ɂȂ�L�[�ő}���������̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertSameKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            bool success = table.Insert(sameKey, value1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ��x�}�����A�폜������ēx�����L�[�ő}���������̋����e�X�g
            @details    ID:-17\n
                        ��x�}�����A�폜������ēx�����L�[�ő}���������̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertAfterInsertAndErase) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Insert(key, value1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		�}���ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:-18(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�[�^�̍폜 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�폜��������悤�Ƃ������̋����e�X�g
            @details    ID:-19\n
                        ���X�g����ł���ꍇ�ɁA�폜��������悤�Ƃ������̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Erase(key);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�č폜�������̋����e�X�g
            @details    ID:-20\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�č폜�������̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�č폜���悤�Ƃ������̋����e�X�g
            @details    ID:-21\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�č폜���悤�Ƃ������̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Erase(key2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ��x�폜�����L�[�ōēx�폜���悤�Ƃ������̋����e�X�g
            @details    ID:-22\n
                        ��x�폜�����L�[�ōēx�폜���悤�Ƃ������̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenErasedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Erase(key);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      �`�F�C���ɂȂ��Ă���v�f������1�̃L�[���w�肵�č폜�������̋����e�X�g
            @details    ID:-23\n
                        �`�F�C���ɂȂ��Ă���v�f������1�̃L�[���w�肵�č폜�������̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      �`�F�C���ɂȂ��Ă���v�f�ƃn�b�V���l�����������A���݂��Ȃ��L�[���w�肵�č폜�������̋����e�X�g
            @details    ID:-24\n
                        �`�F�C���ɂȂ��Ă���v�f�ƃn�b�V���l�����������A���݂��Ȃ��L�[���w�肵�č폜�������̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenChainWhenSameKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            bool success = table.Erase(sameKey);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      �`�F�C���ɂȂ��Ă���v�f�����ɍ폜���Ă��������̋����e�X�g
            @details    ID:-25\n
                        �`�F�C���ɂȂ��Ă���v�f�����ɍ폜���Ă��������̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseMultipleWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
            success = table.Erase(sameKey);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		�폜�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:-26(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Erase(key);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�[�^�̌��� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�L�[���w�肵�Č����������̋����e�X�g
            @details    ID:-27\n
                        ���X�g����ł���ꍇ�ɁA�L�[���w�肵�Č����������̋������m�F���Ă��܂��B\n
                        ����������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�Č����������̋����e�X�g
            @details    ID:-28\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�Č����������̋������m�F���Ă��܂��B\n
                        ����������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�Č����������̋����e�X�g
            @details    ID:-29\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�Č����������̋������m�F���Ă��܂��B\n
                        ����������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key2, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�����L�[��2�A���Ō����������̋����e�X�g
            @details    ID:-30\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�����L�[��2�A���Ō����������̋������m�F���Ă��܂��B\n
                        ����������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchTwice) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
            success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      ���ɍ폜���ꂽ�L�[�Ō����������̋����e�X�g
            @details    ID:-31\n
                        ���ɍ폜���ꂽ�L�[�Ō����������̋������m�F���Ă��܂��B\n
                        ����������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenErasedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      �`�F�C���ɂȂ��Ă���v�f�̓���1�̃L�[���w�肵�Č����������̋����e�X�g
            @details    ID:-32\n
                        �`�F�C���ɂȂ��Ă���v�f�̓���1�̃L�[���w�肵�Č����������̋������m�F���Ă��܂��B\n
                        ����������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      �`�F�C���ɂȂ��Ă���v�f������1�̍폜������ɁA�c���Ă���v�f�������������̋����e�X�g
            @details    ID:-33\n
                        �`�F�C���ɂȂ��Ă���v�f������1�̍폜������ɁA�c���Ă���v�f�������������̋������m�F���Ă��܂��B\n
                        ����������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchAfterEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            table.Erase(key);
            bool success = table.Search(sameKey, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value1, seaValue);
        }

        /**********************************************************************************//**
            @brief		�����ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:-34(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Search(key, seaValue);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure