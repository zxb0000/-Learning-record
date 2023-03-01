#pragma once
#include"worker.h"
class employee:public Worker {
public:
	employee(int id, string name, int deid);
	virtual void showInfo();
	virtual string get_deName();
	virtual string get_duty() ;

};