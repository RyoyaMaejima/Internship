#include "pch.h""
#include "ResultData.h"
#include "Stack.h"
#include "Queue.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };


        //=================================== データ数の取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合のデータ数の取得テスト
            @details    ID:スタック-0\n
                        リストが空である場合の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
            Stack<ResultData> stack;
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素をプッシュした時のデータ数の取得テスト
            @details    ID:スタック-1\n
            @brief      要素をプッシュした時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPush) {
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
        TEST(GetDataNumTest, TestGetDataAfterPop) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.pop();
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素のプッシュに失敗した時のデータ数の取得テスト
            @details    ID:スタック-3\n
            @brief      要素のプッシュに失敗した時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPushFailed) {
            Stack<ResultData> stack;
            //stack.push(rd);
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      プッシュを2回行った時のデータ数の取得テスト
            @details    ID:スタック-4\n
            @brief      プッシュを2回行った時の戻り値を確認しています。\n
                        データ数が2増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataAfterPushTwice) {
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
        TEST(GetDataNumTest, TestGetDataAfterPushTwiceAndPopOnce) {
            Stack<ResultData> stack;
            stack.push(rd);
            stack.push(rd1);
            stack.pop();
            EXPECT_EQ(1, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストが空である場合に、ポップを行った後のデータ数の取得テスト
            @details    ID:スタック-6\n
                        リストが空である場合に、ポップを行った後の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterPopWhenEmpty) {
            Stack<ResultData> stack;
            stack.pop();
            EXPECT_EQ(0, stack.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データ数の取得機能について、constのメソッドであるかのテスト
            @details	ID:スタック-7(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenConst)
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
            @details    ID:リスト-8\n
                        リストが空である場合に、プッシュした際の挙動を確認しています。\n
                        プッシュが正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(PushTest, TestPushToEmpty) {
            Stack<ResultData> stack;
            bool success = stack.push(rd);
            EXPECT_TRUE(success);
        }

    } // namespace chapter2
} // namespace ex01_DataStructure