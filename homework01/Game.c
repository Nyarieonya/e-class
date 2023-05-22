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
	if (gamestate == Title) {			// 게임 타이틀 상태에서 받는 명령들
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
	else if (gamestate == Play) {		// 게임 플레이 상태에서 받는 명령들
		if (input == 'q' || input == 'Q') {
			Title_Screen();
			gamestate = 0;
		}
	}
	else if (gamestate == About) {		// 타이틀에서 About 들어갔을때 받는 명령임
		if (input == 'q'|| input == 'Q') {
			Title_Screen();
			gamestate = 0;
		}
	}
	else if (gamestate == Exit) {		// 나가기 커맨드를 입력받았을때 한번 더 물어보는 함수
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
