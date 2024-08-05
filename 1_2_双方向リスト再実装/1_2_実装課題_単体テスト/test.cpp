#include "pch.h"
#include "DoublyLinkedList.h"

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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            // 挿入失敗はメモリ確保失敗時のためスキップ
        }

        /**********************************************************************************//**
            @brief      データの挿入を行った際のデータ数の取得テスト
            @details    ID:リスト-3\n
                        データ数の取得機能のテストです。\n
                        データの挿入を行った際の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetBegin(), rd);
            std::cout << list.GetDataNum() << std::endl;
            EXPECT_EQ(1, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データの挿入が失敗した際のデータ数の取得テスト
            @details	ID:リスト-4\n
                        データ数の取得機能のテストです。\n
                        リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
                        データ数が増えていなければ成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterInsertFailed)
        {
            // 挿入失敗はメモリ確保失敗時のためスキップ
        }

        /**********************************************************************************//**
            @brief      データの削除を行った際のデータ数の取得テスト
            @details    ID:リスト-5\n
                        データ数の取得機能のテストです。\n
                        データの削除を行った際の戻り値を確認しています。\n
                        データ数が減っていれば成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データの挿入が失敗した際のデータ数の取得テスト
            @details	ID:リスト-6\n
                        データ数の取得機能のテストです。\n
                        データの削除が失敗した際の戻り値を確認しています。\n
                        データ数が変わらなければ成功です。\n
        *//***********************************************************************************/
        TEST(GetDataNumTest, TestGetDataNumAfterEraseFailed) {
            DoublyLinkedList list;
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
            DoublyLinkedList list;
            list.Erase(list.GetBegin());
            EXPECT_EQ(0, list.GetDataNum());
        }

        //=================================== データの挿入 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、挿入した際の挙動テスト
            @details    ID:リスト-9\n
                        リストが空である場合に、挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
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
            @brief      リストに複数の要素がある場合に、先頭イテレータを渡して挿入した際の挙動テスト
            @details    ID:リスト-10\n
                        先頭イテレータを渡して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertAtBegin) {
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetBegin();
            ++it;
            bool success = list.Insert(it, rd2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      コンストイテレータを指定して挿入した際の挙動テスト
            @details    ID:リスト-13\n
                        コンストイテレータを指定して挿入した際の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(InsertTest, TestInsertConst) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit = list.GetBegin();
            DoublyLinkedList::Iterator it(nullptr);
            it.current = cit.current;
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
            // 挿入失敗はメモリ確保失敗時のためスキップ
        }

        //=================================== データの削除 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、削除を行った際の挙動テスト
            @details    ID:リスト-16\n
                        リストが空である場合に、削除を行った際の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestEraseFromEmpty) {
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
        TEST(EraseTest, TestInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it = list.GetBegin();
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
        TEST(EraseTest, TestInsertConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit = list.GetBegin();
            DoublyLinkedList::Iterator it(nullptr);
            it.current = cit.current;
            bool success = list.Erase(it);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      不正なイテレータを渡して削除した際の挙動テスト
            @details    ID:リスト-21\n
                        不正なイテレータを渡して削除した際の挙動を確認しています。\n
                        削除が正常に行われれなければ成功です。\n
        *//***********************************************************************************/
        TEST(EraseTest, TestInsertInvalid) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it(nullptr);
            bool success = list.Erase(it);
            EXPECT_TRUE(!success);
        }

        //=================================== 先頭イテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストの先頭イテレータ取得のテスト
            @details    ID:リスト-23\n
                        リストの先頭イテレータ取得のテストです。\n
                        リストが空である場合に、先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetBegin();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの先頭イテレータ取得のテスト
            @details    ID:リスト-24\n
                        リストに要素が一つある場合に、先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭イテレータ取得のテスト
            @details    ID:リスト-25\n
                        リストに二つ以上の要素がある場合に、先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭イテレータ取得のテスト
            @details    ID:リスト-26\n
                        データの挿入を行った後に、先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭イテレータ取得のテスト
            @details    ID:リスト-27\n
                        データの削除を行った後に、先頭イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetBegin();
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        //=================================== 先頭コンストイテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストの先頭コンストイテレータ取得のテスト
            @details    ID:リスト-29\n
                        リストの先頭コンストイテレータ取得のテストです。\n
                        リストが空である場合に、先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenEmptyConst) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator cit(nullptr);
            cit = list.GetBegin();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの先頭コンストイテレータ取得のテスト
            @details    ID:リスト-30\n
                        リストに要素が一つある場合に、先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenOneElementConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetBegin();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭コンストイテレータ取得のテスト
            @details    ID:リスト-31\n
                        リストに二つ以上の要素がある場合に、先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginWhenMultipleElementsConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetBegin();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭コンストイテレータ取得のテスト
            @details    ID:リスト-32\n
                        データの挿入を行った後に、先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterInsertConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetBegin();
            EXPECT_EQ(rd.score, (*cit).score);
            EXPECT_EQ(rd.username, (*cit).username);
        }

        /**********************************************************************************//**
            @brief      リストの先頭コンストイテレータ取得のテスト
            @details    ID:リスト-33\n
                        データの削除を行った後に、先頭コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(BeginIteratorTest, TestBeginAfterEraseConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Erase(list.GetBegin());
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetBegin();
            EXPECT_EQ(rd1.score, (*cit).score);
            EXPECT_EQ(rd1.username, (*cit).username);
        }

        //=================================== 末尾イテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストの末尾イテレータ取得のテスト
            @details    ID:リスト-35\n
                        リストの末尾イテレータ取得のテストです。\n
                        リストが空である場合に、末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetEnd();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾イテレータ取得のテスト
            @details    ID:リスト-36\n
                        リストに要素が一つある場合に、末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetEnd();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾イテレータ取得のテスト
            @details    ID:リスト-37\n
                        リストに二つ以上の要素がある場合に、末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetEnd();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾イテレータ取得のテスト
            @details    ID:リスト-38\n
                        データの挿入を行った後に、末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsert) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetEnd();
            EXPECT_EQ(it, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾イテレータ取得のテスト
            @details    ID:リスト-39\n
                        データの削除を行った後に、末尾イテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterErase) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            DoublyLinkedList::Iterator it(nullptr);
            it = list.GetEnd();
            EXPECT_EQ(it, list.GetEnd());
        }

        //=================================== 末尾コンストイテレータの取得 ===================================

        /**********************************************************************************//**
            @brief      リストの末尾コンストイテレータ取得のテスト
            @details    ID:リスト-41\n
                        リストの末尾イテレータ取得のテストです。\n
                        リストが空である場合に、末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenEmptyConst) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetEnd();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾コンストイテレータ取得のテスト
            @details    ID:リスト-42\n
                        リストに要素が一つある場合に、末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenOneElementConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetEnd();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾コンストイテレータ取得のテスト
            @details    ID:リスト-43\n
                        リストに二つ以上の要素がある場合に、末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndWhenMultipleElementsConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetEnd();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾コンストイテレータ取得のテスト
            @details    ID:リスト-44\n
                        データの挿入を行った後に、末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterInsertConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetEnd();
            EXPECT_EQ(cit, list.GetEnd());
        }

        /**********************************************************************************//**
            @brief      リストの末尾コンストイテレータ取得のテスト
            @details    ID:リスト-45\n
                        データの削除を行った後に、末尾コンストイテレータの取得が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(EndIteratorTest, TestEndAfterEraseConst) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Erase(list.GetBegin());
            DoublyLinkedList::ConstIterator cit(nullptr);
            cit = list.GetEnd();
            EXPECT_EQ(cit, list.GetEnd());
        }

        //=================================== イテレータの指す要素を取得する ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で要素を取得した際の挙動テスト
            @details    ID:イテレータ-0\n
                        リストが空または無効な状態で、イテレータから要素を取得した際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceWhenInvalid) {
            DoublyLinkedList::ConstIterator it(nullptr);
            EXPECT_THROW(*it, std::exception);
        }

        /**********************************************************************************//**
            @brief      Iteratorから取得した要素に対して、値の代入が行えるかをチェックするテスト
            @details    ID:イテレータ-1\n
                        Iteratorから取得した要素に対して、値の代入が可能であることを確認しています。\n
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
            @brief      リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
            @details    ID:イテレータ-3\n
                        リストが空の場合に、先頭イテレータから要素を取得しようとした際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtBeginWhenEmpty) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator it = list.GetBegin();
            EXPECT_THROW(*it, std::exception);
        }

        /**********************************************************************************//**
            @brief      末尾イテレータに対して呼び出した際の挙動テスト
            @details    ID:イテレータ-4\n
                        末尾イテレータから要素を取得しようとした際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorDereferenceTest, TestDereferenceAtEnd) {
            DoublyLinkedList list;
            DoublyLinkedList::ConstIterator it = list.GetEnd();
            EXPECT_THROW(*it, std::exception);
        }

        //=================================== イテレータをリストの末尾に向かって一つ進める ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で一つ進めた際の挙動テスト
            @details    ID:イテレータ-5\n
                        リストが空または無効な状態で、イテレータを進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenInvalid) {
            DoublyLinkedList::Iterator it(nullptr);
            EXPECT_THROW(++it, std::exception);
        }

        /**********************************************************************************//**
            @brief      リストが空の際の、先頭イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-6\n
                        リストが空の場合に、先頭イテレータを進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenEmpty) {
            DoublyLinkedList list;
            auto it = list.GetBegin();
            EXPECT_THROW(++it, std::exception);
        }

        /**********************************************************************************//**
            @brief      末尾イテレータに対して一つ進めた際の挙動テスト
            @details    ID:イテレータ-7\n
                        末尾イテレータからさらに進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceAtEnd) {
            DoublyLinkedList list;
            auto it = list.GetEnd();
            EXPECT_THROW(++it, std::exception);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-8\n
                        リストに複数の要素がある場合に、イテレータを一つ進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestAdvanceWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            bool success = false;
            while (it.current) {
                success = (*it).score == rd1.score;
                if (success) break;
                ++it;
            }
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      前置インクリメントを行った際の挙動テスト
            @details    ID:イテレータ-9\n
                        前置インクリメント（++演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreIncrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      後置インクリメントを行った際の挙動テスト
            @details    ID:イテレータ-10\n
                        後置インクリメント（++演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostIncrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        //=================================== イテレータをリストの先頭に向かって一つ進める ===================================

        /**********************************************************************************//**
            @brief      リストの参照がない状態で一つ進めた際の挙動テスト
            @details    ID:イテレータ-11\n
                        リストが空または無効な状態で、イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenInvalid) {
            DoublyLinkedList::Iterator it(nullptr);
            EXPECT_THROW(--it, std::exception);
        }

        /**********************************************************************************//**
            @brief      リストが空の際の、末尾イテレータを一つ進めた際の挙動テスト
            @details    ID:イテレータ-12\n
                        リストが空の場合に、末尾イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromEndWhenEmpty) {
            DoublyLinkedList list;
            auto it = list.GetEnd();
            EXPECT_THROW(--it, std::exception);
        }

        /**********************************************************************************//**
            @brief      先頭イテレータに対して一つ進めた際の挙動テスト
            @details    ID:イテレータ-13\n
                        先頭イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardFromBegin) {
            DoublyLinkedList list;
            auto it = list.GetBegin();
            EXPECT_THROW(--it, std::exception);
        }

        /**********************************************************************************//**
            @brief      リストに二つ以上の要素がある場合に、一つ進めた際の挙動テスト
            @details    ID:イテレータ-14\n
                        リストに複数の要素がある場合に、イテレータを逆に進めた際の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestBackwardWhenMultipleElements) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            ++it;
            bool success = false;
            while (it.current) {
                success = (*it).score == rd.score;
                if (success) break;
                --it;
            }
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      前置デクリメントを行った際の挙動テスト
            @details    ID:イテレータ-15\n
                        前置デクリメント（--演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPreDecrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      後置デクリメントを行った際の挙動テスト
            @details    ID:イテレータ-16\n
                        後置デクリメント（--演算子オーバーロード）の挙動を確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAdvanceTest, TestPostDecrement) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            --it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        //=================================== イテレータのコピーを行う ===================================

        /**********************************************************************************//**
            @brief      コピーコンストラクト後の値がコピー元と等しいことをチェックするテスト
            @details    ID:イテレータ-18\n
                        コピーコンストラクト後のイテレータの値がコピー元と等しいことを確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorCopyTest, TestCopyConstructor) {
            DoublyLinkedList list;
            list.Insert(list.GetEnd(), rd);
            auto it(list.GetBegin());
            EXPECT_EQ((*it).score, rd.score);
            EXPECT_EQ((*it).username, rd.username);
        }

        //=================================== イテレータの代入を行う ===================================

        /**********************************************************************************//**
            @brief      代入後の値がコピー元と等しいことをチェックするテスト
            @details    ID:イテレータ-20\n
                        代入後のイテレータの値がコピー元と等しいことを確認しています。\n
        *//***********************************************************************************/
        TEST(IteratorAssignmentTest, TestAssignment) {
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
            DoublyLinkedList list;
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
