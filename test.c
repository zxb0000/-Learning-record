#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"

int main() {
	int input=0;
	struct Contact con;
	initContact(&con);
	do {
		meun();
		printf("请输入你的选择：");
		scanf("%d", &input);
		system("CLS");
			switch (input) {
			case ADD:
				addContact(&con);
				break;
			case DELE:
				DelContact(&con);
				break;
			case ALTER:
				AlterContact(&con);
				break;
			case SELECT:
				SelectContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				printf("已经退出通讯录！\n");
				break;
			default:
				printf("输入错误！请重新输入!\n");
				break;
			}
	} while (input);

}