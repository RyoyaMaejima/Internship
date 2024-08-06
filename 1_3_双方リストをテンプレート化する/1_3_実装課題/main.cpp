#include "DoublyLinkedList.h"
#include "ResultData.h"
#include <fstream>

int main() {
    DoublyLinkedList<ResultData> list;

    // ファイルを取得
    std::ifstream file("Scores.txt");

    // ファイルが無ければエラー文を出力
    if (!file.is_open()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    ResultData data;

    // ファイルから標準入力を受け取る
    while (file >> data.score >> data.username) {
        data = { data.score, data.username };
        // リストに追加
        list.Insert(list.GetEnd(), data);
    }

    // リストの中身を表示
    DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
    while (it != list.GetEnd()) {
        std::cout << (*it).score << "\t" << (*it).username << std::endl;
        ++it;
    }

    // ファイルを閉じる
    file.close();

    return 0;
}