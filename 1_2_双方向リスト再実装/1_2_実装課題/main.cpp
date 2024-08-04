#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    DoublyLinkedList list;

    // ファイルを取得
    std::ifstream file("Scores.txt");

    // ファイルが無ければエラー文を出力
    if (!file.is_open()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    int score;
    std::string username;

    // ファイルから標準入力を受け取る
    while (file >> score >> username) {
        ResultData data = { score, username };
        // リストに追加
        list.Insert(list.GetEnd(), data);
    }

    // リストの中身を表示
    list.PrintList();

    // ファイルを閉じる
    file.close();

    return 0;
}