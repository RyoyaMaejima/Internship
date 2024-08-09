#pragma once

#include <string>
#include <iostream>

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