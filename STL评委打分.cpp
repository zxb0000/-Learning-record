#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
class person {
public:
	person(string n, int s):name(n), score(s) {}
	string name;
	int score;
};
void printpeson(const vector<person>&v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].name << " 平均分：" << v[i].score << endl;
	}

}
void createperson(vector<person>&v) {
	
	string n = "ABCDE";
	for (int i = 0; i < n.size(); i++) {
		string name = "选手：";
		name += n[i];
		person p(name, 0);
		v.push_back(p);
	}
//	printpeson(v);
}
void pingfeng(vector<person>&v) {
	
	for (int i = 0; i < v.size(); i++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			d.push_back(rand()%41+60);
		}
		sort(d.begin(),d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (int i = 0; i < d.size(); i++) {
			cout << d[i] << " " ;
			sum += d[i];
		}
		cout << endl;
		sum /= d.size();
		v[i].score = sum;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	vector<person>v;
	createperson(v);
	pingfeng(v);
	printpeson(v);
	return 0;
}