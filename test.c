#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
	char bord[ROW][COL] = { 0 };
	Initbord(bord,ROW,COL);
	system("CLS");
	Display(bord,ROW,COL);
	char rec;
	while(1){
		Computermove(bord, ROW, COL);
		rec=Iswin(bord, ROW, COL);
		if (rec != 'C') {
			break;
		}
		Playermove(bord, ROW, COL);
		rec = Iswin(bord, ROW, COL);
		if (rec != 'C') {
			break;
		}
		
	}
	if (rec == 'O') {
		printf("恭喜您赢了！\n");
	}
	if (rec == 'X') {
		printf("您输了！\n");
	}
	if (rec == 'Q') {
		printf("平局！！\n");
	}
	

}
int main() {
	int input;
	srand((unsigned int) time(NULL));
	do
	{
		meun();
		printf("请输入选项：");
		scanf("%d", &input);
		switch(input) 
		{
		case 1: {
				game();
				break;
			}
			case 0:
				printf("已经退出游戏！\n");
				break;
			default:
				printf("输入错误！！请重新输入！\n");
				break;
		}
	}while(input);
	return 0;
}