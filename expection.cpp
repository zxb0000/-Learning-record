#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;
class myoutofrange :public exception {
public:
	myoutofrange(string &err) {
		this->errinfo = err;
	}
	myoutofrange(const char* err) {
		this->errinfo = err;//可以隐式转换
	}
 virtual char const* what() const
	{
	 return this->errinfo.c_str();//转换成const char*
	}
 string errinfo;
};
class person {
public:
	person(int p) {
		if (p < 0 || p>150) {
			throw myoutofrange("参数范围错误");
		}
		else {
			age = p;
		}
		
	}
	int age;
};
void test() {
	try {
		person(1000);
	}
	catch (exception &e) {
		cout<<e.what()<<endl;
		
	}
}
int main() {
	test();
	return 0;
}