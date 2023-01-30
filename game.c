 #define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initbord(char arr[ROWS][COLS], int rows, int cols,char set) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			arr[i][j] = set;
		}
	}
}
void Displaybord(char arr[ROWS][COLS], int row, int  col) {
	int i, j;
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void Initmine(char arr[ROWS][COLS], int row, int col) {
	int x, y,count;
	count = degree;
	while(count) {
		x = rand() % row + 1;//随机产生行坐标
		y = rand() % col + 1;//随机产生列坐标
		if (arr[x][y] == '0') {
			arr[x][y] = '1';
			count--;
		}
	}
}
int mine_count(char mine[ROWS][COLS], int x,int y) {

	return (mine[x+1][y+1] + mine[x + 1][y] + mine[x + 1][y - 1] +mine[x][y+1]+ mine[x][y - 1] +mine[x - 1][y + 1] + mine[x - 1][y] + mine[x - 1][y - 1])-8*'0';
}
void jisuan(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y){
	
	if (x>0&&y>0&&x<ROWS-1&&y<COLS-1&&show[x][y]=='*') {//判断坐标是否棋盘内，并且是否已经被翻开过
		int count=0;
		count = mine_count(mine, x, y);
		if (count == 0) {
			show[x][y] = ' ';
			jisuan(mine, show, x + 1, y + 1);
			jisuan(mine, show, x + 1, y);
			jisuan(mine, show, x + 1, y - 1);
			jisuan(mine, show, x, y + 1);
			jisuan(mine, show, x, y - 1);
			jisuan(mine, show, x - 1, y + 1);
			jisuan(mine, show, x - 1, y);
			jisuan(mine, show, x - 1, y - 1);
		}
		else {
			show[x][y] = count + '0';
		}
	}
	
}
int  Unknown_block_num(char show[ROWS][COLS],int row,int col) {//计算未知格的数量，当未知格的数量等于炸弹的数量时，游戏胜利
	int i, j, num;
	num = 0;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			if (show[i][j] == '*') num++;
		}
	}
	return num;
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x, y, Unblock=row*col;
	while (Unblock !=degree) {
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				system("CLS");
				Displaybord(mine, row, col);
				printf("很遗憾！你踩到雷了！游戏结束！\n");
					break;
			}
			jisuan(mine, show, x, y);//计算坐标周围地雷数量并显示
			system("CLS");
			Displaybord(show, row, col);
			Unblock = Unknown_block_num(show, row, col);
		}
		else {
			printf("输入的坐标有误！请重新输入！\n");
		}
	}
	if (Unblock == degree) {
		system("CLS");
		printf("恭喜你找出了全部的地雷！游戏胜利！\n");
		Displaybord(mine, row, col);
	}
	
}
void meun() {
	printf("---------------------------\n");
	printf("--------1.开始游戏---------\n");
	printf("--------0.退出游戏---------\n");
	printf("---------------------------\n");
}

