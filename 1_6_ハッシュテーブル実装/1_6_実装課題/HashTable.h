#pragma once

#include "DoublyLinkedList.h"
#include "Pair.h"

/**
 * @brief チェイン式ハッシュテーブルクラス
 * @tparam K キーの型
 * @tparam V 値の型
 * @tparam HF ハッシュ関数の型
 * @tparam BucketSize ハッシュテーブルのバケットサイズ
 */
template<typename K, typename V, typename HF, size_t BucketSize>
class HashTable {
private:
    DoublyLinkedList<Pair<K, V>> table[BucketSize];    /**< チェイン式ハッシュテーブル */
    HF hashFunction;    /**< ハッシュ関数 */
    size_t dataNum;    /**< データ数 */

public:
    /**
     * @brief コンストラクタ
     */
    HashTable();

    /**
     * @brief データ数の取得
     * @return データ数
     */
    size_t GetDataNum() const;

    /**
     * @brief キーと値のペアをハッシュテーブルに挿入する
     * @param key キー
     * @param value 値
     * @return 挿入が成功すればtrue、キーが重複するとfalse
     */
    bool Insert(const K& key, const V& value);

    /**
     * @brief キーに対応する値を削除する
     * @param key キー
     * @return 削除が成功すればtrue、キーが存在しないとfalse
     */
    bool Erase(const K& key);

    /**
     * @brief キーに対応する値を検索する
     * @param key キー
     * @param value 探索した値を格納する変数
     * @return キーが見つかればtrue、見つからなければfalse
     */
    bool Search(const K& key, V& value) const;
};

#include "HashTable.inl"