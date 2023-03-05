#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
class person {
public:
	person(string n, int a): name(n), age(a) {

	}
	bool operator==(const person &s) {
		if (s.age == this->age && s.name == this->name)
			return true;
		else
			return false;
	}
	string name;
	int age;
};
class greater20 {
public:
	bool operator()(person p){
		return p.age > 20;
	}
};
void test() {
	vector<person>v;
	person p1("aaa", 50);
	person p2("bbb", 40);
	person p3("ccc", 30);
	person p4("ddd", 20);
	person p5("eee", 10);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	person px("ccc", 30);
	//vector<person>::iterator it=find(v.begin(), v.end(), px);//
								//find函数在查找自定义数据类型时，需要提供==的重载函数
	vector<person>::iterator it = find_if(v.begin(), v.end(), greater20());
	if (it == v.end()) {
		cout << "没找到！" << endl;
	}
	else {
		cout << "找到了！" << it->name << " " << it->age << endl;
	}
	for_each(v.begin(), v.end(), [](person& s) {cout << s.name << " " << s.age << endl; });
}
void test2() {
	vector<int>v;
	v.push_back(20);
	v.push_back(12);
	v.push_back(3);
	v.push_back(12);
	v.push_back(3);
	v.push_back(3);
	v.push_back(23);
	v.push_back(3);
	vector<int >::iterator it=adjacent_find(v.begin(), v.end());//找到相邻的元素会返回迭代器
	if (it == v.end()) {
		cout << "没找到奥" << endl;
	}else{
		cout << *it<<endl;
	}
	sort(v.begin(), v.end());//二分查找排列必须有序
	if (binary_search(v.begin(), v.end(), 12)) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}
class person2{
public:
	person2(string n, int a) : name(n), age(a) {

	}
	bool operator==(const person2 &p){//重载==
		if (age == 35)
			return true;
		else
			return false;
	}
	string name;
	int age;
};
void test3() {
	vector<person2>v;
	person2 p1("aaa", 31);
	person2 p2("bbb", 32);
	person2 p3("ccc", 35);
	person2 p4("ddd", 33);
	person2 p5("eee", 35);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	person2 p("nsh", 35);
	int num=count(v.begin(), v.end(),p);//根据条件重载==
	cout << "35岁的人有：" << num << endl;
}
class person3 {
public:
	person3(string n, int a) : name(n), age(a) {

	}
	string name;
	int age;
};
class greatr32 {
public:
	bool operator()(const person3 &p) {
		return p.age > 32;
	}
};
void test4() {
	vector<person3 >v;
	person3 p1("aaa", 31);
	person3 p2("bbb", 32);
	person3 p3("ccc", 35);
	person3 p4("ddd", 33);
	person3 p5("eee", 35);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num=count_if(v.begin(), v.end(), greatr32());//pred谓词
	cout << num << endl;
}
void test5() {
	srand((unsigned int)time(NULL));
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int a) {cout << a << " "; });
	cout << endl;
	random_shuffle(v.begin(), v.end());//也要随机种子才能真随机
	for_each(v.begin(), v.end(), [](int a) {cout << a << " "; });

}
void test6() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+1);
	}
	vector<int>v3;
	v3.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	for_each(v3.begin(), v3.end(),[](int a){cout << a << " ";});
}
void test7() {
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(i + 1);
	}
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout << endl;
	reverse(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
}
void test8() {
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(i + 1);
	}
	vector<int>v3;
	v3.resize(v2.size());
	copy(v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), [](int a) {cout << a << " "; });
}
void test9() {
	vector<int>v2;
	v2.push_back(10);
	v2.push_back(54);
	v2.push_back(20);
	v2.push_back(10);
	v2.push_back(8);
	v2.push_back(60);
	v2.push_back(46);
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout << endl << "--------------" << endl;
	replace(v2.begin(), v2.end(), 10, 999);
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
}
void test10() {
	vector<int>v2;
	v2.push_back(10);
	v2.push_back(54);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(10);
	v2.push_back(8);
	v2.push_back(60);
	v2.push_back(46);
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout << endl << "--------------" << endl;
	replace_if(v2.begin(), v2.end(), bind2nd(greater_equal<int>(), 30), 9999);//大于等于三十的被替换9999
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
}
void test11() {
	vector<int>v2;
	vector<int>v3;
	v2.push_back(10);
	v2.push_back(54);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(10);
	v2.push_back(8);
	v2.push_back(60);
	v2.push_back(46);
	for (int i = 0; i < 10; i++) {
		v3.push_back(i);
	}
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout<< endl;
	for_each(v3.begin(), v3.end(), [](int a) {cout << a << " "; });
	swap(v2, v3);
	cout << endl << "----------------" << endl;
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout << endl;
	for_each(v3.begin(), v3.end(), [](int a) {cout << a << " "; });

}
void test12() {//计算容器数值总和accumulate,需要添加头文件numeric
	vector<int>v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);//累加的基值0
		cout << total;
}
void test13() {
	vector<int>v;
	v.resize(10);//设置容器的大小，默认用0来填充，如果后期想要更改默认的填充的数据可以用fill来
	//重新装载  也要包含头文件numeric
	fill(v.begin(), v.end(), 100);//用100来填充
	for_each(v.begin(), v.end(), [](int a) {cout << a << " "; });
}
void test14() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int>v3;
	v3.resize(min(v1.size(), v2.size()));//存放交集的容器大小设置为较小的一个容器的大小
	//两个容器的排序必须有序,才能使用set_intersection
	vector<int>::iterator itend=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//函数将返回交集结束的迭代器的位置,
	//因为v3迭代器的大小是通过特殊情况考虑的，可能没有装满，会有默认填充的数据，
	//所以遍历的时候结束位置应填写返回的迭代器,否则的话，将会导致交集的错误显示
	for_each(v3.begin(), itend, [](int a) {cout << a << " "; });

}
void test15() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector < int>v3;
	v3.resize(v1.size() + v2.size());//并集最大为两个容器的之和
	vector<int>::iterator itend=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itend, [](int a) {cout << a << " "; });

}
void test16() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector < int>v3;
	v3.resize(max(v1.size(),v2.size()));//差集的容器大小最大为两个容器中最大的一个
	cout << "v1和v2的差集" << endl;
	vector<int>::iterator itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itend, [](int a) {cout << a << " "; });
	cout << endl;
	cout << "v2和v1的差集" << endl;
	itend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), itend, [](int a) {cout << a << " "; });
	//求谁的差集就把哪个容器放在前面

}
int main() {
	test16();
	return 0;
}