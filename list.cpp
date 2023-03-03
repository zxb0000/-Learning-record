#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
class person {
public:
	person(string n,int a,int w,int h):name(n),age(a),weight(w),high(h){}
	string name;
	int age;
	int weight;
	int high;
};
void printlist(list<person>l) {
	for (list<person>::const_iterator it = l.begin(); it != l.end();it++) {
		cout << it->name << " " << it->age << " " << it->weight << " " << it->high << endl;
	}
}
bool compare1(person p1,person p2) {
	if (p1.age == p2.age) {
		return p1.high> p2.high;
	}
	return p1.age < p2.age;
}
void test() {
	list<person>l;
	person p1("张三",51, 120,180);
	person p2("王五",51, 100,167);
	person p3("李四",21, 130,178);
	person p4("吗是",31, 152,190);
	person p5("成我",51, 120,177);
	person p6("让对方",51, 120,168);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	printlist(l);
	l.sort(compare1);
	cout << "--------------" << endl;
	printlist(l);
}
int main() {
	test();
	return 0;
}