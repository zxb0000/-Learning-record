#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {
public:

	virtual void showInfo() = 0;
	virtual string get_deName() = 0;
	virtual string get_duty()=0;
	string w_name;
	int w_deID;
	int w_ID;
	string w_deName;
};
