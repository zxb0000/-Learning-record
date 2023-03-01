#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test() {
	cout << "请输入一串字符或者数字";
	char a = cin.peek();
	if (a >= '0' && a <= '9') {
		int num;
		cin>>num;
		cout << "您输入的是数字：" << num << endl;
	}
	else {
		char buff[1024];
		cin >> buff;
		cout << "您输入的是字符串：" << buff<< endl;
	}
}
void test1() {
	int num=-1;
	cout << "请输入0-10之间的数字：" << endl;
	while (1) {
		cin >> num;//cin在写入数据失败时，会将原变量置零，而且当溢出时，会写入std::numeric_limits::max() 或 std::numeric_limits::min()，
		//cout << num << endl;
		if(!cin.fail()&& num >= 0 && num <= 10)
		 {
			//cout << num << endl;
			cout << "输入正确！" <<endl;
			cout << cin.fail() << endl;//fail标志位,最近的一次cin输入错误返回1，否则返回0
			break;
		}
		cout << cin.fail() << endl;//fail标志位
		cin.clear();//标志位清楚
		//cin.sync();//刷新缓冲区  vs2015以上不好用，可以使用getlinne
		char p[1024] = { 0 };
		cin.getline(p,1024);
		
		cout << "请输入正确的数字！" << endl;
	}
}
int main() {
	test1();
	int *p=&014；
	return 0;
}