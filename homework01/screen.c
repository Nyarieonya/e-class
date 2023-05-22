#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Screen.h"
#define Screen_Width 100
#define Screen_Height 20

char Screen_arr[Screen_Height * 100];
const char* Title = "���б����� ��Ƴ���";
const char* Command_Text[] = { "1. G a m e  S t a r t", "2. G a m e  A b o u t", "3. G a m e  E x i t" };
const char* Exit_Text[] = {"Y. Y E S     N. N O       ","������ �����Ͻðڽ��ϱ�?"};
const char* About_Text[] = { "������ : ����ö-202327049", "Ver 0.1", "Q�� ���� ������" };
const char* Story_Number = "���ǻ��� �� ������ �÷��� ���";
const char* Story_Text1[] = {"�� ������ �ſ� ������ �ְ����̸� ������ �ٸ� �� �ֽ��ϴ�. ","���丮�� �Ϻδ� �������� ��ȭ�� �������� ����������ϴ�.", "�� ������ EnterŰ�� ���� �ѱ� ���� �ְ� �ٸ� �Է��� �䱸 �� �� �ֽ��ϴ�."};

void Screen_Text_add(const char* source, int line, int col) { //��ũ�� ������ source �ؽ�Ʈ�� �߰��ϴ� �Լ��Դϴ�.
    int len = strlen(source), st;

    if (col == 0)
        st = Screen_Width / 2 - len / 2;
    else
        st = col;
    st += line * 100;

    memcpy(Screen_arr + st, source, strlen(source));
}

void Screen_Clear() {   //   ��ũ���� �ʱ�ȭ�ϴ� �Լ��Դϴ�.
    memset(Screen_arr, '#', sizeof(Screen_arr));
    memset(Screen_arr + Screen_Width, ' ', sizeof(Screen_arr) - Screen_Width * 2);

    for (int i = 0; i < Screen_Height * Screen_Width; i += Screen_Width) {
        Screen_arr[i] = '\n';
        Screen_arr[i + 1] = Screen_arr[i + Screen_Width - 1] = '#';
    }
}

void Title_Screen() {//   Ÿ��Ʋ ȭ���� ����ϴ� �Լ��Դϴ�.
    Screen_Clear();
    Screen_Text_add(Title, 3, 0);
    Screen_Text_add(Command_Text[0], 12, 37);
    Screen_Text_add(Command_Text[1], 14, 37);
    Screen_Text_add(Command_Text[2], 16, 37);
}

void Game_Start_Screen() { //   Ÿ��Ʋ���� ó�� �����ϴ� â�� ���� �Լ��Դϴ�
    Screen_Clear();
    Screen_Text_add(Story_Number, 2, 3);
    Screen_Text_add(Story_Text1[0], 14, 0);
    Screen_Text_add(Story_Text1[1], 15, 0);
    Screen_Text_add(Story_Text1[2], 16, 0);
    Screen_Text_add(About_Text[2], 18, 80);
}

void About_Screen() {   //      ������ ����...���� ����...���..
    Screen_Clear();
    Screen_Text_add(Title, 3, 0);
    Screen_Text_add(About_Text[0], 13, 0);
    Screen_Text_add(About_Text[1], 4, 0);
    Screen_Text_add(About_Text[2], 16, 0);
}

void Exit_Screen() {      //      Exit Ŀ�ǵ带 �Է¹޾��� �� ��ũ���� ������ִ� �Լ��Դϴ�
    Screen_Clear();
    Screen_Text_add(Exit_Text[1], 3, 0);
    Screen_Text_add(Exit_Text[0], 16, 39);
}

void Screen_Export() {
    system("cls");
    printf("%s\n", Screen_arr);
}