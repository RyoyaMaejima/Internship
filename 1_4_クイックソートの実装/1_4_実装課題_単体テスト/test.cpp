#include "pch.h"
#include "DoublyLinkedList.h"
#include "ResultData.h"

namespace ex01_DataStructure {
    namespace chapter2 {

        ResultData rd = { 100, "User" };
        ResultData rd1 = { 200, "User1" };
        ResultData rd2 = { 300, "User2" };

        bool compareInvalid(const std::string& a, const std::string& b) {
            return a < b;
        }

        /**********************************************************************************//**
            @brief      �v�f�������Ȃ����X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details    ID:-0\n
                        �v�f�������Ȃ����X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortEmpty) {
            DoublyLinkedList<ResultData> list;

            list.Sort(compareScoreAs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareScoreDs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareUsernameAs);
            EXPECT_EQ(0, list.GetDataNum());

            list.Sort(compareUsernameDs);
            EXPECT_EQ(0, list.GetDataNum());
        }

        /**********************************************************************************//**
            @brief      �v�f���P���������X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details    ID:-1\n
                        �v�f���P���������X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortOneElement) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            auto it = list.GetBegin();

            list.Sort(compareScoreAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareScoreDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareUsernameAs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list.Sort(compareUsernameDs);
            EXPECT_EQ(1, list.GetDataNum());
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		�Q�ȏ�v�f�������X�g�Ƀ\�[�g�����s�����Ƃ��̋����e�X�g
            @details	ID:-2\n
                        �Q�ȏ�v�f�������X�g�Ƀ\�[�g�����s�����Ƃ��̋������m�F���Ă��܂��B\n
                        �v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortMultipleElements)
        {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            
            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      �����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋����e�X�g
            @details    ID:-3\n
                        �����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋������m�F���Ă��܂��B\n
                        �v�f���\�[�g����ĕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortSameKey) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);

            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋����e�X�g
            @details	ID:-4\n
                        ����ς݃��X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
                        ���Ԃ��ϓ����Ȃ���ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortSortedList)
        {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);

            auto it = list.GetBegin();
            list.Sort(compareScoreAs);
            list.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareScoreDs);
            list.Sort(compareScoreDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameAs);
            list.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);

            it = list.GetBegin();
            list.Sort(compareUsernameDs);
            list.Sort(compareUsernameDs);
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief      ��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋����e�X�g
            @details    ID:-5\n
                        ��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋������m�F���Ă��܂��B\n
                        �v�f���\�[�g����ĕ��ׂΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortResort) {
            DoublyLinkedList<ResultData> list1;
            DoublyLinkedList<ResultData> list2;
            DoublyLinkedList<ResultData> list3;
            DoublyLinkedList<ResultData> list4;
            list1.Insert(list1.GetEnd(), rd);
            list1.Insert(list1.GetEnd(), rd1);
            list2.Insert(list2.GetEnd(), rd);
            list2.Insert(list2.GetEnd(), rd1);
            list3.Insert(list3.GetEnd(), rd);
            list3.Insert(list3.GetEnd(), rd1);
            list4.Insert(list4.GetEnd(), rd);
            list4.Insert(list4.GetEnd(), rd1);

            list1.Sort(compareScoreAs);
            list1.Insert(list1.GetBegin(), rd2);
            auto it = list1.GetBegin();
            list1.Sort(compareScoreAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);

            list2.Sort(compareScoreDs);
            list2.Insert(list2.GetBegin(), rd2);
            it = list2.GetBegin();
            list2.Sort(compareScoreDs);
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);

            list3.Sort(compareUsernameAs);
            list3.Insert(list3.GetBegin(), rd2);
            it = list3.GetBegin();
            list3.Sort(compareUsernameAs);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);

            list4.Sort(compareUsernameDs);
            list4.Insert(list4.GetBegin(), rd2);
            it = list4.GetBegin();
            list4.Sort(compareUsernameDs);
            EXPECT_EQ(rd2.score, (*it).score);
            EXPECT_EQ(rd2.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
            ++it;
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		�L�[�w������Ȃ��������̋����e�X�g
            @details	ID:-6\n
                        �L�[�w������Ȃ��������̋������m�F���Ă��܂��B\n
                        ���X�g�ɉ����N����Ȃ���΂ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortNullKey) {
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();

            list.Sort(nullptr);
            EXPECT_EQ(rd.score, (*it).score);
            EXPECT_EQ(rd.username, (*it).username);
            ++it;
            EXPECT_EQ(rd1.score, (*it).score);
            EXPECT_EQ(rd1.username, (*it).username);
        }

        /**********************************************************************************//**
            @brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋����e�X�g
            @details	ID:-7(�蓮)\n
                        �^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋������m�F���Ă��܂��B\n
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortInvalid)
        {
#if defined TT_TEST_MANUAL
            DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            auto it = list.GetBegin();
            list.Sort(compareInvalid);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

        /**********************************************************************************//**
            @brief		�\�[�g�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
            @details	ID:-8(�蓮)\n
                        ��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B
                        �L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
        *//***********************************************************************************/
        TEST(QuickSortTest, TestQuickSortConst)
        {
#if defined TT_TEST_MANUAL
            const DoublyLinkedList<ResultData> list;
            list.Insert(list.GetEnd(), rd);
            list.Insert(list.GetEnd(), rd1);
            list.Sort(compareScoreAs);
#endif //TT_TEST_MANUAL
            SUCCEED();
        }

    } // namespace chapter2
} // namespace ex01_DataStructure