#include "DoublyLinkedList.h"
#include <fstream>

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
        ResultData data = { score, username };
        // ���X�g�ɒǉ�
        list.Insert(list.GetEnd(), data);
    }

    // ���X�g�̒��g��\��
    DoublyLinkedList::Iterator it = list.GetBegin();
    while (it.current) {
        std::cout << (*it).score << "\t" << (*it).username << std::endl;
        ++it;
    }

    // �t�@�C�������
    file.close();

    return 0;
}