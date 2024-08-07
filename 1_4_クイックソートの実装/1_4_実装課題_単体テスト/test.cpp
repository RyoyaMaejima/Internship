#include "pch.h"
#include "DoublyLinkedList.h"
#include "ResultData.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        /**********************************************************************************//**
            @brief      要素を持たないリストにソートを実行したときの挙動テスト
            @details    ID:-0\n
                        要素を持たないリストにソートを実行したときの挙動を確認しています。\n
                        リストに何も起こらなければ成功です。\n
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
            @brief      要素を１つだけ持つリストにソートを実行したときの挙動テスト
            @details    ID:-1\n
                        要素を１つだけ持つリストにソートを実行したときの挙動を確認しています。\n
                        リストに何も起こらなければ成功です。\n
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
            @brief		２つ以上要素を持つリストにソートを実行したときの挙動テスト
            @details	ID:-2\n
                        ２つ以上要素を持つリストにソートを実行したときの挙動を確認しています。\n
                        要素が指定したキーに準じて指定した順に並べば成功です。\n
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
            @brief      同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動テスト
            @details    ID:リスト-3\n
                        データの挿入を行った際の戻り値を確認しています。\n
                        要素がソートされて並べば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetBegin(), rd);
            std::cout << list.GetDataNum() << std::endl;
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		整列済みリストにソートを実行した時の挙動テスト
            @details	ID:リスト-4\n
                        データ数の取得機能のテストです。\n
                        データの挿入が失敗した際の戻り値を確認しています。\n
                        順番が変動しなければ成功です。\n
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
            @brief      一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動テスト
            @details    ID:リスト-5\n
                        データ数の取得機能のテストです。\n
                        データの削除を行った際の戻り値を確認しています。\n
                        要素がソートされて並べば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		キー指定をしなかった時の挙動テスト
            @details	ID:リスト-6\n
                        データ数の取得機能のテストです。\n
                        データの削除が失敗した際の戻り値を確認しています。\n
                        リストに何も起こらなければば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterEraseFailed) {
            DoublyLinkedList<ResultData> list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

    } // namespace chapter2
} // namespace ex01_DataStructure