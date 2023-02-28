#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"myarr.hpp"
using namespace std;
template<class T1,class T2>
class person;
template<class T1, class T2>
void printperson(person<T1, T2>& p) {
	cout << p.name << " " << p.age << endl;
}
template<class T1, class T2>
class person {
	//friend void printperson(person<T1, T2>& p) {//全局函数类内实现
	//	cout << p.name << " " << p.age << endl;
	//}
	//类外实现  需要加空模板列表  并且让编译器提前知道这个函数，将printperson函数放在这个类模板之前，
	//并且又要在函数之前声明类模板person;
	friend void printperson<>(person<T1, T2>& p);
public:
	person(T1 n, T2 a) {
		name = n;
		age = a;
	}
private:
	T1 name;
	T2 age;
};

void test(){
	person<string, int>p("张三", 20);
	printperson(p);
}
void test1() {
	myarr<int>p(10);
	
}
int main() {
	test1();
	return 0;
}