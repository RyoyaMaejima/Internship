#include "pch.h""
#include "ResultData.h"
#include "Stack.h"
#include "Queue.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };


        //=================================== �f�[�^���̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-0\n
                        ���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
            Stack<ResultData> stack;
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���v�b�V���������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-1\n
            @brief      �v�f���v�b�V���������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPush) {
            Stack<ResultData> stack;
            stack.push(rd);
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���|�b�v�������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-2\n
            @brief      �v�f���|�b�v�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPop) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.pop();
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�̃v�b�V���Ɏ��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-3\n
            @brief      �v�f�̃v�b�V���Ɏ��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPushFailed) {
            Stack<ResultData> stack;
            //stack.push(rd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�b�V����2��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-4\n
            @brief      �v�b�V����2��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����2�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPushTwice) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            EXPECT_EQ(2, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�b�V����2��s������A1��|�b�v������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-5\n
            @brief      �v�b�V����2��s������A1��|�b�v������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPushTwiceAndPopOnce) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            stack.pop();
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�|�b�v���s������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-6\n
                        ���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterPopWhenEmpty) {
            Stack<ResultData> stack;
            stack.pop();
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�X�^�b�N-7(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �v�b�V�� ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋����e�X�g
            @details    ID:���X�g-8\n
                        ���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋������m�F���Ă��܂��B\n
                        �v�b�V��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(PushTest, TestPushToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.push(rd);
            EXPECT_TRUE(success);
        }

    } // namespace chapter2
} // namespace ex01_DataStructure