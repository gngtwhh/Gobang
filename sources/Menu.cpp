#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../headers/Menu.h"
//#include "../headers/System.h"

using namespace std;

void Menu::print() {
    system("cls");
        System::gotoxy(28, 0);
    cout << "������" << endl;
    const char *select[8] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        ��������:                          |\n",
            "        |       1.��ʼ��Ϸ     2.�˳���Ϸ             |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    ��������[1/2]:[ ]"
    };
    for (auto &i: select) {//��ӡ�˵�
        cout << i;
    }
}

int Menu::choose() {
    char c;
    while (true) {
        System::gotoxy(37, 8);//��λ��������
        c = _getch();//vs2022Ҫ��getch()����Ϊ_getch()---��׼c����������getch()(?)
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
    printf("�������!");
    Sleep(1000);
    System::gotoxy(39, 8);
    cout << "         ";
}