#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class abstractdrinking {//抽象类
public:
	//烧水
	virtual void absboiling() = 0;//纯虚函数
	//加入饮品
	virtual void absbeverage() = 0;
    //装入杯中
	virtual void abscup() = 0;
	//加入调料
	virtual void absseasoning()=0;
	void makedrinking(){
		absboiling();
		absbeverage();
		abscup();
		absseasoning();
		cout << "制作完成！" << endl;
	}
};
class tea:public abstractdrinking {
	//烧水
	virtual void absboiling() {//纯虚函数
	
		cout << "加入天然泉水！" << endl;
	}
	//加入饮品
	virtual void absbeverage() {
		cout << "加入茶叶" << endl;
	}
	//装入杯中
	virtual void abscup() {
		cout << "倒入茶杯中" << endl;
	}
	//加入调料
	virtual void absseasoning() {
		cout << "加入枸杞！" << endl;
	}
};
class coffee :public abstractdrinking {
	//烧水
	virtual void absboiling() {//纯虚函数

		cout << "加入泉水！" << endl;
	}
	//加入饮品
	virtual void absbeverage() {
		cout << "加入猫屎咖啡" << endl;
	}
	//装入杯中
	virtual void abscup() {
		cout << "倒入咖啡杯中" << endl;
	}
	//加入调料
	virtual void absseasoning() {
		cout << "加入糖块！" << endl;
	}
};
void dodrinking(abstractdrinking * abs) {
	abs->makedrinking();
	delete abs;
}
int main() {
	dodrinking(new coffee);
	dodrinking(new tea);
	return 0;
}