#include "BOOS.h"

Boss::Boss(int id, string name, int deid)
{
	w_ID = id;
	w_name = name;
	w_deID = deid;
}

void Boss::showInfo()
{
	cout << "ID：" << w_ID << "\t"
		<< "姓名：" << w_name << "\t"
		<< "部门ID：" << w_deID << "\t"
		<< "部门名： " << get_deName() << "\t"
		<< "岗位职责：" << get_duty() << endl;
}

string Boss::get_deName()
{
	return string("董事部");
}

string Boss::get_duty()
{
	return string("管理公司总体事务！");
}
