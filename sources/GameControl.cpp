#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../headers/GameControl.h"
#include "../headers/Referee.h"

using namespace std;

void GameControl::game_init() {
    system("cls");
    board->print_board();

}

void GameControl::start() {
    Referee referee;
    game_init();
    while (true) {
        System::gotoxy(board->maxcoord_x + 2, board->maxcoord_y / 2);
        cout << "轮到 player " << board->piece[player1->sente - 1] << " 落子!";
        player1->set_piece(*board);
        if (referee.judge(*board, 1)) {
            winner = 1;
            break;
        }

        System::gotoxy(board->maxcoord_x + 2, board->maxcoord_y / 2);
        cout << "轮到 player " << board->piece[player2->sente - 1] << " 落子!";
        player2->set_piece(*board);
        if (referee.judge(*board, 2)) {
            winner = 2;
            break;
        }
    }
//    game_over();
}

void GameControl::game_over() {
    //cout<<"player"<<winner<<" win!";
    system("cls");
    const char *endInterface[8] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |      游戏结束!                              |\n",
            "        |      玩家 ",
            " 获胜                            |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    按空格键确认:[ ]"
    };
    for (int i = 0; i < 8; ++i) {
//        System::color(i + 2);
        cout << endInterface[i];
        if (i == 3)
            cout << board->piece[winner - 1];
    }
    System::gotoxy(34, 6);
    char c;
    while (c = _getch() != ' ');//同样等待输入
}