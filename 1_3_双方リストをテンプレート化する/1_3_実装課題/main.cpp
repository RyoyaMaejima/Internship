#include "DoublyLinkedList.h"
#include "ResultData.h"
#include <fstream>

int main() {
    DoublyLinkedList<ResultData> list;

    // �t�@�C�����擾
    std::ifstream file("Scores.txt");

    // �t�@�C����������΃G���[�����o��
    if (!file.is_open()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    ResultData data;

    // �t�@�C������W�����͂��󂯎��
    while (file >> data.score >> data.username) {
        data = { data.score, data.username };
        // ���X�g�ɒǉ�
        list.Insert(list.GetEnd(), data);
    }

    // ���X�g�̒��g��\��
    DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
    while (it != list.GetEnd()) {
        std::cout << (*it).score << "\t" << (*it).username << std::endl;
        ++it;
    }

    // �t�@�C�������
    file.close();

    return 0;
}