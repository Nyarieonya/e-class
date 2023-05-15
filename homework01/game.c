#include"Game.h"
char Screen_arr[2000]; 
char Title[50] = "투명드래곤이 있긴 한걸까        ";
char Command_Text[100] = "1. G a m e  S t a r t     2. G a m e  A b o u t     3. G a m e  E x i t              ";
char Exit_Text[50] = "3. 나 가 기     4. N O       ";
char About_Text[200] = "만든사람 : 문수철-202327049   Ver 0.1                    아무 키를 입력해 나가기                  ";
char Story_Number[50] = "게임의 진행방법                                   ";
char Story_Text1[1000] = "이 게임은 기본적으로 1과 2로 이루어져있고 스토리의 읽기는 1을 입력하는것을 기본으로 합니다. 지금은 아직 개발단계이므로 9번은 게임을 강제 종료시키는 커맨드입니다.                            1번을 입력해 타이틀 화면으로 돌아갑니다                          ";
void Screen_Clear() { //		스크린을 비워주는 함수입니다
	for (int i = 2; i < 1800; i += 100) {
		for (int l = i + 100; l < i + 197; l++)Screen_arr[l] = ' ';
	}
}
int Screen_Setup(int i) { //	스크린 어레이 배열을 #으로 채우는 함수입니다.
	if (i == 2000) {
		return 1;
	}
	else{
		Screen_arr[i] = '#';
		return Screen_Setup(i + 1);
	}
}
int Screen_Start() {	//	100칸마다 줄바꿈 명령을 넣는 함수입니다.
	Screen_Setup(1);
	for (int i = 0; i < 2000; i += 100) {
		Screen_arr[i] = '\n';
	}
	return 0;
}
int Title_Screen() {		//	타이틀 화면을 출력하는 함수입니다.
	Screen_Clear();
	for (int i = 0; i < 25; i++) {
		Screen_arr[i+336]=Title[i];
		Screen_arr[i + 1239] = Command_Text[i];
		Screen_arr[i + 1439] = Command_Text[i + 26];
		Screen_arr[i + 1639] = Command_Text[i + 52];
	}
	printf("%s\n", Screen_arr);
	return 0;
}
int Game_Start_Screen() { //	타이틀에서 게임시작을 눌렀을시 출력시키는 함수입니다
	Screen_Clear();
	for (int i = 0; i < 40; i++) {
		Screen_arr[i + 203] = Story_Number[i];
		Screen_arr[i + 1704] = Story_Text1[i+189];
	}
	Story_Screen_1();
	printf("%s\n", Screen_arr);
	return 0;
}
int Story_Screen_1() {
	for (int i = 0; i < 91; i++) {
		Screen_arr[i + 1504] = Story_Text1[i];
		Screen_arr[i + 1604] = Story_Text1[i + 92];
	}
	return 0;
}
int About_Screen() {	//		제작자 정보...버전 정보...등등..
	Screen_Clear();
	for (int i = 0; i < 25; i++) {
		Screen_arr[i + 336] = Title[i];
		Screen_arr[i + 1339] = About_Text[i];
		Screen_arr[i + 446] = About_Text[i + 30];
		Screen_arr[i + 1639] = About_Text[i + 56];
	}
	printf("%s\n", Screen_arr);
	return 0;
}
int Exit_Screen() {		//		Exit 커맨드를 입력받았을 시 스크린에 출력해주는 함수입니다
	Screen_Clear();
	for (int i = 0; i < 25; i++) {
		Screen_arr[i + 336] = Title[i];
		Screen_arr[i + 1239] = Command_Text[i];
		Screen_arr[i + 1439] = Command_Text[i + 26];
		Screen_arr[i + 1639] = Exit_Text[i];
	}
	printf("%s\n", Screen_arr);
	return 0;
}