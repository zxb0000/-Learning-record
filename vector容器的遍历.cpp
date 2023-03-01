#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(int v) {
	cout << v << endl;
}
class person {
public:
	person(string n, int a) :name(n), age(a) {};
	string name;
	int age;
};
void test() {
	vector<int> v;//声明容器对象，模板存放的类型为int，需要包含容器头文件vector
	v.push_back(10);//向容器的最后面插入数据
	v.push_back(20);
	v.push_back(120);
	v.push_back(11);
	v.push_back(10);
	//容器的遍历
	// 迭代器也就是相当于指针
	//第一种
	vector<int>::iterator itbegin = v.begin();//返回迭代器。这个迭代器指向容器中第一个元素
	vector<int>::iterator itend = v.end();//返回迭代器，这个迭代器指向容器中最后一个元素的下一个位置
	while (itbegin != itend) {
		cout << *itbegin << endl;
		itbegin++;
	}
	//第二种
	for (vector<int>::iterator begin = v.begin(); begin != v.end(); begin++) {
		cout << *begin << endl;
	}
	//第三种 借助算法需要包含头文件algorithm
	for_each(v.begin(), v.end(), print);//需要提供输出函数的地址，也就是函数名,类似qsort中的比较函数
	
}
void test1() {//容器存放自定义类型
	vector<person> v;
	person p1("爱上代表1", 10);
	person p2("爱上代表2", 20);
	person p3("爱上代表3", 30);
	person p4("爱上代表4", 40);
	person p5("爱上代表5", 50);
	person p6("爱上代表6", 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->name << " " << it->age << endl;
	}
}
void test2() {
	vector<person*> v;//指针数组
	person p1("爱上代表1", 10);
	person p2("爱上代表2", 20);
	person p3("爱上代表3", 30);
	person p4("爱上代表4", 40);
	person p5("爱上代表5", 50);
	person p6("爱上代表6", 60);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->name << "* " << (*it)->age << endl;
	}
}
void test3() {//容器的嵌套
	vector<vector<int>> bv;//容器中存放着vector<int>类型的数据，
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	for (int i = 0; i < 5; i++) {//初始化五个小的容器，放入数据
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
		v5.push_back(i+5);
	}
	bv.push_back(v1);//将小容器放入大容器bv中
	bv.push_back(v2);
	bv.push_back(v3);
	bv.push_back(v4);
	bv.push_back(v5);
	for (vector<vector<int>>::iterator bit = bv.begin(); bit != bv.end(); bit++) {
		//访问大容器中的每个小容器
		for (vector<int>::iterator it = bit->begin(); it != bit->end(); it++) {
			//访问每个小容器中得元素int，*bit代表每个小容器,可以通过->来访问类函数begin和end；
			cout << *it << " ";
		}
		cout << endl;//每访问一个小容器进行换行
	}
}
int main() {
	test3();
	return 0;
}