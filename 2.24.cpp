#include<iostream>
#include<stdio.h>
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
//class person {
//public:
//	friend ostream& operator<<(ostream& o, person& s);
//
//	person(int a,int b):a(a),b(b) {
//	}
//	/*void operator<<(ostream &o) {
//		cout << a << '-' <<b << endl;
//	}*/
//private:
//	int a;
//	int b;
//};
//ostream& operator<<(ostream & o, person& s) {
//	cout << s.a << '-' << s.b << endl;
//	return o;
//}
//void test() {
//	person s1(10,20);
//	person s2(10,20);
//	cout << s1;
//}
//int main() {
//	test();
//	return 0;
//}
//自增运算符重载//
//class person {
//public:
//	friend ostream& operator<<(ostream& o, person a);
//	person() {
//		a = 0;
//	}
//	person& operator++() {//++a
//		this->a++;
//		return *this;
//	}
//	person operator++(int) {//++a
//		person temp;
//		temp = *this;
//		this->a++;
//		return temp;
//	}
//private:
//	int a;
//};
//ostream& operator<<(ostream& o, person a) {
//	cout << a.a << endl;
//	return o;
//}
//void test() {
//	person n;
//	
//	//(++n);//相当于n.operator++();
//	//n++;
//	cout<< n++;//相当于n.operator++(int)
//	cout << n;
//}
//class person {
//public:
//	person(int a) {
//		age = new int(a);
//	}
//	int* age;
//	
//	~person() {
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//	}
//	person& operator=(person& s) {
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//		age = new int(*s.age);
//		return *this;
//	}
//};
//void test(){
//	person a1(10);
//	person a2(12);
//	person a3(5);
//		a3=a2 = a1;
//	cout << *a1.age << endl;
//	cout << *a2.age << endl;
//	cout << *a3.age << endl;
//}
//class person {
//public:
//	person(string name,int age):m_age(age),m_name(name) {
//
//	}
//	string m_name;
//	int m_age;
//	bool operator==(person &s) {//==重载
//		if (m_age == s.m_age && m_name == s.m_name) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	bool operator!=(person& s) {//!=重载
//		if (m_age == s.m_age && m_name == s.m_name) {
//			return false;
//		}
//		else {
//			return true;
//		}
//	}
//};
//void test() {
//	person a1("tom", 25);
//	person a2("tom", 25);
//	if (a1 == a2) {
//		cout << "一样" << endl;
//	}
//	else {
//		cout << "不一样" << endl;
//	}
//	if (a1 != a2) {
//		cout << "不一样" << endl;
//	}
//	else {
//		cout << "一样" << endl;
//	}
//}
//class person {
//public:
//	person(int n) {
//		cout << "person构造函数" << endl;
//		age = n;
//	}
//	void showage() {
//		cout << "年龄为：" << age << endl;
//	}
//	~person() {
//		cout << "person的析构函数" << endl;
//	}
//	int age;
//};
//class smartPoint {//智能指针用来管理指针，可以利用析构函数自动释放指针所指向的空间
//public:
//	person* operator->() {//实现->访问
//		return this->point;
//	}
//	person operator*() {//实现解引用访问
//		return *this->point;
//	}
//	smartPoint(person* p) {
//		cout << "智能指针的构造函数" << endl;
//		this->point = p;
//	}
//	~smartPoint() {//用析构函数来释放指针
//		cout << "smartPOint析构函数" << endl;
//		if (this->point != NULL) {
//			delete point;
//			point = NULL;
//		}
//	}
//
//	person* point;
//};
//void test() {
//	//person* p1 = new person(20);//new申请的空间在堆区，由用户自己释放
//	//p1->showage();	//用户不主动释放指针，不会调用解析函数；
//	//(*p1).showage();
//	smartPoint p(new person(20));//用智能指针p来管理person类型的对象
//	p->showage();
//	(*p).showage();
//
//}
void test() {
	int s[5] = { 1,2,3,4,5 };
	int* ptr = (int*)((int)s + 1);
	printf("%x\n", *ptr);
}
int main() {
	test();
	return 0;
}