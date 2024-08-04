#include <iostream>
#include <fstream>
#include <string>

// �o�������X�g���̃m�[�h���`
struct Node {
    // �X�R�A
    int score;
    // ���[�U�[��
    std::string username;
    // ���̃m�[�h�ւ̃|�C���^
    Node* next;
    // �O�̃m�[�h�ւ̃|�C���^
    Node* prev;

    Node(int score, std::string& username) : score(score), username(username), next(nullptr), prev(nullptr) {}
};

// �o�������X�g�N���X��錾
class DoublyLinkedList {
private:
    // ���X�g�̐擪
    Node* head;
    // ���X�g�̖���
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // �m�[�h��ǉ�����
    void append(int score, std::string& username) {
        Node* newNode = new Node(score, username);

        // �擪��������ΐ擪���쐬����
        if (!head) {
            head = tail = newNode;
        }
        // �擪������Ζ����Ƀm�[�h��ǉ�
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // �X�R�A�ƃ��[�U�[����\������
    void printList() const {
        Node* current = head;

        // �X�R�A�ƃ��[�U�[����W���o�͂ɕ\��
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

    // �t�@�C�����擾
    std::ifstream file("Scores.txt");

    // �t�@�C����������΃G���[�����o��
    if (!file.is_open()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    int score;
    std::string username;

    // �t�@�C������W�����͂��󂯎��
    while (file >> score >> username) {
        // ���X�g�ɒǉ�
        list.append(score, username);
    }

    // ���X�g�̒��g��\��
    list.printList();

    // �t�@�C�������
    file.close();

    return 0;
}