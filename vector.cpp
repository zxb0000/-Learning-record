#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	if (v1.empty()) {
		cout << "空的" << endl;
	}
	else {
		cout << "容量为" << v1.capacity()<<endl;
		cout << "大小为" << v1.size()<<endl;
	}
	print(v1);
	v1.resize(15,1);//扩展到15个空间，并用1来填充
	print(v1);
	v1.resize(5);
	v1.insert(v1.begin(), 2,1000);
	print(v1);

}
void test2() {
	vector<int>v1;
	for (int i = 0; i < 1100; i++) {
		v1.push_back(i);
	}
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.resize(5);//当重新设置大小后，所占的容量还是和原来一样大，会造成空间的浪费
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
		//和匿名对象互换，实现内存的收缩，匿名对象使用一次后系统就会自动回收
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
}
void test3() {
	vector<int>v1;
	v1.reserve(10000);//提前预留10000个空间，就会一次开辟
	int num = 0;//统计开辟空间的次数
	int* p = NULL;//
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];//每开批一次空间p就指向第一个元素的地址
			num++;
		}
	}
	cout << num;//开辟了24次

	
}
void test4() {
	int* s, p;
	int sp;
	cout << typeid(s).name();
	cout << sp;
}
int main(){
	test4();		
	return 0;
}