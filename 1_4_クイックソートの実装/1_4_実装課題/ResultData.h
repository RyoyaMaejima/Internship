#pragma once

#include <iostream>
#include <string>

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

/**
* @brief �X�R�A�Ɋ�Â��ď����Ƀ\�[�g���邽�߂̔�r�֐�
* @param a 1�ڂ�ResultData�I�u�W�F�N�g
* @param b 2�ڂ�ResultData�I�u�W�F�N�g
* @return a�̃X�R�A��b�̃X�R�A��菬�����ꍇ��true
*/
bool compareScoreAs(const ResultData& a, const ResultData& b) {
    return a.score < b.score;
}

/**
* @brief �X�R�A�Ɋ�Â��č~���Ƀ\�[�g���邽�߂̔�r�֐�
* @param a 1�ڂ�ResultData�I�u�W�F�N�g
* @param b 2�ڂ�ResultData�I�u�W�F�N�g
* @return a�̃X�R�A��b�̃X�R�A���傫���ꍇ��true
*/
bool compareScoreDs(const ResultData& a, const ResultData& b) {
    return a.score > b.score;
}

/**
* @brief ���[�U�[���Ɋ�Â��ď����Ƀ\�[�g���邽�߂̔�r�֐�
* @param a 1�ڂ�ResultData�I�u�W�F�N�g
* @param b 2�ڂ�ResultData�I�u�W�F�N�g
* @return a�̃��[�U�[����b�̃��[�U�[����菬�����ꍇ��true
*/
bool compareUsernameAs(const ResultData& a, const ResultData& b) {
    return a.username < b.username;
}

/**
* @brief ���[�U�[���Ɋ�Â��č~���Ƀ\�[�g���邽�߂̔�r�֐�
* @param a 1�ڂ�ResultData�I�u�W�F�N�g
* @param b 2�ڂ�ResultData�I�u�W�F�N�g
* @return a�̃��[�U�[����b�̃��[�U�[�����傫���ꍇ��true
*/
bool compareUsernameDs(const ResultData& a, const ResultData& b) {
    return a.username > b.username;
}

/**
* @brief �X�R�A�Ɋ�Â��ď����Ƀ\�[�g���邽�߂̔�r�֐�
* @param a 1�ڂ�ResultData�I�u�W�F�N�g
* @param b 2�ڂ�ResultData�I�u�W�F�N�g
* @return a�̃X�R�A��b�̃X�R�A��菬�����ꍇ��true
*/
bool compareScore(const ResultData& a, const ResultData& b) {
    return a.score < b.score;
}