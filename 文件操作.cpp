#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<istream>
#include<String>
using namespace std;
int test() 
{	
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	char buff[200] = { 0 };
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return 0;
	}
	/*while(ifs.getline(buff,sizeof(buff))){
		cout << buff << endl;
	}*/
	//string s;
	//while(getline(ifs,s)) {//第二个参数为string
	//	cout << s<<endl;
	//}
	char c;
	while((c=ifs.get())!= EOF) {
		cout << c;
	}
	
	return 0;
}
class person {
public:
	char name[30];
	int age;
};
void test1() {
	ofstream ofs;
	ofs.open("test1.txt", ios::out | ios::binary);
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
	}
	person p ={"张三", 22};
	ofs.write((const char*)&p, sizeof(person));
	ofs.close();
}
void read() {
	ifstream ifs;
	ifs.open("test1.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	person s2;
	ifs.read((char*)&s2, sizeof(person));
	cout << s2.age << s2.name;
	ifs.close();
}
int main() {
	read();
	return 0;
}