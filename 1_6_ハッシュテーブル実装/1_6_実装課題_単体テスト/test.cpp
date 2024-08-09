#include "pch.h"
#include "HashTable.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        std::string key = "User";
        std::string key1 = "User1";
        std::string key2 = "User2";
        std::string sameKey = "Same";
        int value = 100;
        int value1 = 200;
        int value2 = 300;
        int seaValue;

        struct HashFunction {
            size_t operator()(const std::string& key) const {
                return key.length() % 10;
            }
        };

        struct HashFunction1 {
            size_t operator()(const std::string& key) const {
                return key.length() % 2;
            }
        };

        struct InvalidHashFunction {
            void operator()(const std::string& key) const {
                return;
            }
        };

        //=================================== クラスの挙動 ===================================

        /**********************************************************************************//**
            @brief		不適切なハッシュ関数がテンプレート引数で渡された時の挙動
            @details	ID:-0(手動)\n
                        不適切なハッシュ関数がテンプレート引数で渡された時の挙動を確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTableInvalid)
        {
#if defined TT_TEST_MANUAL
            HashTable<std::string, int, InvalidHashFunction, 10> table;
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief		算出方法の異なる適切なハッシュ関数を渡したときのそれぞれの挙動
            @details	ID:-1\n
                        算出方法の異なる適切なハッシュ関数を渡したときのそれぞれの挙動を確認しています。\n
                        挿入、検索、削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTable)
        {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
            success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            success = table.Erase(key);
            EXPECT_TRUE(success);

            HashTable<std::string, int, HashFunction1, 10> table1;
            success = table1.Insert(key, value);
            EXPECT_TRUE(success);
            success = table1.Search(key, seaValue);
            EXPECT_TRUE(success);
            success = table1.Erase(key);
            EXPECT_TRUE(success);
        }

        //=================================== データ数の取得 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合のデータ数の取得テスト
            @details    ID:-2\n
                        リストが空である場合の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素を挿入した時のデータ数の取得テスト
            @details    ID:-3\n
            @brief      要素を挿入した時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterPush) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素を挿入し、そのキーで削除した時のデータ数の取得テスト
            @details    ID:-4\n
            @brief      要素を挿入し、そのキーで削除した時の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterErase) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      既に存在するキーで要素の挿入をし失敗した時のデータ数の取得テスト
            @details    ID:-5\n
            @brief      既に存在するキーで要素の挿入をし失敗した時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterInsertFailedWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key, value1);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストに要素がある時に存在しないキーを指定し要素の削除に失敗した時のデータ数の取得テスト
            @details    ID:-6\n
            @brief      リストに要素がある時に存在しないキーを指定し要素の削除に失敗した時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseFailedWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key1);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      リストが空である場合に、削除を行った後のデータ数の取得テスト
            @details    ID:-7\n
                        リストが空である場合に、削除を行った後の戻り値を確認しています。\n
                        データ数が0であれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumAfterEraseWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Erase(key);
            EXPECT_EQ(0, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素２つが内部でチェインになっていない時のデータ数の取得テスト
            @details    ID:-8\n
            @brief      要素２つが内部でチェインになっていない時の戻り値を確認しています。\n
                        データ数が2増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataWhenNonChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            EXPECT_EQ(2, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素２つが内部でチェインになっていない時に一方を削除した時のデータ数の取得テスト
            @details    ID:-9\n
            @brief      要素２つが内部でチェインになっていない時に一方を削除した時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseWhenNonChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            table.Erase(key);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素２つが内部でチェインになった後のデータ数の取得テスト
            @details    ID:-10\n
            @brief      要素２つが内部でチェインになった後の戻り値を確認しています。\n
                        データ数が2増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            EXPECT_EQ(2, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      要素２つが内部でチェインになっている時に一方を削除した時のデータ数の取得テスト
            @details    ID:-11\n
            @brief      要素２つが内部でチェインになっていない時に一方を削除した時の戻り値を確認しています。\n
                        データ数が1増えていれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataAfterEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            table.Erase(key);
            EXPECT_EQ(1, table.GetDataNum());
        }

        /**********************************************************************************//**
            @brief		データ数の取得機能について、constのメソッドであるかのテスト
            @details	ID:-12(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestGetDataNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.GetDataNum();
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データの挿入 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、挿入した時の挙動テスト
            @details    ID:-13\n
                        リストが空である場合に、挿入した時の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、キーが重複しないで挿入した時の挙動テスト
            @details    ID:-14\n
                        リストに複数の要素がある場合に、キーが重複しないで挿入した時の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenNonDuplicated) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Insert(key2, value2);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、キーが重複して挿入しようとした時の挙動テスト
            @details    ID:-15\n
                        リストに複数の要素がある場合に、キーが重複して挿入しようとした時の挙動を確認しています。\n
                        挿入が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenDuplicated) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Insert(key, value2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      既にリストにある要素とハッシュ値が同じになるキーで挿入した時の挙動テスト
            @details    ID:-16\n
                        既にリストにある要素とハッシュ値が同じになるキーで挿入した時の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertSameKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            bool success = table.Insert(sameKey, value1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      一度挿入し、削除した後再度同じキーで挿入した時の挙動テスト
            @details    ID:-17\n
                        一度挿入し、削除した後再度同じキーで挿入した時の挙動を確認しています。\n
                        挿入が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertAfterInsertAndErase) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Insert(key, value1);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		挿入について、非constのメソッドであるかのテスト
            @details	ID:-18(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestInsertWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データの削除 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、削除操作をしようとした時の挙動テスト
            @details    ID:-19\n
                        リストが空である場合に、削除操作をしようとした時の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Erase(key);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、存在するキーで指定して削除した時の挙動テスト
            @details    ID:-20\n
                        リストに複数の要素がある場合に、存在するキーで指定して削除した時の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、存在しないキーで指定して削除しようとした時の挙動テスト
            @details    ID:-21\n
                        リストに複数の要素がある場合に、存在しないキーで指定して削除しようとした時の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Erase(key2);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      一度削除したキーで再度削除しようとした時の挙動テスト
            @details    ID:-22\n
                        一度削除したキーで再度削除しようとした時の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenErasedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Erase(key);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      チェインになっている要素うちの1つのキーを指定して削除した時の挙動テスト
            @details    ID:-23\n
                        チェインになっている要素うちの1つのキーを指定して削除した時の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief      チェインになっている要素とハッシュ値が同じだが、存在しないキーを指定して削除した時の挙動テスト
            @details    ID:-24\n
                        チェインになっている要素とハッシュ値が同じだが、存在しないキーを指定して削除した時の挙動を確認しています。\n
                        削除が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenChainWhenSameKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            bool success = table.Erase(sameKey);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      チェインになっている要素を順に削除していった時の挙動テスト
            @details    ID:-25\n
                        チェインになっている要素を順に削除していった時の挙動を確認しています。\n
                        削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseMultipleWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value);
            bool success = table.Erase(key);
            EXPECT_TRUE(success);
            success = table.Erase(sameKey);
            EXPECT_TRUE(success);
        }

        /**********************************************************************************//**
            @brief		削除について、非constのメソッドであるかのテスト
            @details	ID:-26(手動)\n
                        非constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルエラーになれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestEraseWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Erase(key);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        //=================================== データの検索 ===================================

        /**********************************************************************************//**
            @brief      リストが空である場合に、キーを指定して検索した時の挙動テスト
            @details    ID:-27\n
                        リストが空である場合に、キーを指定して検索した時の挙動を確認しています。\n
                        検索が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenEmpty) {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、存在するキーで指定して検索した時の挙動テスト
            @details    ID:-28\n
                        リストに複数の要素がある場合に、存在するキーで指定して検索した時の挙動を確認しています。\n
                        検索が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、存在しないキーで指定して検索した時の挙動テスト
            @details    ID:-29\n
                        リストに複数の要素がある場合に、存在しないキーで指定して検索した時の挙動を確認しています。\n
                        検索が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenNonExistedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key2, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      リストに複数の要素がある場合に、同じキーで2連続で検索した時の挙動テスト
            @details    ID:-30\n
                        リストに複数の要素がある場合に、同じキーで2連続で検索した時の挙動を確認しています。\n
                        検索が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchTwice) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(key1, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
            success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      既に削除されたキーで検索した時の挙動テスト
            @details    ID:-31\n
                        既に削除されたキーで検索した時の挙動を確認しています。\n
                        検索が正常に行われなければ成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenErasedKey) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Erase(key);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(!success);
        }

        /**********************************************************************************//**
            @brief      チェインになっている要素の内の1つのキーを指定して検索した時の挙動テスト
            @details    ID:-32\n
                        チェインになっている要素の内の1つのキーを指定して検索した時の挙動を確認しています。\n
                        検索が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            bool success = table.Search(key, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value, seaValue);
        }

        /**********************************************************************************//**
            @brief      チェインになっている要素うちの1つの削除した後に、残っている要素を検索した時の挙動テスト
            @details    ID:-33\n
                        チェインになっている要素うちの1つの削除した後に、残っている要素を検索した時の挙動を確認しています。\n
                        検索が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchAfterEraseWhenChain) {
            HashTable<std::string, int, HashFunction, 10> table;
            table.Insert(key, value);
            table.Insert(sameKey, value1);
            table.Erase(key);
            bool success = table.Search(sameKey, seaValue);
            EXPECT_TRUE(success);
            EXPECT_EQ(value1, seaValue);
        }

        /**********************************************************************************//**
            @brief		検索について、constのメソッドであるかのテスト
            @details	ID:-34(手動)\n
                        constのメソッドであるかを確認しています。\n
                        有効にしてコンパイルが通れば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestSearchNumWhenConst)
        {
#if defined TT_TEST_MANUAL
            const HashTable<std::string, int, HashFunction, 10> table;
            table.Search(key, seaValue);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure