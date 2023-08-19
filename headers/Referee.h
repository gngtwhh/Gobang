#ifndef gomoku_REFEREE_H
#define gomoku_REFEREE_H
class Board;
class Referee {
public:
    Referee() = default;
    bool judge(Board &board,int who);
};

#endif //gomoku_REFEREE_H
