#include <iostream>
#include <cstdlib>
#include <memory>
#include "../headers/Board.h"
#include "../headers/GameControl.h"
#include "../headers/Player.h"
#include "../headers/Referee.h"
#include "../headers/System.h"
#include "../headers/Menu.h"

using namespace std;

int main() {
//    主控制循环体
    while (true) {
        GameControl game_controler(make_shared<Player>(1), make_shared<Player>(2),
                                   make_shared<Board>());
        Menu::print();
        if (Menu::choose() == 2)
            break;
        game_controler.start();//游戏主循环体
        game_controler.game_over();//一局游戏结束时进行处理
    }

    return 0;
}