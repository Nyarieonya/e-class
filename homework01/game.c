#include"Game.h"
char Screen_arr[2000]; 
char Title[50] = "����巡���� �ֱ� �Ѱɱ�        ";
char Command_Text[100] = "1. G a m e  S t a r t     2. G a m e  A b o u t     3. G a m e  E x i t              ";
char Exit_Text[50] = "3. �� �� ��     4. N O       ";
char About_Text[200] = "������ : ����ö-202327049   Ver 0.1                    �ƹ� Ű�� �Է��� ������                  ";
char Story_Number[50] = "������ ������                                   ";
char Story_Text1[1000] = "�� ������ �⺻������ 1�� 2�� �̷�����ְ� ���丮�� �б�� 1�� �Է��ϴ°��� �⺻���� �մϴ�. ������ ���� ���ߴܰ��̹Ƿ� 9���� ������ ���� �����Ű�� Ŀ�ǵ��Դϴ�.                            1���� �Է��� Ÿ��Ʋ ȭ������ ���ư��ϴ�                          ";
void Screen_Clear() { //		��ũ���� ����ִ� �Լ��Դϴ�
	for (int i = 2; i < 1800; i += 100) {
		for (int l = i + 100; l < i + 197; l++)Screen_arr[l] = ' ';
	}
}
int Screen_Setup(int i) { //	��ũ�� ��� �迭�� #���� ä��� �Լ��Դϴ�.
	if (i == 2000) {
		return 1;
	}
	else{
		Screen_arr[i] = '#';
		return Screen_Setup(i + 1);
	}
}
int Screen_Start() {	//	100ĭ���� �ٹٲ� ����� �ִ� �Լ��Դϴ�.
	Screen_Setup(1);
	for (int i = 0; i < 2000; i += 100) {
		Screen_arr[i] = '\n';
	}
	return 0;
}
int Title_Screen() {		//	Ÿ��Ʋ ȭ���� ����ϴ� �Լ��Դϴ�.
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
int Game_Start_Screen() { //	Ÿ��Ʋ���� ���ӽ����� �������� ��½�Ű�� �Լ��Դϴ�
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
int About_Screen() {	//		������ ����...���� ����...���..
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
int Exit_Screen() {		//		Exit Ŀ�ǵ带 �Է¹޾��� �� ��ũ���� ������ִ� �Լ��Դϴ�
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