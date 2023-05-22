#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Screen.h"
#define Screen_Width 100
#define Screen_Height 20

char Screen_arr[Screen_Height * 100];
const char* Title = "대학교에서 살아남기";
const char* Command_Text[] = { "1. G a m e  S t a r t", "2. G a m e  A b o u t", "3. G a m e  E x i t" };
const char* Exit_Text[] = {"Y. Y E S     N. N O       ","게임을 종료하시겠습니까?"};
const char* About_Text[] = { "만든사람 : 문수철-202327049", "Ver 0.1", "Q를 눌러 나가기" };
const char* Story_Number = "주의사항 및 게임의 플레이 방법";
const char* Story_Text1[] = {"이 게임은 매우 지극히 주관적이며 실제와 다를 수 있습니다. ","스토리중 일부는 개발자의 실화를 바탕으로 만들어졌습니다.", "이 게임은 Enter키를 눌러 넘길 수도 있고 다른 입력을 요구 할 수 있습니다."};

void Screen_Text_add(const char* source, int line, int col) { //스크린 변수에 source 텍스트를 추가하는 함수입니다.
    int len = strlen(source), st;

    if (col == 0)
        st = Screen_Width / 2 - len / 2;
    else
        st = col;
    st += line * 100;

    memcpy(Screen_arr + st, source, strlen(source));
}

void Screen_Clear() {   //   스크린을 초기화하는 함수입니다.
    memset(Screen_arr, '#', sizeof(Screen_arr));
    memset(Screen_arr + Screen_Width, ' ', sizeof(Screen_arr) - Screen_Width * 2);

    for (int i = 0; i < Screen_Height * Screen_Width; i += Screen_Width) {
        Screen_arr[i] = '\n';
        Screen_arr[i + 1] = Screen_arr[i + Screen_Width - 1] = '#';
    }
}

void Title_Screen() {//   타이틀 화면을 출력하는 함수입니다.
    Screen_Clear();
    Screen_Text_add(Title, 3, 0);
    Screen_Text_add(Command_Text[0], 12, 37);
    Screen_Text_add(Command_Text[1], 14, 37);
    Screen_Text_add(Command_Text[2], 16, 37);
}

void Game_Start_Screen() { //   타이틀에서 처음 시작하는 창을 띄우는 함수입니다
    Screen_Clear();
    Screen_Text_add(Story_Number, 2, 3);
    Screen_Text_add(Story_Text1[0], 14, 0);
    Screen_Text_add(Story_Text1[1], 15, 0);
    Screen_Text_add(Story_Text1[2], 16, 0);
    Screen_Text_add(About_Text[2], 18, 80);
}

void About_Screen() {   //      제작자 정보...버전 정보...등등..
    Screen_Clear();
    Screen_Text_add(Title, 3, 0);
    Screen_Text_add(About_Text[0], 13, 0);
    Screen_Text_add(About_Text[1], 4, 0);
    Screen_Text_add(About_Text[2], 16, 0);
}

void Exit_Screen() {      //      Exit 커맨드를 입력받았을 시 스크린에 출력해주는 함수입니다
    Screen_Clear();
    Screen_Text_add(Exit_Text[1], 3, 0);
    Screen_Text_add(Exit_Text[0], 16, 39);
}

void Screen_Export() {
    system("cls");
    printf("%s\n", Screen_arr);
}