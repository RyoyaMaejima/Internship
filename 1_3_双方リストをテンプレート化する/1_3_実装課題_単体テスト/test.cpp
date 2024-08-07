#include "pch.h"
#include "DoublyLinkedList.h"
#include "ResultData.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        //=================================== データ数の取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合のデータ数の取得テスト
            @details    ID:リスト-0\n
                        データ数の取得機能のテストです。\n
                        リストが空である場合の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リスト末尾への挿入を行った際のデータ数の取得テスト
            @details    ID:リスト-1\n
                        データ数の取得機能のテストです。\n
                        リスト末尾への挿入を行った際の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertAtEnd) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
            @details	ID:リスト-2\n
                        データ数の取得機能のテストです。\n
                        リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
                        データ数が増えていなければ成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
        {
            DoublyLinkedList<ResultData> list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList<ResultData> list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list2.GetEnd();
            list1.Insert(it, rd2);
            EXPECT_EQ(1, list1.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った際のデータ数の取得テスト
            @details    ID:リスト-3\n
                        データ数の取得機能のテストです。\n
                        データの挿入を行った際の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetBegin(), rd);
            std::cout << list.GetDataNum() << std::endl;
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データの挿入が失敗した際のデータ数の取得テスト
            @details	ID:リスト-4\n
                        データ数の取得機能のテストです。\n
                        データの挿入が失敗した際の戻り値を確認しています。\n
                        データ数が増えていなければ成功です。\n
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
            @brief      データの削除を行った際のデータ数の取得テスト
            @details    ID:リスト-5\n
                        データ数の取得機能のテストです。\n
                        データの削除を行った際の戻り値を確認しています。\n
                        データ数が減っていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データの削除が失敗した際のデータ数の取得テスト
            @details	ID:リスト-6\n
                        データ数の取得機能のテストです。\n
                        データの削除が失敗した際の戻り値を確認しています。\n
                        データ数が変わらなければ成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterEraseFailed) {
            DoublyLinkedList<ResultData> list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストが空である場合に、データの削除を行った際のデータ数の取得テスト
            @details    ID:リスト-7\n
                        データ数の取得機能のテストです。\n
                        リストが空である場合に、データの削除を行った際の戻り値を確認しています。\n
                        データ数が変わらなければ成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenEraseEmpty) {
            DoublyLinkedList<ResultData> list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データ数の取得機能について、constのメソッドであるかのテスト
            @details	ID:リスト-8(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データの挿入 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、挿入した際の挙動テスト
            @details    ID:リスト-9\n
                        リストが空である場合に、挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertToEmpty) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            bool successBegin = list.Insert(list.GetBegin(), rd);
            bool successEnd = list.Insert(list.GetEnd(), rd);
            EXPECT_TRUE(successBegin);
            EXPECT_TRUE(successEnd);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、先頭イテレータを渡して挿入した際の挙動テスト
            @details    ID:リスト-10\n
                        先頭イテレータを渡して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertAtBegin) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            bool success = list.Insert(list.GetBegin(), rd1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、末尾イテレータを渡して挿入した際の挙動テスト
            @details    ID:リスト-11\n
                        末尾イテレータを渡して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertAtEnd) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            bool success = list.Insert(list.GetEnd(), rd1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
            @details    ID:リスト-12\n
                        先頭でも末尾でもないイテレータを渡して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
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
            @brief      コンストイテレータを指定して挿入した際の挙動テスト
            @details    ID:リスト-13\n
                        コンストイテレータを指定して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertWhenConst) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList<ResultData>::Iterator it(nullptr, nullptr);
            it.current = cit.current;
            it.list = cit.list;
            bool success = list.Insert(it, rd);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      不正なイテレータを渡して挿入した際の挙動テスト
            @details    ID:リスト-14\n
                        不正なイテレータを渡して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれなければ成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertInvalid) {
            DoublyLinkedList<ResultData> list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList<ResultData> list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list2.GetBegin();
            bool success = list1.Insert(it, rd2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief		リストのデータ追加について、非constが保障されているかのテスト
            @details	ID:リスト-15(手動)\n
                        非constが保障されているかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestInsertWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データの削除 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、削除を行った際の挙動テスト
            @details    ID:リスト-16\n
                        リストが空である場合に、削除を行った際の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseFromEmpty) {
            DoublyLinkedList<ResultData> list;
            bool successBegin = list.Erase(list.GetBegin());
            bool successEnd = list.Erase(list.GetEnd());
            EXPECT_TRUE(!successBegin);
            EXPECT_TRUE(!successEnd);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、先頭イテレータを渡して削除した際の挙動テスト
            @details    ID:リスト-17\n
                        先頭イテレータを渡して削除した際の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseAtBegin) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            bool success = list.Erase(list.GetBegin());
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、末尾イテレータを渡して削除した際の挙動テスト
            @details    ID:リスト-18\n
                        末尾イテレータを渡して削除した際の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseAtEnd) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            bool success = list.Erase(list.GetEnd());
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動テスト
            @details    ID:リスト-19\n
                        先頭でも末尾でもないイテレータを渡して削除した際の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            ++it;
            bool success = list.Erase(it);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      コンストイテレータを指定して削除した際の挙動テスト
            @details    ID:リスト-20\n
                        コンストイテレータを指定して削除した際の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList<ResultData>::Iterator it(nullptr, nullptr);
            it.current = cit.current;
            it.list = cit.list;
            bool success = list.Erase(it);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      不正なイテレータを渡して削除した際の挙動テスト
            @details    ID:リスト-21\n
                        不正なイテレータを渡して削除した際の挙動を確認しています。\n
                        削除が正常に行われれなければ成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseInvalid) {
            DoublyLinkedList<ResultData> list1;
            list1.Insert(list1.GetEnd(), rd);
            DoublyLinkedList<ResultData> list2;
            list2.Insert(list2.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list2.GetBegin();
            bool success = list1.Erase(it);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief		リストのデータ削除について、非constが保障されているかのテスト
            @details	ID:リスト-22(手動)\n
                        非constが保障されているかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEraseWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetEnd());
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== 先頭イテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、呼び出した際の挙動テスト
            @details    ID:リスト-23\n
                        リストの先頭イテレータ取得のテストです。\n
                        先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストに要素が一つある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-24\n
                        先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-25\n
                        先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElements) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-26\n
                        先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      データの削除を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-27\n
                        先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		リストの先頭イテレータ取得について、constのリストからIteratorの取得が行えないかのテスト
            @details	ID:リスト-28(手動)\n
                        constのリストからIteratorの取得が行えないかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestBeginWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== 先頭コンストイテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、呼び出した際の挙動テスト
            @details    ID:リスト-29\n
                        リストの先頭コンストイテレータ取得のテストです。\n
                        先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmptyWhenConst) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストに要素が一つある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-30\n
                        先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElementWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-31\n
                        先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElementsWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-32\n
                        先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsertWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      データの削除を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-33\n
                        先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterEraseWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();;
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        /**********************************************************************************//**
           @brief		リストの先頭イテレータ取得について、constのリストからIteratorの取得が行えるかのテスト
           @details	ID:リスト-34(手動)\n
                       constのリストからIteratorの取得が行えないかを確認しています。\n
                       有効にしてコンパイルが通れば成功です。\n
       *//***********************************************************************************/
        TEST(ListManualTest, TestBeginWhenConstWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== 末尾イテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、呼び出した際の挙動テスト
            @details    ID:リスト-35\n
                        リストの末尾イテレータ取得のテストです。\n
                        末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
            EXPECT_EQ(it, list.GetBegin());
        }

        /**********************************************************************************//**
            @brief      リストに要素が一つある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-36\n
                        末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-37\n
                        末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElements) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
            --it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-38\n
                        末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsert) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      データの削除を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-39\n
                        末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterErase) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
            --it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		リストの末尾イテレータ取得について、constのリストからIteratorの取得が行えないかのテスト
            @details	ID:リスト-40(手動)\n
                        constのリストからIteratorの取得が行えないかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEndWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::Iterator it = list.GetEnd();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== 末尾コンストイテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、呼び出した際の挙動テスト
            @details    ID:リスト-41\n
                        リストの末尾イテレータ取得のテストです。\n
                        末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmptyWhenConst) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
            EXPECT_EQ(cit, list.GetBegin());
        }

        /**********************************************************************************//**
            @brief      リストに要素が一つある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-42\n
                        末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElementWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
            --cit;
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
            @details    ID:リスト-43\n
                        末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElementsWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
            --cit;
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-44\n
                        末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsertWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
            --cit;
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      データの削除を行った後に、呼び出した際の挙動テスト
            @details    ID:リスト-45\n
                        末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterEraseWhenConst) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
            --cit;
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief		リストの末尾イテレータ取得について、constのリストからIteratorの取得が行えるかのテスト
            @details	ID:リスト-46(手動)\n
                        constのリストからIteratorの取得が行えないかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestEndWhenConstWhenConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetEndConst();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== イテレータの指す要素を取得する ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で要素を取得した際の挙動テスト
            @details    ID:イテレータ-0\n
                        リストが空または無効な状態で、イテレータから要素を取得した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceWhenInvalid) {
            DoublyLinkedList<ResultData>::ConstIterator it(nullptr, nullptr);
            ASSERT_DEATH(*it, ".*");
        }

        /**********************************************************************************//**
            @brief      Iteratorから取得した要素に対して、値の代入が行えるかをチェックするテスト
            @details    ID:イテレータ-1\n
                        Iteratorから取得した要素に対して、値の代入が可能であることを確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestIteratorAssignment) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();
            (*it).score = 400;
            (*it).username = "User3";
            EXPECT_EQ(400, (*it).score);
            EXPECT_EQ("User3", (*it).username);
        }

        /**********************************************************************************//**
            @brief		ConstIteratorから取得した要素に対して、値の代入が行えないかをチェックするテスト
            @details	ID:イテレータ-2(手動)\n
                        Iteratorから取得した要素に対して、値の代入が不可能であることを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestIteratorAssignmentWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            (*it).score = 400;
            (*it).username = "User3";
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
            @details    ID:イテレータ-3\n
                        リストが空の場合に、先頭イテレータから要素を取得しようとした際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtBeginWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator it = list.GetBegin();
            ASSERT_DEATH(*it, ".*");
        }

        /**********************************************************************************//**
            @brief      末尾イテレータに対して呼び出した際の挙動テスト
            @details    ID:イテレータ-4\n
                        末尾イテレータから要素を取得しようとした際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtEnd) {
            DoublyLinkedList<ResultData> list;
            DoublyLinkedList<ResultData>::ConstIterator it = list.GetEnd();
            ASSERT_DEATH(*it, ".*");
        }

        //=================================== イテレータをリストの末尾に向かって一つ進める ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で一つ進めた際の挙動テスト
            @details    ID:イテレータ-5\n
                        リストが空または無効な状態で、イテレータを進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenInvalid) {
            DoublyLinkedList<ResultData>::Iterator it(nullptr, nullptr);
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      リストが空の際の、先頭イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-6\n
                        リストが空の場合に、先頭イテレータを進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            auto it = list.GetBegin();
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      末尾イテレータに対して一つ進めた際の挙動テスト
            @details    ID:イテレータ-7\n
                        末尾イテレータからさらに進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceAtEnd) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetEnd();
            ASSERT_DEATH(++it, ".*");
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-8\n
                        リストに複数の要素がある場合に、イテレータを一つ進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenMultipleElements) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            bool success = false;
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      前置インクリメントを行った際の挙動テスト
            @details    ID:イテレータ-9\n
                        前置インクリメント（++演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreIncrement) {
            DoublyLinkedList<ResultData> list;
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
            @brief      後置インクリメントを行った際の挙動テスト
            @details    ID:イテレータ-10\n
                        後置インクリメント（++演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostIncrement) {
            DoublyLinkedList<ResultData> list;
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

        //=================================== イテレータをリストの先頭に向かって一つ進める ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で一つ進めた際の挙動テスト
            @details    ID:イテレータ-11\n
                        リストが空または無効な状態で、イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenInvalid) {
            DoublyLinkedList<ResultData>::Iterator it(nullptr, nullptr);
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      リストが空の際の、末尾イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-12\n
                        リストが空の場合に、末尾イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromEndWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            auto it = list.GetEnd();
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      先頭イテレータに対して一つ進めた際の挙動テスト
            @details    ID:イテレータ-13\n
                        先頭イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromBegin) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();
            ASSERT_DEATH(--it, ".*");
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、一つ進めた際の挙動テスト
            @details    ID:イテレータ-14\n
                        リストに複数の要素がある場合に、イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenMultipleElements) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetEnd();
            --it;
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      前置デクリメントを行った際の挙動テスト
            @details    ID:イテレータ-15\n
                        前置デクリメント（--演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreDecrement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it1 = list.GetEnd();
            --it1;
            EXPECT_EQ(rd1.score, (*it1).score);
            EXPECT_EQ(rd1.username, (*it1).username);
            auto it2 = --it1;
            EXPECT_EQ(rd.score, (*it1).score);
            EXPECT_EQ(rd.username, (*it1).username);
            EXPECT_EQ(rd.score, (*it2).score);
            EXPECT_EQ(rd.username, (*it2).username);
        }

        /**********************************************************************************//**
            @brief      後置デクリメントを行った際の挙動テスト
            @details    ID:イテレータ-16\n
                        後置デクリメント（--演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostDecrement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it1 = list.GetEnd();
            it1--;
            EXPECT_EQ(rd1.score, (*it1).score);
            EXPECT_EQ(rd1.username, (*it1).username);
            auto it2 = it1--;
            EXPECT_EQ(rd.score, (*it1).score);
            EXPECT_EQ(rd.username, (*it1).username);
            EXPECT_EQ(rd1.score, (*it2).score);
            EXPECT_EQ(rd1.username, (*it2).username);
        }

        //=================================== イテレータのコピーを行う ===================================

        /**********************************************************************************//**
            @brief		ConstIteratorからIteratorのコピーが作成されないかチェック
            @details	ID:イテレータ-17(手動)\n
                        ConstIteratorからIteratorへのコピーが不可能であることを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestCopyConstructorWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList<ResultData>::Iterator it(cit);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      コピーコンストラクト後の値がコピー元と等しいことをチェックするテスト
            @details    ID:イテレータ-18\n
                        コピーコンストラクト後のイテレータの値がコピー元と等しいことを確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorCopyTest, TestCopyConstructor) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it(list.GetBegin());
            EXPECT_EQ((*it).score, rd.score);
            EXPECT_EQ((*it).username, rd.username);
        }

        //=================================== イテレータの代入を行う ===================================

        /**********************************************************************************//**
            @brief		IteratorにConstIteratorが代入できないかチェック
            @details	ID:イテレータ-19(手動)\n
                        IteratorにConstIteratorが代入することが不可能であることを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(ListManualTest, TestAssignmentWhenConst)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList<ResultData>::ConstIterator cit = list.GetBeginConst();
            DoublyLinkedList<ResultData>::Iterator it = cit;
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief      代入後の値がコピー元と等しいことをチェックするテスト
            @details    ID:イテレータ-20\n
                        代入後のイテレータの値がコピー元と等しいことを確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAssignmentTest, TestAssignment) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();
            EXPECT_EQ((*it).score, rd.score);
            EXPECT_EQ((*it).username, rd.username);
        }

        //=================================== 二つのイテレータが同一のものであるか、比較を行う ===================================

        /**********************************************************************************//**
            @brief      リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動テスト
            @details    ID:イテレータ-21\n
                        リストが空の場合に、先頭イテレータと末尾イテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareBeginAndEndWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            auto it1 = list.GetBegin();
            auto it2 = list.GetEnd();
            bool success = it1 == it2;
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      同一のイテレータを比較した際の挙動テスト
            @details    ID:イテレータ-22\n
                        同一のイテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareSameIterators) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            bool success = it1 == it2;
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      異なるイテレータを比較した際の挙動テスト
            @details    ID:イテレータ-23\n
                        異なるイテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestCompareDifferentIterators) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            ++it2;
            bool success = it1 == it2;
            EXPECT_TRUE(!success);
        }

        //=================================== 二つのイテレータが異なるものであるか、比較を行う ===================================

        /**********************************************************************************//**
            @brief      リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動テスト
            @details    ID:イテレータ-24\n
                        リストが空の場合に、先頭イテレータと末尾イテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenEmpty) {
            DoublyLinkedList<ResultData> list;
            auto it1 = list.GetBegin();
            auto it2 = list.GetEnd();
            bool success = it1 != it2;
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      同一のイテレータを比較した際の挙動テスト
            @details    ID:イテレータ-25\n
                        同一のイテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenSame) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it1 = list.GetBegin();
            auto it2 = list.GetBegin();
            bool success = it1 != it2;
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      異なるイテレータを比較した際の挙動テスト
            @details    ID:イテレータ-26\n
                        異なるイテレータを比較した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorComparisonTest, TestDifferentWhenDifferent) {
            DoublyLinkedList<ResultData> list;
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
