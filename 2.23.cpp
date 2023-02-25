#include<iostream>
using namespace std;
////单例模式的类
//class Chariman {
//public:
//	static Chariman* getInstance() {//提供外部接口，帮助读取单例默认规定的接口名为getInstance：
//		return Singleman;
//	}
//private:
//	Chariman(Chariman &){}//将拷贝函数私有化
//	Chariman() { cout << "构造函数！" << endl; }//将构造函数私有化
//	static Chariman* Singleman;
//};
//Chariman * Chariman::Singleman = new Chariman;
//int main() {
//	cout << "'main'";
//	Chariman *s =Chariman::getInstance();
//	Chariman* a = Chariman::getInstance();
//	//Chariman a = Chariman(*s);
//	if (s == a) {
//		cout << "s==a" << endl;
//	}
//	return 0;
//
//}
//class building;//类的声明
//class goodgay {
//public:
//	goodgay();//构造函数声明
//	void vist1();//成员函数声明
//	void vist2();
//private:
//	building* build;
//};
//
//class building {
//public:
//	friend void goodgay::vist1();//声明类中的函数做友元
//	building();//构造函数声明
//	string sittingroom;
//private:
//	string bedroom;
//};
//building::building() {//构造函数
//	sittingroom = "客厅";
//	bedroom = "卧室";
//}
//
//goodgay::goodgay() {//构造函数
//	build = new building;
//}
//void goodgay::vist1() {
//	cout << "vist1" << endl;
//	cout << build->sittingroom << endl;
//	cout << build->bedroom << endl;
//}
//void goodgay::vist2() {
//	cout << "vist2" << endl;
//	//cout << build->bedroom << endl;
//	cout << build->sittingroom << endl;
//
//}
//void test() {
//	goodgay p;
//	p.vist1();//vist1能够访问 vist2不能
//	p.vist2();
//}
//class person {
//	
//public:
//	person(){}
//	person(int a, int b) :a(a), b(b) {
//	}
//	int a;
//	int b;
//	//person operator+(person& a1) {//成员函数方式重载
//	//	person temp;
//	//	temp.a = a1.a + this->a;
//	//	temp.b = a1.b + this->b;
//	//	return temp;
//	//}
//};
//person operator+(person& s1, person& s2) {//全局函数的重载
//	person temp;
//	temp.a = s1.a + s2.a;
//	temp.b = s1.b + s2.b;
//	return temp;
//}
//void test() {
//	person a1(10, 10);
//	person a2(10, 10);
//	person a3 = a1 + a2;//全局函数的重载 相当于person a3=operator+(a1,a2);
//	person a3 = a1 + a2;//成员函数重载  相当于a3=a1.operator+(a2) 
//	cout << a3.a << ' ' << a3.b << endl;
//}
class person {
public:
	friend ostream& operator<<(ostream& o, person& s);

	person(int a,int b):a(a),b(b) {
	}
	/*void operator<<(ostream &o) {
		cout << a << '-' <<b << endl;
	}*/
private:
	int a;
	int b;
};
ostream& operator<<(ostream & o, person& s) {
	cout << s.a << '-' << s.b << endl;
	return o;
}
void test() {
	person s1(10,20);
	person s2(10,20);
	cout << s1;
}
int main() {
	test();
	return 0;
}