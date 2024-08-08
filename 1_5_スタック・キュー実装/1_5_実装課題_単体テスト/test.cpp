#include "pch.h""
#include "ResultData.h"
#include "Stack.h"
#include "Queue.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };
        ResultData popRd;
        ResultData deqRd;

        //=================================== �f�[�^���̎擾 ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-0\n
                        ���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumWhenEmpty) {
            Stack<ResultData> stack;
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���v�b�V���������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-1\n
            @brief      �v�f���v�b�V���������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPush) {
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
        TEST(StackTest, TestGetDataAfterPop) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.pop(popRd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�̃v�b�V���Ɏ��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-3\n
            @brief      �v�f�̃v�b�V���Ɏ��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPushFailed) {
            //�v�b�V�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
        }

        /**********************************************************************************//**
            @brief      �v�b�V����2��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-4\n
            @brief      �v�b�V����2��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����2�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPushTwice) {
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
        TEST(StackTest, TestGetDataAfterPushTwiceAndPopOnce) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            stack.pop(popRd);
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�|�b�v���s������̃f�[�^���̎擾�e�X�g
            @details    ID:�X�^�b�N-6\n
                        ���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumAfterPopWhenEmpty) {
            Stack<ResultData> stack;
            stack.pop(popRd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�X�^�b�N-7(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumWhenConst)
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
            @details    ID:�X�^�b�N-8\n
                        ���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋������m�F���Ă��܂��B\n
                        �v�b�V��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPushToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.push(rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋����e�X�g
            @details    ID:�X�^�b�N-9\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋������m�F���Ă��܂��B\n
                        �v�b�V��������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPush) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            bool success = stack.push(rd2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		�v�b�V���ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�X�^�b�N-10(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPushWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.push();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �|�b�v ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋����e�X�g
            @details    ID:�X�^�b�N-11\n
                        ���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋������m�F���Ă��܂��B\n
                        �|�b�v������ɍs����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPopToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.pop(popRd);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋����e�X�g
            @details    ID:�X�^�b�N-12\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋������m�F���Ă��܂��B\n
                        �|�b�v������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPop) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            bool success = stack.pop(popRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd1.score, popRd.score);
            EXPECT_EQ(rd1.username, popRd.username);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋����e�X�g
            @details    ID:�X�^�b�N-13\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋������m�F���Ă��܂��B\n
                        �|�b�v������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPopMultiple) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            bool success = stack.pop(popRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd1.score, popRd.score);
            EXPECT_EQ(rd1.username, popRd.username);
            success = stack.pop(popRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd.score, popRd.score);
            EXPECT_EQ(rd.username, popRd.username);
        }

        /**********************************************************************************//**
            @brief		�|�b�v�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�X�^�b�N-14(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(StackTest, TestPopWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.pop();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�[�^���̎擾 ===================================

       /**********************************************************************************//**
           @brief      ���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
           @details    ID:�L���[-0\n
                       ���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
                       �f�[�^����0�ł���ΐ����ł��B\n
       *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumWhenEmpty) {
            Queue<ResultData> queue;
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���G���L���[�������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-1\n
            @brief      �v�f���G���L���[�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            EXPECT_EQ(1, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���f�L���[�������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-2\n
            @brief      �v�f���f�L���[�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterDequeue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.dequeue(deqRd);
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f�̃G���L���[�Ɏ��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-3\n
            @brief      �v�f�̃G���L���[�Ɏ��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueFailed) {
            //�G���L���[���s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
        }

        /**********************************************************************************//**
            @brief      �G���L���[��2��s�������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-4\n
            @brief      �G���L���[��2��s�������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����2�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueTwice) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            EXPECT_EQ(2, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �G���L���[��2��s������A1��f�L���[������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-5\n
            @brief      �G���L���[��2��s������A1��f�L���[������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����1�����Ă���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueTwiceAndDequeueOnce) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            queue.dequeue(deqRd);
            EXPECT_EQ(1, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�f�L���[���s������̃f�[�^���̎擾�e�X�g
            @details    ID:�L���[-6\n
                        ���X�g����ł���ꍇ�ɁA�f�L���[���s������̖߂�l���m�F���Ă��܂��B\n
                        �f�[�^����0�ł���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumAfterDequeueWhenEmpty) {
            Queue<ResultData> queue;
            queue.dequeue(deqRd);
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�L���[-7(�蓮)\n
                        const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Queue<ResultData> queue;
            queue.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �G���L���[ ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�G���L���[�����ۂ̋����e�X�g
            @details    ID:�L���[-8\n
                        ���X�g����ł���ꍇ�ɁA�G���L���[�����ۂ̋������m�F���Ă��܂��B\n
                        �G���L���[������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueueToEmpty) {
            Queue<ResultData> queue;
            bool success = queue.enqueue(rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�G���L���[�����ۂ̋����e�X�g
            @details    ID:�L���[-9\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�G���L���[�����ۂ̋������m�F���Ă��܂��B\n
                        �G���L���[������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            bool success = queue.enqueue(rd2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		�G���L���[�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�L���[-10(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueueWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Queue<ResultData> queue;
            queue.enqueue(rd);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== �f�L���[ ===================================

        /**********************************************************************************//**
            @brief      ���X�g����ł���ꍇ�ɁA�f�L���[�����ۂ̋����e�X�g
            @details    ID:�L���[-11\n
                        ���X�g����ł���ꍇ�ɁA�f�L���[�����ۂ̋������m�F���Ă��܂��B\n
                        �f�L���[������ɍs����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestDequeueToEmpty) {
            Queue<ResultData> queue;
            bool success = queue.dequeue(deqRd);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA�f�L���[�����ۂ̋����e�X�g
            @details    ID:�L���[-12\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA�f�L���[�����ۂ̋������m�F���Ă��܂��B\n
                        �f�L���[������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestDequeue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            bool success = queue.dequeue(deqRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd.score, deqRd.score);
            EXPECT_EQ(rd.username, deqRd.username);
        }

        /**********************************************************************************//**
            @brief      ���X�g�ɕ����̗v�f������ꍇ�ɁA������f�L���[�����ۂ̋����e�X�g
            @details    ID:�L���[-13\n
                        ���X�g�ɕ����̗v�f������ꍇ�ɁA������f�L���[�����ۂ̋������m�F���Ă��܂��B\n
                        �f�L���[������ɍs����ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestDequeueMultiple) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            bool success = queue.dequeue(deqRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd.score, deqRd.score);
            EXPECT_EQ(rd.username, deqRd.username);
            success = queue.dequeue(deqRd);
            EXPECT_TRUE(success);
            EXPECT_EQ(rd1.score, deqRd.score);
            EXPECT_EQ(rd1.username, deqRd.username);
        }

        /**********************************************************************************//**
            @brief		�f�L���[�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:�L���[-14(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QueueTest, TestDequeueWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Queue<ResultData> queue;
            queue.dequeue(deqRd);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure