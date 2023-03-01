#include "manager.h"

Manager::Manager(int id, string name, int deid)
{
	w_ID = id;
	w_name = name;
	w_deID = deid;
}

void Manager::showInfo()
{
	cout << "ID：" << w_ID << "\t"
		<< "姓名：" << w_name << "\t"
		<< "部门ID：" << w_deID << "\t"
		<< "部门名： " << get_deName() << "\t"
		<< "岗位职责：" << get_duty() << endl;
}

string Manager::get_deName()
{
	return string("管理层");
}

string Manager::get_duty()
{
	return string("上传下达！");
}
