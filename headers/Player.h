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
    int sente;//�Ⱥ���

    //pair<int,int> decision();//������ҽ��о���
private:
//    void move_coord(Board& board);
};

#endif //gomoku_PLAYER_H
