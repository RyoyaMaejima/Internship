#include <iostream>
#include <fstream>
#include <string>

// 双方向リスト内のノードを定義
struct Node {
    // スコア
    int score;
    // ユーザー名
    std::string username;
    // 次のノードへのポインタ
    Node* next;
    // 前のノードへのポインタ
    Node* prev;

    Node(int score, std::string& username) : score(score), username(username), next(nullptr), prev(nullptr) {}
};

// 双方向リストクラスを宣言
class DoublyLinkedList {
private:
    // リストの先頭
    Node* head;
    // リストの末尾
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // ノードを追加する
    void append(int score, std::string& username) {
        Node* newNode = new Node(score, username);

        // 先頭が無ければ先頭を作成する
        if (!head) {
            head = tail = newNode;
        }
        // 先頭があれば末尾にノードを追加
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // スコアとユーザー名を表示する
    void printList() const {
        Node* current = head;

        // スコアとユーザー名を標準出力に表示
        while (current) {
            std::cout << current->score << "\t" << current->username << std::endl;
            current = current->next;
        }
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

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
        // リストに追加
        list.append(score, username);
    }

    // リストの中身を表示
    list.printList();

    // ファイルを閉じる
    file.close();

    return 0;
}