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
            "���������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө�������",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "�� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D �� �D ��",
            "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��",
            "���������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩�������"
    };
/*static const char *corners[4] = {"��", "��", "��", "��"};//����,����,����,����
static const char *crosses[5] = {"��", "��", "��", "��", "��"};//��,��,��,��,��
static const char *mid_edges[2] = {" �D ", "��"};//��,��
static const char *edges[2] = {" ����", "��"};//��,��
static const char *space = "   ";

//�ϱ߽�
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

//�м�
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

//�±߽�
cout << corners[2];
for (int i = 0; i < 14; ++i) {
    cout<<edges[0] << (i != 13 ? crosses[3] : corners[3]);
}
cout << endl;*/

//    ֱ�Ӵ�ӡ����
    for (auto str: board_strs)
        cout << str << endl;
//    ��ӡĬ������(7,7)
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
    };//��������
    //����ƶ��Ŀ�����
    if ((direction == 1 && coords['y'] == 0) || (direction == 2 && coords['x'] == 0) ||
        (direction == 3 && coords['y'] == maxcoord_y) || (direction == 4 && coords['x'] == maxcoord_x)) {
        return;
    }
    //��������ϵ�ԭ����ַ�
    clear_cursor();

    //�ƶ���������
    coords['x'] += cursor_move[direction - 1][0];
    coords['y'] += cursor_move[direction - 1][1];

    //�����µĹ���ַ�
    print_cursor();
}

void Board::move_coord(int x, int y) {

}

bool Board::move_in_board(int who) {
    //ע��:record��x��y��coords��x��y�෴
    if (!record[coords['y'] / 2][coords['x'] / 4]) {
        record[coords['y'] / 2][coords['x'] / 4] = who;
        System::gotoxy(coords['x'], coords['y']);
        cout << piece[who - 1];//��ұ��Ϊ1��2
        return true;
    } else return false;
}

void Board::print_cursor() {
    //x+-2,y+-1
    //��������
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
    //��������
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

std::pair<int, int> Board::last_position() {//��ǰ��λ�ü�Ϊ������ӵĵط�,��Ϊ���Ӻ������ж�
    //ע��˳��Ե�
    return {coords['y'] / 2, coords['x'] / 4};
}