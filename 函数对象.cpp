#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class myadd {
public:
	int operator()(int a,int b) {
		return a + b;
	}
};
void test() {
	myadd myadd;
	std::cout<<myadd(10, 5);//可以有参数，返回值
}
class myprint {
public:
	void operator()(std::string test) {
		cout << test << endl;
		num++;
	}
	int num = 0;
};
void test2() {
	myprint print;
	print("hello word");
	print("hello word");
	print("hello word");
	print("hello word");//
	cout << print.num;//可以有自己的状态
}
void func(myprint my,string s) {
	my(s);
}
void test3() {
	myprint m;
	func(m, "函数对象可以作为函数的参数传递");
}
int main() {
	test3();
	return 0;
}