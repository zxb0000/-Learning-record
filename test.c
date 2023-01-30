#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
		char mine[ROWS][COLS];//游戏数组
		char show[ROWS][COLS];//显示数组
		Initbord(mine, ROWS, COLS,'0');//初始化数组的填充内容
		Initbord(show, ROWS, COLS,'*');//初始化数组的填充内容
		Initmine(mine, ROW, COL);//初始化地雷的位置
		//Displaybord(mine, ROW, COL);//地雷的位置
		Displaybord(show, ROW, COL);//显示棋盘
		Findmine(mine, show, ROW, COL);
}
void test() {
	int input;
	do{
		meun();
		printf("请选择：");
		scanf("%d", &input);
		switch (input) {
		case 1: 
			system("CLS");
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入有误！请重新输入！\n");
			break;
		}
	
	} while (input);
}

int main() {
	srand((unsigned int)time(NULL));
	test();
	return 0;
}