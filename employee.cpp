#include "employee.h"

employee::employee(int id, string name, int deid)
{
	this->w_ID = id;
	this->w_name = name;
	this->w_deID = deid;
}

void employee::showInfo()
{
	cout << "ID：" << w_ID << "\t"
		<< "姓名：" << w_name << "\t"
		<< "部门ID：" << w_deID << "\t"
		<< "部门名： " << get_deName() << "\t"
		<< "岗位职责：" << get_duty() << endl;
}

string employee::get_deName()
{
	return string("一线员工");
}

string employee::get_duty()
{
	return string("完成上级的任务！");
}
