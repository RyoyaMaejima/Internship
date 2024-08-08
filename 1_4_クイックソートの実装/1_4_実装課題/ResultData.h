#pragma once

#include <iostream>
#include <string>

/**
 * @brief 成績データ
 */
struct ResultData {
    int score;          /**< スコア */
    std::string username; /**< ユーザー名 */

    /**
     * @brief ストリームにResultDataを挿入する演算子
     * @param os 出力ストリーム
     * @param rd ResultDataオブジェクト
     * @return 出力ストリーム
     */
    friend std::ostream& operator<<(std::ostream& os, const ResultData& rd) {
        os << rd.score << '\t' << rd.username;
        return os;
    }
};

/**
* @brief スコアに基づいて昇順にソートするための比較関数
* @param a 1つ目のResultDataオブジェクト
* @param b 2つ目のResultDataオブジェクト
* @return aのスコアがbのスコアより小さい場合にtrue
*/
bool compareScoreAs(const ResultData& a, const ResultData& b) {
    return a.score < b.score;
}

/**
* @brief スコアに基づいて降順にソートするための比較関数
* @param a 1つ目のResultDataオブジェクト
* @param b 2つ目のResultDataオブジェクト
* @return aのスコアがbのスコアより大きい場合にtrue
*/
bool compareScoreDs(const ResultData& a, const ResultData& b) {
    return a.score > b.score;
}

/**
* @brief ユーザー名に基づいて昇順にソートするための比較関数
* @param a 1つ目のResultDataオブジェクト
* @param b 2つ目のResultDataオブジェクト
* @return aのユーザー名がbのユーザー名より小さい場合にtrue
*/
bool compareUsernameAs(const ResultData& a, const ResultData& b) {
    return a.username < b.username;
}

/**
* @brief ユーザー名に基づいて降順にソートするための比較関数
* @param a 1つ目のResultDataオブジェクト
* @param b 2つ目のResultDataオブジェクト
* @return aのユーザー名がbのユーザー名より大きい場合にtrue
*/
bool compareUsernameDs(const ResultData& a, const ResultData& b) {
    return a.username > b.username;
}

/**
* @brief スコアに基づいて昇順にソートするための比較関数
* @param a 1つ目のResultDataオブジェクト
* @param b 2つ目のResultDataオブジェクト
* @return aのスコアがbのスコアより小さい場合にtrue
*/
bool compareScore(const ResultData& a, const ResultData& b) {
    return a.score < b.score;
}