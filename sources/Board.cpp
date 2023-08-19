#include <iostream>
#include "../headers/Board.h"

using namespace std;

Board::Board() : coords({{'x', 7 * 4},
                         {'y', 7 * 2}}) {
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            record[i][j] = 0;
}

void Board::print_board() {
    static const char *board_strs[] = {
            "┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┓",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┠ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┼ ― ┨",
            "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃",
            "┗━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┛"
    };
/*static const char *corners[4] = {"┏", "┓", "┗", "┛"};//左上,右上,左下,右下
static const char *crosses[5] = {"┠", "┯", "┨", "┷", "┼"};//左,上,右,下,中
static const char *mid_edges[2] = {" ― ", "│"};//横,竖
static const char *edges[2] = {" ━━", "┃"};//横,竖
static const char *space = "   ";

//上边界
cout << corners[0];
for (int i = 0; i < 14; ++i) {
    cout<<edges[0] << (i != 13 ? crosses[1] : corners[1]);
}
cout << endl;

cout << edges[1];
for (int i = 0; i < 14; ++i) {
    cout << space << (i != 13 ? mid_edges[1] : edges[1]);
}
cout << endl;

//中间
for (int i = 0; i < 13; ++i) {
    cout << crosses[0];
    for (int j = 0; j < 14; ++j)
        cout << mid_edges[0] << (j != 13 ? crosses[4] : crosses[2]);
    cout << endl;

    cout << edges[1];
    for (int j = 0; j < 14; ++j)
        cout << space << (j != 13 ? mid_edges[1] : edges[1]);
    cout << endl;
}

//下边界
cout << corners[2];
for (int i = 0; i < 14; ++i) {
    cout<<edges[0] << (i != 13 ? crosses[3] : corners[3]);
}
cout << endl;*/

//    直接打印棋盘
    for (auto str: board_strs)
        cout << str << endl;
//    打印默认坐标(7,7)
    print_cursor();
}

void Board::clear_board() {

}

void Board::move_coord(int direction) {
    static int cursor_move[4][2] = {
            {0,  -2},
            {-4, 0},
            {0,  2},
            {4,  0}
    };//上左下右
    //检查移动的可行性
    if ((direction == 1 && coords['y'] == 0) || (direction == 2 && coords['x'] == 0) ||
        (direction == 3 && coords['y'] == maxcoord_y) || (direction == 4 && coords['x'] == maxcoord_x)) {
        return;
    }
    //清除画板上的原光标字符
    clear_cursor();

    //移动中心坐标
    coords['x'] += cursor_move[direction - 1][0];
    coords['y'] += cursor_move[direction - 1][1];

    //绘制新的光标字符
    print_cursor();
}

void Board::move_coord(int x, int y) {

}

bool Board::move_in_board(int who) {
    //注意:record的x和y与coords的x和y相反
    if (!record[coords['y'] / 2][coords['x'] / 4]) {
        record[coords['y'] / 2][coords['x'] / 4] = who;
        System::gotoxy(coords['x'], coords['y']);
        cout << piece[who - 1];//玩家编号为1和2
        return true;
    } else return false;
}

void Board::print_cursor() {
    //x+-2,y+-1
    //上左下右
    if (!(coords['x'] - 2 < 0 || coords['y'] - 1 < 0)) {
        System::gotoxy(coords['x'] - 2, coords['y'] - 1);
        cout << corners[0];
    }
    if (!(coords['x'] + 2 > maxcoord_x || coords['y'] - 1 < 0)) {
        System::gotoxy(coords['x'] + 2, coords['y'] - 1);
        cout << corners[1];
    }
    if (!(coords['x'] - 2 < 0 || coords['y'] + 1 > maxcoord_y)) {
        System::gotoxy(coords['x'] - 2, coords['y'] + 1);
        cout << corners[2];
    }
    if (!(coords['x'] + 2 > maxcoord_x || coords['y'] + 1 > maxcoord_y)) {

        System::gotoxy(coords['x'] + 2, coords['y'] + 1);
        cout << corners[3];
    }
}

void Board::clear_cursor() {
    //x+-2,y+-1
    //上左下右
    if (!(coords['x'] - 2 < 0 || coords['y'] - 1 < 0)) {
        System::gotoxy(coords['x'] - 2, coords['y'] - 1);
        cout << ' ';
    }
    if (!(coords['x'] + 2 > maxcoord_x || coords['y'] - 1 < 0)) {
        System::gotoxy(coords['x'] + 2, coords['y'] - 1);
        cout << ' ';
    }
    if (!(coords['x'] - 2 < 0 || coords['y'] + 1 > maxcoord_y)) {
        System::gotoxy(coords['x'] - 2, coords['y'] + 1);
        cout << ' ';
    }
    if (!(coords['x'] + 2 > maxcoord_x || coords['y'] + 1 > maxcoord_y)) {

        System::gotoxy(coords['x'] + 2, coords['y'] + 1);
        cout << ' ';
    }
}

std::pair<int, int> Board::last_position() {//当前的位置即为最后落子的地方,因为落子后立即判断
    //注意顺序对调
    return {coords['y'] / 2, coords['x'] / 4};
}