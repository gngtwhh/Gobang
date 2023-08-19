//
// Created by admin on 2023/6/11.
//

#ifndef gomoku_PLAYER_H
#define gomoku_PLAYER_H
#include "Board.h"
class Player {
public:
    Player(int s) : sente(s) {}
    void set_piece(Board&board);
    int sente;//先后手

    //pair<int,int> decision();//电脑玩家进行决策
private:
//    void move_coord(Board& board);
};

#endif //gomoku_PLAYER_H
