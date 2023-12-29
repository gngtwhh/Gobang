#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../headers/System.h"

using namespace std;

//涉及到windows的API
//更改文字颜色
void System::color(int i) {
    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void System::gotoxy(int x, int y) {
    COORD c;
    static HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);//从标准设备获取句柄
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

int System::keyboard() {//1234---上左下右
    char c;
    int n = 0;
    if (_kbhit()) {//检查是否有键盘输入
        c = _getch();//如果有,则进行一次读取
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