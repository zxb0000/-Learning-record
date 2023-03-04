#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class print:public binary_function<int,int,void> {//第二步，仿函数继承父类
public:
	void operator()(int a,int star) const {//第三步，重写父类的仿函数，要加const
		//输出的时候想要加一个基值，可以通过适配器来实现
		cout << a<<" " <<star << " "<<a+star<<endl;
	}
};
void test() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "请输入想要添加的基值" << endl;
	int star;
	cin >> star;
	for_each(v.begin(), v.end(), bind2nd(print(),star));//第一步绑定参数
								//bind1st是将参数绑定到仿函数的第一个参数
								//bind1nd是将参数绑定到仿函数的第二个参数

}
class greaterFive :public unary_function<int,bool>{
	//第二步继承，只有一个参数继承一元继承unary_functiom,两个二元继承binary_function
public:
	bool operator()(int a) const{//第三步加const 重写父类
		return a > 5;
	}
};
void test2() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	//vector<int>::iterator it=find_if(v.begin(), v.end(), not1(greaterFive()));
	//notl取反适配器 ----第一步加not1  not1一元取反，not2二元取反
	vector<int>::iterator it=find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(),5 )));
	//也可以利用内建函数来进行绑定和取反适配，这时就只需要加适配器名称就好
	
	if (it == v.end()) {
		cout << "没找到" << endl;
	}
	else {
		cout << "找到了：" << *it << endl;
	}
	sort(v.begin(), v.end(), not2(greater<int>()));//not2二元取反
	for_each(v.begin(), v.end(), [](int a) {cout << a << " "; });
	// [](int a) {cout << a << " "; }匿名函数
}
void  print(int a,int star) {
	cout << a+star << " ";
}
void test3(){//函数指针适配器
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "请输入想要添加的基值" << endl;
	int star;
	cin >> star;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print),star));
	//for_each的输出可以用仿函数也可以用函数，但是用函数的时候无法进行像仿函数进行参数的绑定
	//因此可以通过函数指针适配器修饰函数指针进行参数的绑定 ptr_fun(函数名),然后就能够进行绑定操作
	//也不需要像仿函数一样继承父类，直接就能使用
}
class person {
public:
	person(string n,int a):name(n),age(a){

	}
	void show() {
		cout << name << " " << age << endl;
	}
	void addage() {
		age++;
	}
	string name;
	int age;
};
void test4() {
	vector<person >v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for_each(v.begin(), v.end(), mem_fun_ref(&person::show));
	for_each(v.begin(), v.end(), mem_fun_ref(&person::addage));
	for_each(v.begin(), v.end(), mem_fun_ref(&person::show));
	//men_fun_ref成员函数适配器。能够通过外部直接利用成员函数，
	//需要取成员函数的地址进行操作&
}
int main() {
	test4();
	return 0;
}