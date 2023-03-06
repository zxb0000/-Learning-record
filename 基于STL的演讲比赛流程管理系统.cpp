#define _CRT_SECURE_NO_WARNINGS
#include"manage.h"
#include<algorithm>
int main() {
	srand((unsigned int)time(NULL));
	manage man;
	/*for_each(man.m.begin(), man.m.end(), [](map<int, speaker>::reference it) {cout << "编号:" << it.first << " "
		<< "选手姓名：" << it.second.name << "分数：" << it.second.sorce[0] << " " << it.second.sorce[1] << endl; });*/
	int choice;
	while (1) {
		man.showmenu();
		cout << "请输入你的选择：";
		cin>>choice;
		switch (choice)
		{
		case 1:
			man.starspeech();
			break;
		case 2:
			man.showrecord();
			break;
		case 3:
			man.clearrecord();
			break;
		case 0:
			man.system_exit();
			break;
		default:
			system("cls");
			break;
		}
		
	}
	
	system("pause");
	return 0;
}