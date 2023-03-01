#pragma once
#include<iostream>
#include<fstream>
#include"BOOS.h"
#include"employee.h"
#include"manager.h"
#define FILEDATA "data.txt"
using namespace std;
class WorkerManage{
public:
	int w_Num;
	Worker** workerarr;
	bool fileisempty;
	void init_data();
	void show_woker();
	void Addworker();
	int isexist(int id);
	void del_worker();
	void mod_worker();
	void find_worker();
	void sort();
	void clean();
	int getnum();
	void save();
	WorkerManage();
	~WorkerManage();
	void exitststem();
	void Worker_showmenu();
};