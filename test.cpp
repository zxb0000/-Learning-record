#define _CRT_SECURE_NO_WARNINGS
#include"worker.h"
#include"workermanage.h"
#include"employee.h"
#include"BOOS.h"
#include"manager.h"
void test() {
	Worker* w1= new employee(1, "张三", 1);
	w1->showInfo();
	Worker* w2 = new Manager(2, "李四", 2);
	w2->showInfo();
	Worker* w3 = new Boss(3,"王五", 3);
	w3->showInfo();
	delete w1, w2, w3;
}
int main() {
	//test();
	WorkerManage wm;
	int chioch;
	while (1) {
		wm.Worker_showmenu();
		cout << "请输入你的选择:" << endl;
		cin >> chioch;
		switch (chioch) {
		case 0:
			wm.exitststem();
			break;
		case 1:
			wm.Addworker();
			break;
		case 2:
			wm.show_woker();
			break;
		case 3:
			wm.del_worker();
			break;
		case 4:
			wm.mod_worker();
			break;
		case 5:
			wm.find_worker();
			break;
		case 6:
			wm.sort();
			break;
		case 7:
			wm.clean();
			break;
		default:
			system("cls");
			cout << "输入错误!" << endl;
			break;
		}
	}
}