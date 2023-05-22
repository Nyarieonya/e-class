#define Title 0
#define Play 1
#define About 2
#define Exit 3
#include "Game.h"
#include "Screen.h"
int gamestate = 0;
int gamescreen_savepoint(int save) {
	return gamestate;
}
int Game_playing(char input) { 
	if (gamestate == Title) {			// ���� Ÿ��Ʋ ���¿��� �޴� ��ɵ�
		if (input == '1') {
			Game_Start_Screen();
			gamestate = 1;
		}
		else if (input == '2') {
			About_Screen();
			gamestate = 2;
		}
		else if (input == '3'){
			Exit_Screen();
			gamestate = 3;
		}
	}
	else if (gamestate == Play) {		// ���� �÷��� ���¿��� �޴� ��ɵ�
		if (input == 'q' || input == 'Q') {
			Title_Screen();
			gamestate = 0;
		}
	}
	else if (gamestate == About) {		// Ÿ��Ʋ���� About ������ �޴� �����
		if (input == 'q'|| input == 'Q') {
			Title_Screen();
			gamestate = 0;
		}
	}
	else if (gamestate == Exit) {		// ������ Ŀ�ǵ带 �Է¹޾����� �ѹ� �� ����� �Լ�
		if (input == 'y'|| input == 'Y') {
			gamestate = 999;
		}
		else if (input == 'n'|| input == 'N') {
			Title_Screen();
			gamestate = 0;
		}
	}
	return 0;
}
