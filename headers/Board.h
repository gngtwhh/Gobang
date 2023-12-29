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

    bool move_in_board(int who);//����ֵ�����ж��Ƿ���ȷ����---���ѡ�����ӵĵط�������������
    std::pair<int,int> last_position();//�������һ�����ӵ�����

    std::string piece[2]={"��","��"};//���Ȱ׺�
    int maxcoord_x = 14 * 4;
    int maxcoord_y = 14 * 2;
private:
    void print_cursor();
    void clear_cursor();
    std::map<char, int> coords;//��ǰ������
    int record[15][15] = {-1};//ע��,����ά�Ȳ�����ϵͳ����̨���,��Ҫ����
    const char *corners[4] = {"��", "��", "��", "��"};//����,����,����,����
};
#endif //gomoku_BOARD_H
