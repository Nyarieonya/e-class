#include"Game.h"
int main() {
	Screen_Start();
	int Title_Command_Code, Game_State = 0, Game_Start_State = 0, Ingame_Command;
	while (Game_State == 0) {
		Title_Screen();
		scanf_s("%d", &Title_Command_Code);
		if (Title_Command_Code == 1) {
			while (Game_Start_State == 0){
				Game_Start_Screen();
				scanf_s("%d", &Ingame_Command);
				if (Ingame_Command == 1) {
					Game_Start_State = 1;
				}
				else if (Ingame_Command == 9) {
					Game_Start_State = 1;
					Game_State = 1;
				}
			}
			Game_Start_State = 0;
		}
		else if (Title_Command_Code == 2) {
			About_Screen();
			int Exit;
			scanf_s("%d", &Exit);
			if (Exit == 3) {
			}
			else if (Exit == 4) {

			}
		}
		else if (Title_Command_Code == 3) {
			Exit_Screen();
			int Exit;
			scanf_s("%d", &Exit);
			if (Exit == 3) {
				Game_State = 1;
			}
		}
		else if (Title_Command_Code == 9 || Ingame_Command == 9) {
			Game_Start_State = 1;
			Game_State = 1;
		}
		else {
			printf("Not Found Command!!!!");
		}
	}
	return 0;
}