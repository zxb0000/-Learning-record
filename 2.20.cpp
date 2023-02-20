#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>
#if 0
int main() {
	printf("helsld!\n");
	double x = 3.14;
	printf("%lf,%lf \n",sqrt(x),sin(x));
	char he[] = "hesss !";
	puts(he);
		return 0;
}
#endif
////using namespace std;//也可以直接声明名字空间
////using std::cout;//可以这样引入
////int main() {
////	cout << "helllsd"<<std::endl;//endl相当于换行符
////	std::cout << 1+2 <<std::endl;
////	double radius;
////	std::cin >> radius;//输入流>>
////	cout << radius *radius* 3.14<<endl;
////	return 0;
////}
////#include<fstream>
////using namespace std;
////int main() {
////	int a = 3;
////	int& r = a;
////	cout << a << endl;
////	cout << r<< endl;
////	r = 6;
////	cout << a << endl;
////	cout << r << endl;
////	return 0;
////}
////void print(char ch, int n = 1) {
////	for (int i = 0; i < n; i++) {
////		std::cout << ch;
////	}
////}
////int main() {
////	print('#'); std::cout << std::endl;
////	print('#',3);
////	print('#',5);
////
////	return 0;
////}
////函数模板
//#include<string>
//using namespace std;
//template<typename T>
//T add(T a, T b) {
//	return a + b;
//}
//int main() {
//	std::cout<<add<int>(1 ,3)<<endl;
//	std::cout<<add<double>(3.5 ,5)<<endl;
//	std::cout<<add<string>("ss", "aaa"); 
//}
//int main() {
//	std::cout << add(1, 3) << endl;
//	std::cout << add(3.5, 5.0) << endl;//即使不写类型也能自动推断类型进行相应的函数模板
//	std::cout << add(3.5, (double)5) << endl;//如果两个数据的类型不一样就会产生歧异性
//	
//}
//#include<iostream>
//using namespace std;
//int main() {
//	string s1 = "hello,bit", s2("hello word!"), s3{ "整型从v" },s4;
//	cout << s1.size() << endl;
//	cout << s1.substr(2,4) << endl;//提取第二个字符后面4个字符
//	s4=s1.substr(2,4) ;
//	cout << s2+" "+s3<<endl;//能够进行加的拼接
//	s2[2] = 'X';//将s2的下标为2的替换为内X
//	int pos=s1.find("llo");//查找llo 并返回他的开始下标
//	cout << pos<<endl;
//	cout << s2.insert(5,"the") << endl;//在下表为5的位置插入
//	for (int i = 0; i < s2.size(); i++) {
//		cout << s2[i] << '-';
//	}
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v1 = {1, 2, 3, 4, 5};//定义一个int向量
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.push_back(25);//最后面已添加一个25
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.pop_back();//弹出最后一个元素
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.resize(3);//重新定义大小为3
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	return 0;
}