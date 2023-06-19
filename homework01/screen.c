#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Screen.h"
#define Screen_Width 100
#define Screen_Height 30
#define Block_W 4
#define Block_H 4

char Screen_arr[Screen_Height * Screen_Width];
const char* Title = "2    0    4    8";
const char* Command_Text[] = { "1. G a m e  S t a r t", "2. G a m e  A b o u t", "3. G a m e  E x i t" };
const char* Exit_Text[] = { "Y. Y E S     N. N O       ","게임을 종료하시겠습니까?" };
const char* About_Text[] = { "만든사람 : 문수철-202327049", "Ver 0.3", "Y를 눌러 시작하기" };
const char* About_Text0 = "주의사항 및 게임의 플레이 방법";
const char* About_Text1[] = { "간단한 게임이며 규칙도 어렵지 않으며 게임을 쉽게 만들었습니다","딱히 이상한건 없으니 안심하시고 재밌게 플레이 해 주시길 바랍니다", "정말로 쉬운 게임입니다" };
const char* About_Text2[] = { "방향키를 눌러 해당 방향으로 블럭을 밀고", "블럭을 밀었을 때 붙는 블럭끼리","숫자가 같다면 합쳐지며", "연달아서 합쳐지는건 불가능 합니다.", "그리고 최고점수는 현재 만들어진","블럭 숫자로 갱신됩니다." };
const char* Block_print[] = { "##########  ##########  ##########  ##########", "#        #  #        #  #        #  #        #" };
int Block[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
char c_temp[10];

void Screen_Text_add(const char* source, int line, int col) { //스크린 변수에 source 텍스트를 추가하는 함수입니다.
    int len = strlen(source), st;

    if (col == 0)
        st = Screen_Width / 2 - len / 2;
    else
        st = col;
    st += line * Screen_Width;

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
    Screen_Text_add(Command_Text[0], 12, 0);
    Screen_Text_add(Command_Text[1], 14, 0);
    Screen_Text_add(Command_Text[2], 16, 0);
}

void Title_Start_Screen() { //   타이틀에서 처음 시작하는 창을 띄우는 함수입니다
    Screen_Clear();
    Screen_Text_add(About_Text0, 2, 3);
    Screen_Text_add(About_Text1[0], 14, 0);
    Screen_Text_add(About_Text1[1], 15, 0);
    Screen_Text_add(About_Text1[2], 16, 0);
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
    Screen_Text_add(Exit_Text[0], 16, 40);
}
void Game_Start() {
    Screen_Clear();
    int m = 3;
    for (int i = 0; i < 4; i++) {
        Screen_Text_add(Block_print[0], m, 4);
        for (int c = 0; c < 3; c++) {
            m++;
            Screen_Text_add(Block_print[1], m, 4);
        }
        m++;
        Screen_Text_add(Block_print[0], m, 4);
        m+=2;
    }
    Screen_Text_add(Title, 3, 65);
    Screen_Text_add(About_Text2[0], 10, 55);
    Screen_Text_add(About_Text2[1], 12, 55);
    Screen_Text_add(About_Text2[2], 13, 55);
    Screen_Text_add(About_Text2[3], 15, 55);
    Screen_Text_add(About_Text2[4], 17, 55);
    Screen_Text_add(About_Text2[5], 18, 55);
}
void Game() {
    int W = 7, H = 5;
    for (int i = 0; i < 4; i++) {
        W = 7;
        for (int l = 0; l < 4; l++) {
            sprintf_s(c_temp, sizeof(c_temp), "%d", Block[i][l]);
            Screen_Text_add(c_temp, H, W);
            W += 12;
        }
        H += 6;
    }
}

void Screen_Export() {
    system("cls");
    printf("%s\n", Screen_arr);
}