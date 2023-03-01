#pragma once
#include"worker.h"
class Manager :public Worker{
public:
	Manager(int id, string name, int deid);
	virtual void showInfo();
	virtual string get_deName();
	virtual string get_duty();


};
