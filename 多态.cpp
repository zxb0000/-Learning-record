#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class base {
//public:
//	int a;int b=20;
//protected:
//	
//private:
//	int c;
//};
//class son : public base{
//public:
//	int b=10;
//};
class animal {
public:
	virtual void speak() {//虚函数--子类中相同的函数将重写这个函数，形成函数地址的 晚绑定 
		cout << "动物都在说话" << endl;
	}
};
class cat :public animal {
public:
	void speak() {
		cout << "小猫都在说话" << endl;
	}
};
class dog :public animal {
public:
	void speak() {
		cout << "小狗都在说话" << endl;
	}
};
void dosepak(animal& an) {//父类的指针或者引用 将指向子类，所以将子类填入也能进行,形成动态多态
	an.speak();
}
void test() {
	cat cat;
	dog dog;
	dosepak(cat);
	dosepak(dog);
}