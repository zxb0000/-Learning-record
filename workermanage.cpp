#include "workermanage.h"
void WorkerManage::init_data()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	int id;
	string name;
	int deid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deid) {
		Worker* worker = NULL;
		switch (deid)
		{
		case 1:worker = new employee(id, name, deid); break;
		case 2:worker = new Manager(id, name, deid); break;
		case 3:worker = new Boss(id, name, deid); break;
		default:
			break;
		}
		workerarr[index++] = worker;
	}
	ifs.close();
}
void WorkerManage::show_woker()
{
	if (fileisempty) {
		cout << "没有数据！" << endl;
	}
	else {
		for (int i=0; i < w_Num; i++) {
			workerarr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManage::Addworker()
{
	cout << "请输入要添加的员工人数:" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0) {
		int newnum = this->w_Num + addnum;
		Worker** newspace = new Worker * [newnum];
		if (this->workerarr != NULL) {//如果原来存在数据，将原来的数据转移到新的空间上
			for (int i = 0; i < this->w_Num; i++) {
				newspace[i] = workerarr[i];
				}
		}
		for (int i = 0; i < addnum; i++) {//添加新数据
			int id;
			int selectdeid;
			string name;
			cout << "请输入第" << i +1<< "个人的ID" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个人的姓名" << endl;
			cin >>name;

			cout << "请选择第" << i + 1 << "个人的部门" << endl;
			cout << "1.一线员工" << endl;
			cout << "2.管理部门" << endl;
			cout << "3.董事部" << endl;
			cin >> selectdeid;
			Worker* worker=NULL;
			switch (selectdeid)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout<<"输入有误！";
				break;
			}
			//将新创建的员工数据添加到数组中
			newspace[this->w_Num + i] = worker;
		}
		//释放原来的空间
		delete []this->workerarr;
		workerarr = newspace;
		this->w_Num = newnum;
		save();
		fileisempty = false;
		cout << "成功添加了" << addnum << "个新员工" << endl;
		
	}
	else {
		cout << "输入有误！";
		return;
	}
	system("pause");
	system("cls");
}

int WorkerManage::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < w_Num; i++) {
		if (workerarr[i]->w_ID == id) {
			index = i;
		}
	 }
	return index;
}

void WorkerManage::del_worker()
{
	
	if (fileisempty) {
		cout << "数据空,无法操作！" << endl;
	}
	else {
		int id;
		cout << "请输入要删除员工的ID:" << endl;
		cin >> id;
		int index = isexist(id);
		if (index == -1) {
			cout << "失败！查询无此id" << endl;
			
		}
		else {
			for (int i = index; i < w_Num-1; i++) {
				workerarr[i] = workerarr[i + 1];
			}
			w_Num--;
			save();
			cout << "删除成功！" << endl;
			
		}
	}
	system("pause");
	system("cls");
}

void WorkerManage::mod_worker()
{
	if (fileisempty) {
		cout << "数据为空，无法修改！" << endl;
	}
	else {
		int id;
		cout << "请输入要修改人的ID:" << endl;
		cin >> id;
		int index = isexist(id);
		if (index == -1) {
			cout << "查无此人！无法修改！" << endl;
		}
		else{
			delete workerarr[index];
			Worker* worker=NULL;
			int newid;
			string newname;
			int newdeid;
			cout << "请输入新的id" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			
			cout << "请选择新的部门:" << endl;
			cout << "1.一线员工" << endl;
			cout << "2.管理部门" << endl;
			cout << "3.董事部" << endl;
			cin >> newdeid;
			switch (newdeid)
			{
			case 1:
				worker = new employee(newid, newname, newdeid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdeid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdeid);
				break;
			default://有问题！
				cout << "输入错误！" << endl;
				break;
			}
			workerarr[index] = worker;
			save();
			cout << "修改完成！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManage::find_worker()
{
	if (fileisempty) {
		cout << "数据为空！" << endl;
	}
	else {
		int select = -1;
		cout << "请输入查找的方式：" << endl;
		cout << "1.按照ID查找" << endl;
		cout << "2.按照姓名查找" << endl;
		cin >> select;
		if (select == 1) {
			cout << "请输入ID：" << endl;
			int id;
			cin >> id;
			int index = isexist(id);
			if (index == -1) {
				cout << "查询无此ID！" << endl;
				return;
			}
			else {
				workerarr[index]->showInfo();
			}
		}
		else if (select == 2) {
			cout << "请输入姓名：" << endl;
			string name;
			cin >> name;
			int flag = 0;
			for (int i = 0; i < w_Num; i++) {
				if (workerarr[i]->w_name == name) {
					workerarr[i]->showInfo();
					flag = 1;
				}
			}
			if (flag == 0) {
				cout << "没有找到此人的相关信息!" << endl;
			}
		}
		else {
			cout << "输入错误！" << endl;
		}
	}
	system("pause");
	system("cls");
}
int cmp_id_up(const void* e1, const void* e2) {
	return (*((Worker**)e1))->w_ID - (*((Worker**)e2))->w_ID;
}
int cmp_id_down(const void* e1, const void* e2) {
	return  (*((Worker**)e2))->w_ID - (*((Worker**)e1))->w_ID;
}
void WorkerManage::sort()
{
	if (fileisempty) {
		cout << "数据为空！无法排序" << endl;
		system("pause");
		system("cls");
	}
	else {
		int select=0;
		cout << "请输入要排序的方法" << endl;
		cout << "1.按照ID升序" << endl;
		cout << "2.按照ID降序" << endl;
		//cout << "1.按照姓名升序" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			qsort(workerarr, w_Num, sizeof(Worker*), cmp_id_up);
			break;
		case 2:
			qsort(workerarr, w_Num, sizeof(Worker*), cmp_id_down);
			break;
		default:
			break;
		}
		cout << "排序完成！" << endl;
		show_woker();
		save();
		
	}

}

void WorkerManage::clean()
{
	cout << "确认要清空所有的数据吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs(FILEDATA, ios::trunc);
		ofs.close();
		if(workerarr!=NULL){
			for (int i = 0; i < w_Num; i++) {
				delete workerarr[i];
				workerarr[i] = NULL;
			}
			delete[]workerarr;
			workerarr = NULL;
			w_Num = 0;
			fileisempty = true;
		}
		cout << "清除成功！" << endl;
		system("pause");
		system("cls");
	}
	else {
		system("cls");
		return;
	}
}

int WorkerManage::getnum()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	int id;
	string name;
	int deid;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> deid) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManage::save()
{
	ofstream ofs(FILEDATA, ios::out | ios::binary);
	if (!ofs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	for (int i = 0; i < this->w_Num; i++) {
		ofs << this->workerarr[i]->w_ID << " " << workerarr[i]->w_name << " " << workerarr[i]->w_deID << endl;
	}
	ofs.close();
}

WorkerManage::WorkerManage()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	if(!ifs.is_open()){
		//cout << "数据文件不存在" << endl;
		w_Num = 0;
		workerarr = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		w_Num = 0;
		workerarr = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	int num = getnum();
	//cout << "职工人数为" << num << "个" << endl;
	w_Num = num;
	workerarr = new Worker * [w_Num];
	init_data();
	fileisempty = false;
	/*for (int i = 0; i < w_Num; i++) {
		cout << "ID：        " << workerarr[i]->w_ID << "\t"
			<< "姓名：      " << workerarr[i]->w_name << "\t"
			<< "部门ID：    " << workerarr[i]->w_deID << "\t"
			<< "部门名：    " << workerarr[i]->get_deName() << "\t"
			<< "岗位职责：  " << workerarr[i]->get_duty() << endl;
	}*/
	
	
}

WorkerManage::~WorkerManage()
{
	if (workerarr != NULL) {
		delete[]workerarr;
		workerarr = NULL;
	}
}

void WorkerManage::exitststem()
{
	cout << "系统已经退出！" << endl;
	exit(0);
	system("pause");
}

void WorkerManage::Worker_showmenu()
{
	cout << "----------------------------------------" << endl;
	cout << "-------  欢迎使用职工管理系统! ---------" << endl;
	cout << "---------   1.增加职工信息     ---------" << endl;
	cout << "---------   2.显示职工信息     ---------" << endl;
	cout << "---------   3.删除职工信息     ---------" << endl;
	cout << "---------   4.修改职工信息     ---------" << endl;
	cout << "---------   5.查找职工信息     ---------" << endl;
	cout << "---------   6.排序职工信息     ---------" << endl;
	cout << "---------   7.清空所有职工信息 ---------" << endl;
	cout << "---------   0.退出程序        ----------" << endl;
	cout << "----------------------------------------" << endl;
}
