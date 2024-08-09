#include "pch.h"
#include "HashTable.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        std::string key = "User";
        std::string key1 = "User1";
        std::string sameKey = "Same";
        int value = 100;
        int value1 = 200;
        int sValue;

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
                        挿入、探索、削除が正常に行われれば成功です。\n
        *//***********************************************************************************/
        TEST(HashTableTest, TestHashTable)
        {
            HashTable<std::string, int, HashFunction, 10> table;
            bool success = table.Insert(key, value);
            EXPECT_TRUE(success);
            success = table.Search(key, sValue);
            EXPECT_TRUE(success);
            success = table.Erase(key);
            EXPECT_TRUE(success);

            HashTable<std::string, int, HashFunction1, 10> table1;
            success = table1.Insert(key, value);
            EXPECT_TRUE(success);
            success = table1.Search(key, sValue);
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

    } // namespace chapter2
} // namespace ex01_DataStructure