#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<string>
enum {
	策划 = 1, 美术 = 2, 研发 = 3
};
using namespace std;
class worker {
public:
	string name;
	int salary;
};
void createworker(vector<worker> &v) {
	for (int i = 0; i < 10; i++) {
		string nameseek = "ABCDEFGHIJ";
		string name = "员工：" ;
		name += nameseek[i];
		int salary = rand() % 10000 + 10000;
		worker w;
		w.name = name;
		w.salary = salary;
		v.push_back(w);
	}

}
void selectdepartment(vector<worker>&v,multimap<int, worker>&m) {
	for (int i = 0; i < v.size(); i++) {
		int depid = rand() % 3 + 1;
		m.insert(make_pair(depid, v[i]));
	}
}
void showdepatment(multimap<int,worker>m) {
	multimap<int,worker>::iterator pos=m.find(策划);
	int count = m.count(策划);
	int index = 0;
	cout << "策划部的人员："<<endl;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
	cout << "美术部的人员：" << endl;
	count = m.count(美术);
	index = 0;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
	cout << "研发部的人员：" << endl;
	count = m.count(研发);
	index = 0;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	//创建十个员工
	vector<worker>v;
	createworker(v);
	//分配员工部门
	multimap<int, worker>m;
	selectdepartment(v,m);
	//展示部门信息
	showdepatment(m);
	/*for (int i = 0; i < v.size(); i++) {
		cout << "name:" << v[i].name << " salary:" << v[i].salary <<endl;
	}*/
}