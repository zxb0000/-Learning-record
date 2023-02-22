#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
class Cube {
private:
	double m_l;
	double m_w;
	double m_h;
public:
	void set_h(double h) {
		m_h = h;
	}
	void set_l(double l) {
		m_l = l;
	}
	void set_w(double w) {
		m_w = w;
	}
	double get_h() {
		return m_h;
	}
	double get_w() {
		return m_w;
	}
	double get_l() {
		return m_l;
	}
	bool same(Cube s) {
		if (s.get_h() == m_h && m_l == s.get_l() && m_w == s.get_w()) {
			return true;
		}
		else return false;
	}
};
class Point {
	double x;
	double y;
public:
	void set_x(double n) {
		x = n;
	}
	void set_y(double n) {
		y = n;
	}
	double get_x() {
		return x;
	}
	double get_y() {
		return y;
	}
};
class Round {
private:
	double r;
	Point center;
public:
	void set_r(double n) {
		r = n;
	}
	void set_center(Point n) {
		center = n;
	}
	Point get_center() {
		return center;
	}
	double get_r() {
		return r;
	}
};
void Point_Round(Point p,Round r) {
	double dance = ((p.get_x() - r.get_center().get_x())*(p.get_x() - r.get_center().get_x())+(p.get_y() - r.get_center().get_y())*(p.get_y() - r.get_center().get_y()));
	if ((r.get_r() * r.get_r()) == dance) {
		cout << "在圆上" << endl;
	}
	else if (r.get_r() > dance) {
		cout << "在圆内" << endl;
	}
	else {
		cout << "在圆外" << endl;
	}
}
int main() {
	Round o;
	Point c;
	c.set_x(6);
	c.set_y(5);
	o.set_r(5);
	o.set_center(c);
	Point p;
	p.set_x(5);
	p.set_y(0);
	Point_Round(p, o);
	return 0;
}