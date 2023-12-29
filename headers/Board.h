//
// Created by admin on 2023/6/11.
//

#ifndef gomoku_BOARD_H
#define gomoku_BOARD_H

#include <string>
#include <map>
#include "System.h"
#include "Referee.h"
class Board {
public:
    friend bool Referee::judge(Board &board,int who);

    Board();

    void print_board();
    void clear_board();

    void move_coord(int direction);
    void move_coord(int x, int y);

    bool move_in_board(int who);//返回值用于判断是否正确落子---玩家选择落子的地方可能已有棋子
    std::pair<int,int> last_position();//返回最后一次落子的坐标

    std::string piece[2]={"●","○"};//黑先白后
    int maxcoord_x = 14 * 4;
    int maxcoord_y = 14 * 2;
private:
    void print_cursor();
    void clear_cursor();
    std::map<char, int> coords;//当前的坐标
    int record[15][15] = {-1};//注意,两个维度不跟随系统控制台光标,需要调换
    const char *corners[4] = {"┏", "┓", "┗", "┛"};//左上,右上,左下,右下
};
#endif //gomoku_BOARD_H
