#include <iostream>
#include "../headers/Player.h"
#include "../headers/Board.h"

void Player::set_piece(Board &board) {
    int direction;
    while (true) {
        direction = System::keyboard();
        if (direction == 5) {
            if (board.move_in_board(sente))
                break;
        } else if (direction != 0)
            board.move_coord(direction);
    }
}

//pair<int,int> decision();//电脑玩家进行决策