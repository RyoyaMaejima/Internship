#include "pch.h"
#include "DoublyLinkedList.h"
#include "ResultData.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        bool compareInvalid(const std::string& a, const std::string& b) {
            return a < b;
        }

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
        TEST(QuickSortTest, TestQuickSortOneElement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();

            list.Sort(compareScoreAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareScoreDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareUsernameAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareUsernameDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		２つ以上要素を持つリストにソートを実行したときの挙動テスト
            @details	ID:-2\n
                        ２つ以上要素を持つリストにソートを実行したときの挙動を確認しています。\n
                        要素が指定したキーに準じて指定した順に並べば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortMultipleElements)
        {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            
            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動テスト
            @details    ID:-3\n
                        同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動を確認しています。\n
                        要素がソートされて並べば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortSameKey) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);

            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		整列済みリストにソートを実行した時の挙動テスト
            @details	ID:-4\n
                        整列済みリストにソートを実行した時の挙動を確認しています。\n
                        順番が変動しなければ成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortSortedList)
        {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);

            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動テスト
            @details    ID:-5\n
                        一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動を確認しています。\n
                        要素がソートされて並べば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortResort) {
            DoublyLinkedList<ResultData> list1;
            DoublyLinkedList<ResultData> list2;
            DoublyLinkedList<ResultData> list3;
            DoublyLinkedList<ResultData> list4;
            list1.Insert(list1.GetEnd(), rd);
            list1.Insert(list1.GetEnd(), rd1);
            list2.Insert(list2.GetEnd(), rd);
            list2.Insert(list2.GetEnd(), rd1);
            list3.Insert(list3.GetEnd(), rd);
            list3.Insert(list3.GetEnd(), rd1);
            list4.Insert(list4.GetEnd(), rd);
            list4.Insert(list4.GetEnd(), rd1);

            list1.Sort(compareScoreAs);
            list1.Insert(list1.GetBegin(), rd2);
            auto it = list1.GetBegin();
            list1.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);

            list2.Sort(compareScoreDs);
            list2.Insert(list2.GetBegin(), rd2);
            it = list2.GetBegin();
            list2.Sort(compareScoreDs);
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list3.Sort(compareUsernameAs);
            list3.Insert(list3.GetBegin(), rd2);
            it = list3.GetBegin();
            list3.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);

            list4.Sort(compareUsernameDs);
            list4.Insert(list4.GetBegin(), rd2);
            it = list4.GetBegin();
            list4.Sort(compareUsernameDs);
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		キー指定をしなかった時の挙動テスト
            @details	ID:-6\n
                        キー指定をしなかった時の挙動を確認しています。\n
                        リストに何も起こらなければば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortNullKey) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();

            list.Sort(nullptr);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		型などが不適切なキー指定が引数で渡された時の挙動テスト
            @details	ID:-7(手動)\n
                        型などが不適切なキー指定が引数で渡された時の挙動を確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortInvalid)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            list.Sort(compareInvalid);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief		ソートについて、非constのメソッドであるかのテスト
            @details	ID:-8(手動)\n
                        非constのメソッドであるかを確認しています。
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Sort(compareScoreAs);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure