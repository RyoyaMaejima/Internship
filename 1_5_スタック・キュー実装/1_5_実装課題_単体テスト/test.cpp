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

        //=================================== データ数の取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合のデータ数の取得テスト
            @details    ID:スタック-0\n
                        リストが空である場合の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumWhenEmpty) {
            Stack<ResultData> stack;
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素をプッシュした時のデータ数の取得テスト
            @details    ID:スタック-1\n
            @brief      要素をプッシュした時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPush) {
            Stack<ResultData> stack;
            stack.push(rd);
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素をポップした時のデータ数の取得テスト
            @details    ID:スタック-2\n
            @brief      要素をポップした時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPop) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.pop(popRd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素のプッシュに失敗した時のデータ数の取得テスト
            @details    ID:スタック-3\n
            @brief      要素のプッシュに失敗した時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPushFailed) {
            //プッシュ失敗はメモリ確保失敗時のためここではスキップ
        }

        /**********************************************************************************//**
            @brief      プッシュを2回行った時のデータ数の取得テスト
            @details    ID:スタック-4\n
            @brief      プッシュを2回行った時の戻り値を確認しています。\n
                        データ数が2増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPushTwice) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            EXPECT_EQ(2, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      プッシュを2回行った後、1回ポップした後のデータ数の取得テスト
            @details    ID:スタック-5\n
            @brief      プッシュを2回行った後、1回ポップした後の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataAfterPushTwiceAndPopOnce) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            stack.pop(popRd);
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストが空である場合に、ポップを行った後のデータ数の取得テスト
            @details    ID:スタック-6\n
                        リストが空である場合に、ポップを行った後の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumAfterPopWhenEmpty) {
            Stack<ResultData> stack;
            stack.pop(popRd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データ数の取得機能について、constのメソッドであるかのテスト
            @details	ID:スタック-7(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== プッシュ ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、プッシュした際の挙動テスト
            @details    ID:スタック-8\n
                        リストが空である場合に、プッシュした際の挙動を確認しています。\n
                        プッシュが正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestPushToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.push(rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、プッシュした際の挙動テスト
            @details    ID:スタック-9\n
                        リストに複数の要素がある場合に、プッシュした際の挙動を確認しています。\n
                        プッシュが正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestPush) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            bool success = stack.push(rd2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		プッシュについて、非constのメソッドであるかのテスト
            @details	ID:スタック-10(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestPushWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.push();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== ポップ ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、ポップした際の挙動テスト
            @details    ID:スタック-11\n
                        リストが空である場合に、ポップした際の挙動を確認しています。\n
                        ポップが正常に行われれなければ成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestPopToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.pop(popRd);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、ポップした際の挙動テスト
            @details    ID:スタック-12\n
                        リストに複数の要素がある場合に、ポップした際の挙動を確認しています。\n
                        ポップが正常に行われれば成功です。\n
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
            @brief      リストに複数の要素がある場合に、複数回ポップした際の挙動テスト
            @details    ID:スタック-13\n
                        リストに複数の要素がある場合に、複数回ポップした際の挙動を確認しています。\n
                        ポップが正常に行われれば成功です。\n
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
            @brief		ポップについて、非constのメソッドであるかのテスト
            @details	ID:スタック-14(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(StackTest, TestPopWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Stack<ResultData> stack;
            stack.pop();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データ数の取得 ===================================

       /**********************************************************************************//**
           @brief      リストが空である場合のデータ数の取得テスト
           @details    ID:キュー-0\n
                       リストが空である場合の戻り値を確認しています。\n
                       データ数が0であれば成功です。\n
       *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumWhenEmpty) {
            Queue<ResultData> queue;
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素をエンキューした時のデータ数の取得テスト
            @details    ID:キュー-1\n
            @brief      要素をエンキューした時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            EXPECT_EQ(1, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素をデキューした時のデータ数の取得テスト
            @details    ID:キュー-2\n
            @brief      要素をデキューした時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterDequeue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.dequeue(deqRd);
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素のエンキューに失敗した時のデータ数の取得テスト
            @details    ID:キュー-3\n
            @brief      要素のエンキューに失敗した時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueFailed) {
            //エンキュー失敗はメモリ確保失敗時のためここではスキップ
        }

        /**********************************************************************************//**
            @brief      エンキューを2回行った時のデータ数の取得テスト
            @details    ID:キュー-4\n
            @brief      エンキューを2回行った時の戻り値を確認しています。\n
                        データ数が2増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueTwice) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            EXPECT_EQ(2, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      エンキューを2回行った後、1回デキューした後のデータ数の取得テスト
            @details    ID:キュー-5\n
            @brief      エンキューを2回行った後、1回デキューした後の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataAfterEnqueueTwiceAndDequeueOnce) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            queue.dequeue(deqRd);
            EXPECT_EQ(1, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストが空である場合に、デキューを行った後のデータ数の取得テスト
            @details    ID:キュー-6\n
                        リストが空である場合に、デキューを行った後の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumAfterDequeueWhenEmpty) {
            Queue<ResultData> queue;
            queue.dequeue(deqRd);
            EXPECT_EQ(0, queue.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データ数の取得機能について、constのメソッドであるかのテスト
            @details	ID:キュー-7(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Queue<ResultData> queue;
            queue.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== エンキュー ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、エンキューした際の挙動テスト
            @details    ID:キュー-8\n
                        リストが空である場合に、エンキューした際の挙動を確認しています。\n
                        エンキューが正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueueToEmpty) {
            Queue<ResultData> queue;
            bool success = queue.enqueue(rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、エンキューした際の挙動テスト
            @details    ID:キュー-9\n
                        リストに複数の要素がある場合に、エンキューした際の挙動を確認しています。\n
                        エンキューが正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueue) {
            Queue<ResultData> queue;
            queue.enqueue(rd);
            queue.enqueue(rd1);
            bool success = queue.enqueue(rd2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		エンキューについて、非constのメソッドであるかのテスト
            @details	ID:キュー-10(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestEnqueueWhenConst)
        {
#if defined TT_TEST_MANUAL
            const Queue<ResultData> queue;
            queue.enqueue(rd);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== デキュー ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、デキューした際の挙動テスト
            @details    ID:キュー-11\n
                        リストが空である場合に、デキューした際の挙動を確認しています。\n
                        デキューが正常に行われれなければ成功です。\n
        *//***********************************************************************************/
        TEST(QueueTest, TestDequeueToEmpty) {
            Queue<ResultData> queue;
            bool success = queue.dequeue(deqRd);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、デキューした際の挙動テスト
            @details    ID:キュー-12\n
                        リストに複数の要素がある場合に、デキューした際の挙動を確認しています。\n
                        デキューが正常に行われれば成功です。\n
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
            @brief      リストに複数の要素がある場合に、複数回デキューした際の挙動テスト
            @details    ID:キュー-13\n
                        リストに複数の要素がある場合に、複数回デキューした際の挙動を確認しています。\n
                        デキューが正常に行われれば成功です。\n
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
            @brief		デキューについて、非constのメソッドであるかのテスト
            @details	ID:キュー-14(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
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