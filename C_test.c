#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"

int main() {
	int input=0;
	struct Contact con;
	initContact(&con);
	do {
		meun();
		printf("���������ѡ��");
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
			case SAVE:
				SaveContact(&con);
				break;
			case EXIT:
				SaveContact(&con);
				DestoryContact(&con);
				break;
			default:
				printf("�����������������!\n");
				break;
			}
	} while (input);

}