#include "../headers/Referee.h"
#include "../headers/Board.h"
#include <utility>

bool Referee::judge(Board &board, int who) {
    int move[4][2] = {
            {0, 1},
            {1, 0},
            {1, 1},
            {1, -1}
    };//以向右/向下/副对角线向左下为基本正方向,[4]:横,竖,主对角线,副对角线
    std::pair<int, int> pre_coord = board.last_position();
    std::pair<int, int> temp_coord;
    for (auto line: move) {
        int sum = -1;//-1用于解决中间点重复计算的问题
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
        if (sum == 5) return true;//五子连珠,游戏结束
    }
    return false;//每一个方向都没有五子连珠,游戏继续
}
