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
//    ������ѭ����
    while (true) {
        GameControl game_controler(make_shared<Player>(1), make_shared<Player>(2),
                                   make_shared<Board>());
        Menu::print();
        if (Menu::choose() == 2)
            break;
        game_controler.start();//��Ϸ��ѭ����
        game_controler.game_over();//һ����Ϸ����ʱ���д���
    }

    return 0;
}