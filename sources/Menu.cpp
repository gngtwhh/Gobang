#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../headers/Menu.h"
//#include "../headers/System.h"

using namespace std;

void Menu::print() {
    system("cls");
        System::gotoxy(28, 0);
    cout << "五子棋" << endl;
    const char *select[8] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        请输入编号:                          |\n",
            "        |       1.开始游戏     2.退出游戏             |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    请输入编号[1/2]:[ ]"
    };
    for (auto &i: select) {//打印菜单
        cout << i;
    }
}

int Menu::choose() {
    char c;
    while (true) {
        System::gotoxy(37, 8);//定位到输入栏
        c = _getch();//vs2022要求将getch()更换为_getch()---标准c编译器换回getch()(?)
        if (c == '1') {
            system("cls");
            return 1;
        } else if (c == '2') {
            return 2;
        } else wrongInput();
    }
}

void Menu::wrongInput() {
    System::gotoxy(39, 8);
    printf("输入错误!");
    Sleep(1000);
    System::gotoxy(39, 8);
    cout << "         ";
}