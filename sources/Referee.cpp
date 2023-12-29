#include "../headers/Referee.h"
#include "../headers/Board.h"
#include <utility>

bool Referee::judge(Board &board, int who) {
    int move[4][2] = {
            {0, 1},
            {1, 0},
            {1, 1},
            {1, -1}
    };//������/����/���Խ���������Ϊ����������,[4]:��,��,���Խ���,���Խ���
    std::pair<int, int> pre_coord = board.last_position();
    std::pair<int, int> temp_coord;
    for (auto line: move) {
        int sum = -1;//-1���ڽ���м���ظ����������
        temp_coord = pre_coord;
        while (board.record[temp_coord.first][temp_coord.second] == who
               && temp_coord.first >= 0 && temp_coord.first <= 14
               && temp_coord.second >= 0 && temp_coord.second <= 14) {
            ++sum;
            temp_coord.first += line[0];
            temp_coord.second += line[1];
        }
        temp_coord = pre_coord;
        while (board.record[temp_coord.first][temp_coord.second] == who
               && temp_coord.first >= 0 && temp_coord.first <= 14
               && temp_coord.second >= 0 && temp_coord.second <= 14) {
            ++sum;
            temp_coord.first -= line[0];
            temp_coord.second -= line[1];
        }
        if (sum == 5) return true;//��������,��Ϸ����
    }
    return false;//ÿһ������û����������,��Ϸ����
}
