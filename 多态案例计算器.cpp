#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class abstractcalculator {//抽象的计算机
public:
	virtual int getresult() {//虚函数，用于多态的实现
		return 0;
	}
	int a;
	int b;
};
class addcalculator :public abstractcalculator{
public:
	int getresult() {//虚函数重写  实现多态
		return a + b;
	}
};
class subcalculator :public abstractcalculator {
public:
	int getresult() {//虚函数重写  实现多态
		return a - b;
	}
};
class mulcalculator :public abstractcalculator {
public:
	int getresult() {//虚函数重写  实现多态
		return a * b;
	}
};
void test() {
	//abstractcalculator* add = new addcalculator;//通过父类的指针调用
	addcalculator add;//add类直接用
	add.a = 10;
	add.b = 20;
	cout<<add.a<<"+"<<add.b <<"="<<add.getresult()<<endl;
	abstractcalculator* sub = new subcalculator;//通过父类的指针调用
	sub->a = 10;
	sub->b = 20;
	cout << sub->a << "-" << sub->b << "=" << sub->getresult()<<endl;
	delete sub;
	sub = new mulcalculator;
	sub->a = 10;
	sub->b = 20;
	cout << sub->a << "*" << sub->b << "=" << sub->getresult() << endl;
	delete sub;

}
int main() {
	test();
	return 0;
}