#include "pch.h"
#include "DoublyLinkedList.h"
#include "ResultData.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        /**********************************************************************************//**
            @brief      �v�f�������Ȃ����X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details    ID:-0\n
                        �v�f�������Ȃ����X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortEmpty) {
            DoublyLinkedList<ResultData> list;

            list.Sort(compareScoreAs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareScoreDs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareUsernameAs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareUsernameDs);
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���P���������X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details    ID:-1\n
                        �v�f���P���������X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertAtEnd) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();

            list.Sort(compareScoreAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);

            list.Sort(compareScoreDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);

            list.Sort(compareUsernameAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);

            list.Sort(compareUsernameDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);
        }

        /**********************************************************************************//**
            @brief		�Q�ȏ�v�f�������X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details	ID:-2\n
                        �Q�ȏ�v�f�������X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        �v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
        {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            
            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);
            ++it;
            EXPECT_EQ((*it).score, rd1);
            EXPECT_EQ((*it).username, rd1);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            EXPECT_EQ((*it).score, rd1);
            EXPECT_EQ((*it).username, rd1);
            ++it;
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);
            ++it;
            EXPECT_EQ((*it).score, rd1);
            EXPECT_EQ((*it).username, rd1);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            EXPECT_EQ((*it).score, rd1);
            EXPECT_EQ((*it).username, rd1);
            ++it;
            EXPECT_EQ((*it).score, rd);
            EXPECT_EQ((*it).username, rd);
        }

        /**********************************************************************************//**
            @brief      �����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋����e�X�g
            @details    ID:���X�g-3\n
                        �f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �v�f���\�[�g����ĕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetBegin(), rd);
            std::cout << list.GetDataNum() << std::endl;
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋����e�X�g
            @details	ID:���X�g-4\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        ���Ԃ��ϓ����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertFailed)
        {
            DoublyLinkedList<ResultData> list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList<ResultData> list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list2.GetBegin();
            list1.Insert(it, rd2);
            EXPECT_EQ(1, list1.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋����e�X�g
            @details    ID:���X�g-5\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        �v�f���\�[�g����ĕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�L�[�w������Ȃ��������̋����e�X�g
            @details	ID:���X�g-6\n
                        �f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
                        �f�[�^�̍폜�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���΂ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterEraseFailed) {
            DoublyLinkedList<ResultData> list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

    } // namespace chapter2
} // namespace ex01_DataStructure