#pragma once

#include <string>

/**
 * @brief キーと値を格納するための構造体
 * @tparam K キーの型
 * @tparam V 値の型
 */
template<typename K, typename V>
struct Pair {
    K key;
    V value;

    Pair(const K& key, const V& value) : key(key), value(value) {}
};