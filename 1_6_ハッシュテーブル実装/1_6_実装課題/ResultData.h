#pragma once

#include <string>
#include <iostream>

/**
 * @brief ���уf�[�^
 */
struct ResultData {
    int score;          /**< �X�R�A */
    std::string username; /**< ���[�U�[�� */

    /**
     * @brief �X�g���[����ResultData��}�����鉉�Z�q
     * @param os �o�̓X�g���[��
     * @param rd ResultData�I�u�W�F�N�g
     * @return �o�̓X�g���[��
     */
    friend std::ostream& operator<<(std::ostream& os, const ResultData& rd) {
        os << rd.score << '\t' << rd.username;
        return os;
    }
};