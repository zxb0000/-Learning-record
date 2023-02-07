#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int ADD(int x, int y) {
	return x + y;
}
int SUB(int x, int y) {
	return x - y;
}
int MUL(int x, int y) {
	return x * y;
}
int DIV(int x, int y) {
	return x / y;
}
void menu() {
	printf(">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<\n");
	printf(">>>>>>>>>>> 1.ADD    2.SUB  <<<<<<<<<<<\n");
	printf(">>>>>>>>>>> 3.MUL    4.DIV  <<<<<<<<<<<\n");
	printf(">>>>>>>>>>>>>>>>0.EXIT<<<<<<<<<<<<<<<<<\n");
	printf(">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<\n");
}
int main() {
	int input,x,y;
	int (*parr[])(int, int) = { 0,ADD,SUB,MUL,DIV };
	do{
		
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		if (input >= 1 && input <= 4) {
			printf("请输入要计算的两个数：");
			scanf("%d%d", &x, &y);
			printf("结果为: %d\n", parr[input](x, y));
		}
		else if (input == 0) {
			printf("退出程序\n");
		}
		else printf("输入有误！\n");
		

	} while (input);
	
	
}