#pragma once

#include <string>

/**
 * @brief �L�[�ƒl���i�[���邽�߂̍\����
 * @tparam K �L�[�̌^
 * @tparam V �l�̌^
 */
template<typename K, typename V>
struct Pair {
    K key;
    V value;

    Pair(const K& key, const V& value) : key(key), value(value) {}
};