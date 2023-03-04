#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;
void printmap(map<int,int>&m) {
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}
}
void test() {
	pair<int, int>p1(1,25);
	pair<int, int>p2(2,35);
	pair<int, int>p3(3,125);
	pair<int, int>p4(4,45);
	pair<int, int>p5(5,25);
	map<int,int>m;
	m.insert(pair<int, int>(10, 52));//匿名对组插入;
	m.insert(p1);//默认按key值升序排序
	m.insert(p4);
	m.insert(p5);
	m.insert(p2);
	m.insert(p3);
	printmap(m);
}
void test2(){
	//插入
	map<int, int>m;
	m.insert(make_pair(1, 20))  ;
	m.insert(pair<int,int>(2,30));
	m.insert(map<int, int>::value_type(3, 40));
	m[4] = 50;
	printmap(m);

}
class person {
public:
	person(string n, int a) :name(n), age(a) {}
	string name;
	int age;
};
class mycompare {
public:
	bool operator()(person p1,person p2) const{
		return p1.name > p2.name;//按照姓名降序
	}
};
void test3() {
	map<person, int,mycompare>m;
	m.insert(make_pair(person("bhsd", 210), 151));
	m.insert(make_pair(person("vsaaf", 51), 11));
	m.insert(make_pair(person("df", 32), 121));
	m.insert(make_pair(person("isd", 10), 18));
	for (map<person, int, mycompare>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first.name << ":" << it->first.age << " " << it->second << endl;
	}
	
}
int main(){
	test3();
	return 0;
}