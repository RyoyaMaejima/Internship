#include "pch.h"
#include "DoublyLinkedList.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        //=================================== �f�[�^���̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
            @details    ID:���X�g-0\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        ���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
            DoublyLinkedList list;
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
            @details    ID:���X�g-1\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        ���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertAtEnd) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
            @details	ID:���X�g-2\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        ���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^���������Ă��Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
        {
            DoublyLinkedList list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list2.GetEnd();
            list1.Insert(it, rd2);
            EXPECT_EQ(1, list1.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
            @details    ID:���X�g-3\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetBegin(), rd);
            std::cout << list.GetDataNum() << std::endl;
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^�̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
            @details	ID:���X�g-4\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^���������Ă��Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertFailed)
        {
            DoublyLinkedList list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list2.GetBegin();
            list1.Insert(it, rd2);
            EXPECT_EQ(1, list1.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
            @details    ID:���X�g-5\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^���������Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^�̍폜�����s�����ۂ̃f�[�^���̎擾�e�X�g
            @details	ID:���X�g-6\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̍폜�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^�����ς��Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterEraseFailed) {
            DoublyLinkedList list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
            @details    ID:���X�g-7\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        ���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^�����ς��Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEraseEmpty) {
            DoublyLinkedList list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:���X�g-8(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�[�^�̑}�� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�}�������ۂ̋����e�X�g
            @details    ID:���X�g-9\n
                        ���X�g����ł���ꍇ�ɁA�}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertToEmpty) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            bool successBegin = list.Insert(list.GetBegin(), rd);
            bool successEnd = list.Insert(list.GetEnd(), rd);
            EXPECT_TRUE(successBegin);
            EXPECT_TRUE(successEnd);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���đ}�������ۂ̋����e�X�g
            @details    ID:���X�g-10\n
                        �擪�C�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertAtBegin) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            bool success = list.Insert(list.GetBegin(), rd1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���đ}�������ۂ̋����e�X�g
            @details    ID:���X�g-11\n
                        �����C�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertAtEnd) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            bool success = list.Insert(list.GetEnd(), rd1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
            @details    ID:���X�g-12\n
                        �擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetBegin();
            ++it;
            bool success = list.Insert(it, rd2);
            EXPECT_TRUE(success);
            it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �R���X�g�C�e���[�^���w�肵�đ}�������ۂ̋����e�X�g
            @details    ID:���X�g-13\n
                        �R���X�g�C�e���[�^���w�肵�đ}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertWhenConst) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList::Iterator it(nullptr, nullptr);
            it.current = cit.current;
            it.list = cit.list;
            bool success = list.Insert(it, rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      �s���ȃC�e���[�^��n���đ}�������ۂ̋����e�X�g
            @details    ID:���X�g-14\n
                        �s���ȃC�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
                        �}��������ɍs����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertInvalid) {
            DoublyLinkedList list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list2.GetBegin();
            bool success = list1.Insert(it, rd2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief		���X�g�̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
            @details	ID:���X�g-15(�蓮)\n
                        ��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestInsertWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�[�^�̍폜 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋����e�X�g
            @details    ID:���X�g-16\n
                        ���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseFromEmpty) {
            DoublyLinkedList list;
            bool successBegin = list.Erase(list.GetBegin());
            bool successEnd = list.Erase(list.GetEnd());
            EXPECT_TRUE(!successBegin);
            EXPECT_TRUE(!successEnd);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���č폜�����ۂ̋����e�X�g
            @details    ID:���X�g-17\n
                        �擪�C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseAtBegin) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            bool success = list.Erase(list.GetBegin());
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���č폜�����ۂ̋����e�X�g
            @details    ID:���X�g-18\n
                        �����C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs���Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseAtEnd) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            bool success = list.Erase(list.GetEnd());
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋����e�X�g
            @details    ID:���X�g-19\n
                        �擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetBegin();
            ++it;
            bool success = list.Erase(it);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      �R���X�g�C�e���[�^���w�肵�č폜�����ۂ̋����e�X�g
            @details    ID:���X�g-20\n
                        �R���X�g�C�e���[�^���w�肵�č폜�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList::Iterator it(nullptr, nullptr);
            it.current = cit.current;
            it.list = cit.list;
            bool success = list.Erase(it);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      �s���ȃC�e���[�^��n���č폜�����ۂ̋����e�X�g
            @details    ID:���X�g-21\n
                        �s���ȃC�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
                        �폜������ɍs����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseInvalid) {
            DoublyLinkedList list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list2.GetBegin();
            bool success = list1.Erase(it);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief		���X�g�̃f�[�^�폜�ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
            @details	ID:���X�g-22(�蓮)\n
                        ��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEraseWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetEnd());
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �擪�C�e���[�^�̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-23\n
                        ���X�g�̐擪�C�e���[�^�擾�̃e�X�g�ł��B\n
                        �擪�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it = list.GetBegin();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-24\n
                        �擪�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-25\n
                        �擪�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-26\n
                        �擪�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-27\n
                        �擪�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList::Iterator it = list.GetBegin();
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief	    ���X�g�̐擪�C�e���[�^�擾�ɂ��āAconst�̃��X�g����Iterator�̎擾���s���Ȃ����̃e�X�g
            @details	ID:���X�g-28(�蓮)\n
                        const�̃��X�g����Iterator�̎擾���s���Ȃ������m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestBeginWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            DoublyLinkedList::Iterator it = list.GetBegin();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-29\n
                        ���X�g�̐擪�R���X�g�C�e���[�^�擾�̃e�X�g�ł��B\n
                        �擪�R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmptyWhenConst) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-30\n
                        �擪�R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElementWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-31\n
                        �擪�R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElementsWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-32\n
                        �擪�R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsertWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-33\n
                        �擪�R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterEraseWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();;
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        /**********************************************************************************//**
           @brief	   ���X�g�̐擪�C�e���[�^�擾�ɂ��āAconst�̃��X�g����Iterator�̎擾���s���邩�̃e�X�g
           @details	ID:���X�g-34(�蓮)\n
                       const�̃��X�g����Iterator�̎擾���s���Ȃ������m�F���Ă��܂��B\n
                       �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
       *//***********************************************************************************/
        TEST(ListManualTest, TestBeginWhenConstWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
#endif //TT_TEST_BEGIN_MANUAL
            SUCCEED();
        }

        //=================================== �����C�e���[�^�̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-35\n
                        ���X�g�̖����C�e���[�^�擾�̃e�X�g�ł��B\n
                        �����C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it1 = list.GetTail();
            DoublyLinkedList::Iterator it2 = list.GetEnd();
            EXPECT_EQ(it1, it2);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-36\n
                        �����C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it1 = list.GetTail();
            ++it1;
            DoublyLinkedList::Iterator it2 = list.GetEnd();
            EXPECT_EQ(it1, it2);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-37\n
                        �����C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it1 = list.GetTail();
            ++it1;
            DoublyLinkedList::Iterator it2 = list.GetEnd();
            EXPECT_EQ(it1, it2);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-38\n
                        �����C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it1 = list.GetTail();
            ++it1;
            DoublyLinkedList::Iterator it2 = list.GetEnd();
            EXPECT_EQ(it1, it2);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-39\n
                        �����C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            DoublyLinkedList::Iterator it1 = list.GetTail();
            DoublyLinkedList::Iterator it2 = list.GetEnd();
            EXPECT_EQ(it1, it2);
        }

        /**********************************************************************************//**
            @brief		���X�g�̖����C�e���[�^�擾�ɂ��āAconst�̃��X�g����Iterator�̎擾���s���Ȃ����̃e�X�g
            @details	ID:���X�g-40(�蓮)\n
                        const�̃��X�g����Iterator�̎擾���s���Ȃ������m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEndWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            DoublyLinkedList::Iterator it = list.GetEnd();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �����R���X�g�C�e���[�^�̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-41\n
                        ���X�g�̖����C�e���[�^�擾�̃e�X�g�ł��B\n
                        �����R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmptyWhenConst) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it = list.GetTail();
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(it, cit);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-42\n
                        �����R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElementWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it = list.GetTail();
            ++it;
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(it, cit);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-43\n
                        �����R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElementsWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetTail();
            ++it;
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(it, cit);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-44\n
                        �����R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsertWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it = list.GetTail();
            ++it;
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(it, cit);
        }

        /**********************************************************************************//**
            @brief      �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
            @details    ID:���X�g-45\n
                        �����R���X�g�C�e���[�^�̎擾������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterEraseWhenConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            DoublyLinkedList::Iterator it = list.GetTail();
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(it, cit);
        }

        /**********************************************************************************//**
            @brief		���X�g�̖����C�e���[�^�擾�ɂ��āAconst�̃��X�g����Iterator�̎擾���s���邩�̃e�X�g
            @details	ID:���X�g-46(�蓮)\n
                        const�̃��X�g����Iterator�̎擾���s���Ȃ������m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEndWhenConstWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit = list.GetEndConst();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �C�e���[�^�̎w���v�f���擾���� ===================================

        /**********************************************************************************//**
            @brief      ���X�g�̎Q�Ƃ��Ȃ���Ԃŗv�f���擾�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-0\n
                        ���X�g����܂��͖����ȏ�ԂŁA�C�e���[�^����v�f���擾�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceWhenInvalid) {
            DoublyLinkedList::Iterator it(nullptr, nullptr);
            ASSERT_DEATH(*it, ".*");
        }

        /**********************************************************************************//**
            @brief      Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N����e�X�g
            @details    ID:�C�e���[�^-1\n
                        Iterator����擾�����v�f�ɑ΂��āA�l�̑�����\�ł��邱�Ƃ��m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestIteratorAssignment) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();
            (*it).score = 400;
            (*it).username = "User3";
            EXPECT_EQ(400, (*it).score);
            EXPECT_EQ("User3", (*it).username);
        }

        /**********************************************************************************//**
            @brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N����e�X�g
            @details	ID:�C�e���[�^-2(�蓮)\n
                        Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s�\�ł��邱�Ƃ��m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestIteratorAssignmentWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            (*it).score = 400;
            (*it).username = "User3";
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      ���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-3\n
                        ���X�g����̏ꍇ�ɁA�擪�C�e���[�^����v�f���擾���悤�Ƃ����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtBeginWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator it = list.GetBegin();
            ASSERT_DEATH(*it, ".*");
        }

        /**********************************************************************************//**
            @brief      �����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-4\n
                        �����C�e���[�^����v�f���擾���悤�Ƃ����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtEnd) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator it = list.GetEnd();
            ASSERT_DEATH(*it, ".*");
        }

        //=================================== �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� ===================================

        /**********************************************************************************//**
            @brief      ���X�g�̎Q�Ƃ��Ȃ���Ԃň�i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-5\n
                        ���X�g����܂��͖����ȏ�ԂŁA�C�e���[�^��i�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenInvalid) {
            DoublyLinkedList::Iterator it(nullptr, nullptr);
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      ���X�g����̍ۂ́A�擪�C�e���[�^����i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-6\n
                        ���X�g����̏ꍇ�ɁA�擪�C�e���[�^��i�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenEmpty) {
            DoublyLinkedList list;
            auto it = list.GetBegin();
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      �����C�e���[�^�ɑ΂��Ĉ�i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-7\n
                        �����C�e���[�^���炳��ɐi�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceAtEnd) {
            DoublyLinkedList list;
            auto it = list.GetEnd();
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�C�e���[�^����i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-8\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�C�e���[�^����i�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            bool success = false;
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �O�u�C���N�������g���s�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-9\n
                        �O�u�C���N�������g�i++���Z�q�I�[�o�[���[�h�j�̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreIncrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            auto cit = ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      ��u�C���N�������g���s�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-10\n
                        ��u�C���N�������g�i++���Z�q�I�[�o�[���[�h�j�̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostIncrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            auto cit = it++;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        //=================================== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� ===================================

        /**********************************************************************************//**
            @brief      ���X�g�̎Q�Ƃ��Ȃ���Ԃň�i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-11\n
                        ���X�g����܂��͖����ȏ�ԂŁA�C�e���[�^���t�ɐi�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenInvalid) {
            DoublyLinkedList::Iterator it(nullptr, nullptr);
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      ���X�g����̍ۂ́A�����C�e���[�^����i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-12\n
                        ���X�g����̏ꍇ�ɁA�����C�e���[�^���t�ɐi�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromEndWhenEmpty) {
            DoublyLinkedList list;
            auto it = list.GetEnd();
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      �擪�C�e���[�^�ɑ΂��Ĉ�i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-13\n
                        �擪�C�e���[�^���t�ɐi�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromBegin) {
            DoublyLinkedList list;
            auto it = list.GetBegin();
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA��i�߂��ۂ̋����e�X�g
            @details    ID:�C�e���[�^-14\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�C�e���[�^���t�ɐi�߂��ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            ++it;
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �O�u�f�N�������g���s�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-15\n
                        �O�u�f�N�������g�i--���Z�q�I�[�o�[���[�h�j�̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreDecrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            auto cit = --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      ��u�f�N�������g���s�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-16\n
                        ��u�f�N�������g�i--���Z�q�I�[�o�[���[�h�j�̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostDecrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            it++;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            auto cit = it--;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        //=================================== �C�e���[�^�̃R�s�[���s�� ===================================

        /**********************************************************************************//**
            @brief		ConstIterator����Iterator�̃R�s�[���쐬����Ȃ����`�F�b�N
            @details	ID:�C�e���[�^-17(�蓮)\n
                        ConstIterator����Iterator�ւ̃R�s�[���s�\�ł��邱�Ƃ��m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestCopyConstructorWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList::Iterator it(cit);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      �R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N����e�X�g
            @details    ID:�C�e���[�^-18\n
                        �R�s�[�R���X�g���N�g��̃C�e���[�^�̒l���R�s�[���Ɠ��������Ƃ��m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorCopyTest, TestCopyConstructor) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it(list.GetBegin());
            EXPECT_EQ((*it).score, rd.score);
            EXPECT_EQ((*it).username, rd.username);
        }

        //=================================== �C�e���[�^�̑�����s�� ===================================

        /**********************************************************************************//**
            @brief		Iterator��ConstIterator������ł��Ȃ����`�F�b�N
            @details	ID:�C�e���[�^-19(�蓮)\n
                        Iterator��ConstIterator��������邱�Ƃ��s�\�ł��邱�Ƃ��m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestAssignmentWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList::Iterator it = cit;
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      �����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N����e�X�g
            @details    ID:�C�e���[�^-20\n
                        �����̃C�e���[�^�̒l���R�s�[���Ɠ��������Ƃ��m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorAssignmentTest, TestAssignment) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();
            EXPECT_EQ((*it).score, rd.score);
            EXPECT_EQ((*it).username, rd.username);
        }

        //=================================== ��̃C�e���[�^������̂��̂ł��邩�A��r���s�� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-21\n
                        ���X�g����̏ꍇ�ɁA�擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareBeginAndEndWhenEmpty) {
            DoublyLinkedList list;
            auto it1 = list.GetBegin();
            auto it2 = list.GetEnd();
            bool success = it1 == it2;
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ����̃C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-22\n
                        ����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareSameIterators) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            bool success = it1 == it2;
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      �قȂ�C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-23\n
                        �قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareDifferentIterators) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            ++it2;
            bool success = it1 == it2;
            EXPECT_TRUE(!success);
        }

        //=================================== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s�� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-24\n
                        ���X�g����̏ꍇ�ɁA�擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenEmpty) {
            DoublyLinkedList list;
            auto it1 = list.GetBegin();
            auto it2 = list.GetEnd();
            bool success = it1 != it2;
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ����̃C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-25\n
                        ����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenSame) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            bool success = it1 != it2;
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      �قȂ�C�e���[�^���r�����ۂ̋����e�X�g
            @details    ID:�C�e���[�^-26\n
                        �قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenDifferent) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            ++it2;
            bool success = it1 != it2;
            EXPECT_TRUE(success);
        }

    } // namespace chapter2
} // namespace ex01_DataStructure
