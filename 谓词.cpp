#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class greaterfive {
public:
	bool operator()(int a) {//一个参数，一元谓词
		return a > 5;
	}
};
void test() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), greaterfive());//pred谓词，
		//find_if找到满足条件的返回所在的迭代器，没找返回end（）
		//greaterfive()为匿名函数对象
		cout << *pos;
}
int main() {
	test();
	return 0;
}