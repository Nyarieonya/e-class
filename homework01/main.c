#include"Game.h"
#include"Screen.h"
int gameplay = 0;
int main() {
	Title_Screen();
	while (gameplay == 0) {
		Screen_Export();
		char input = _getch();
		Game_playing(input);
		if (gamescreen_savepoint(1) == 999) {
			gameplay = 1;
		}
	}
	return 0;
}