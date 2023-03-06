#pragma once
#include<iostream>
#include"speaker.h"
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<string>
#include<fstream>
using namespace std;
class manage {
public:
	manage();
	void showmenu();
	void system_exit();
	vector<int>v1;//第一回合的人
	vector<int>v2;//第二回合的人
	vector<int>v_win;//获胜者
	map<int, speaker>m;// 存放编号以及选手
	int round;//比赛论数
	map<int, vector<string>>m_record;
	void initspeech();
	void createspeaker();
	void speechcontest();
	void showscore();
	void starspeech();
	void stardraw();
	void save();
	void loadrecord();
	void showrecord();
	void clearrecord();
	bool fileisempty;
	~manage();
};
