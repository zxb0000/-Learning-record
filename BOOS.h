#pragma once
#include"worker.h"
class Boss :public Worker {
public:
	Boss(int id, string name, int deid);
	virtual void showInfo();
	virtual string get_deName();
	virtual string get_duty();

};
