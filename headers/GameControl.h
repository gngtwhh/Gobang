#ifndef gomoku_GAMECONTROL_H
#define gomoku_GAMECONTROL_H

#include <memory>
#include <utility>
#include "Player.h"
#include "Board.h"

//������Ϸ���ݶ��洢��GameControl��һ��ʵ����������
class GameControl {
public:
    GameControl(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, std::shared_ptr<Board> b) :
            player1(std::move(p1)), player2(std::move(p2)), board(std::move(b)) {}
    GameControl()=default;
    void start();
    void game_over();

    int count = 0;
    int winner = -1;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Board> board;
private:
    void game_init();
};

#endif //gomoku_GAMECONTROL_H
