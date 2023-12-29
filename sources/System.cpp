#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../headers/System.h"

using namespace std;

//�漰��windows��API
//����������ɫ
void System::color(int i) {
    //SetConsoleTextAttribute��API���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void System::gotoxy(int x, int y) {
    COORD c;
    static HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);//�ӱ�׼�豸��ȡ���
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

int System::keyboard() {//1234---��������
    char c;
    int n = 0;
    if (_kbhit()) {//����Ƿ��м�������
        c = _getch();//�����,�����һ�ζ�ȡ
        if (c == 'w' || c == 'W')
            n = 1;
        else if (c == 'a' || c == 'A')
            n = 2;
        else if (c == 's' || c == 'S')
            n = 3;
        else if (c == 'd' || c == 'D')
            n = 4;
        else if(c==' ')
            n=5;
    }
    cout<<flush;
    return n;
}