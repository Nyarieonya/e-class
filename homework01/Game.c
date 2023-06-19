#define Title 0
#define Start 1
#define Play 2
#define About 3
#define Exit 4
#include "Game.h"
#include "Screen.h"
int gamestate = 0;
int gamescreen_savepoint(int save) {
	return gamestate;
}
int Game_playing(char input) { 
	if (gamestate == Title) {			// ���� Ÿ��Ʋ ���¿��� �޴� ��ɵ�
		if (input == '1') {
			Title_Start_Screen();
			gamestate = Start;
		}
		else if (input == '2') {
			About_Screen();
			gamestate = About;
		}
		else if (input == '3'){
			Exit_Screen();
			gamestate = Exit;
		}
	}
	else if (gamestate == Start) {		// ���� �÷��� ���¿��� �޴� ��ɵ�
		if (input == 'y' || input == 'Y') {
			Game_Start();
			gamestate = Play;
		}
	}
	else if (gamestate == Play) {
		if (input == 'q' || input == 'Q') {
			gamestate = 999;
		}
		else if (input == 'r' || input == 'R') {
			Game();
		}
	}
	else if (gamestate == About) {		// Ÿ��Ʋ���� About ������ �޴� �����
		if (input == 'q'|| input == 'Q') {
			Title_Screen();
			gamestate = Title;
		}
	}
	else if (gamestate == Exit) {		// ������ Ŀ�ǵ带 �Է¹޾����� �ѹ� �� ����� �Լ�
		if (input == 'y'|| input == 'Y') {
			gamestate = 999;
		}
		else if (input == 'n'|| input == 'N') {
			Title_Screen();
			gamestate = Title;
		}
	}
	return 0;
}
