#include "manage.h"
manage::manage()
{
	initspeech();
	loadrecord();
	createspeaker();
}

void manage::showmenu()
{
	cout << "------------------------------------------------" << endl;
	cout << "---------------  1.开始演讲比赛  ---------------" << endl;
	cout << "---------------  2.查看往届记录  ---------------" << endl;
	cout << "---------------  3.清空比赛记录  ---------------" << endl;
	cout << "---------------  0.退出比赛程序  ---------------" << endl;
	cout << "--------------- ---------------- ---------------" << endl;
}

void manage::system_exit()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void manage::initspeech()
{
	
	this->v1.clear();
	this->v2.clear();
	this->v_win.clear();
	this->m.clear();
	this->round = 1;
	this->m_record.clear();
}

void manage::createspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++) {
		string name = "选手:";
		name += nameseed[i];
		speaker s;
		s.name = name;
		for (int i = 0; i < 2; i++) {
			s.sorce[i] = 0;
		}
		v1.push_back(10001 + i);
		m.insert(make_pair(10001 + i, s));
	}

}

void manage::speechcontest()
{
	cout << "--------      >>>>>    " << "第" << round << "轮比赛正式开始！" << "      <<<<<    --------" << endl;
	vector<int>var;
	if (round == 1) {
		var = v1;
	}
	else if (round == 2) {
		var = v2;
	}
	int num = 0;
	multimap<double, int, greater<double>>groupScore;
	for (vector<int>::iterator it = var.begin(); it != var.end(); it++) {
		num++;
		deque<double>de;
		double score;
		for (int i = 0; i < 10; i++) {
			score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			de.push_back(score);
		}
		//cout << endl;
		sort(de.begin(), de.end(), greater<double>());
		de.pop_back();
		de.pop_front();
		double sum = accumulate(de.begin(), de.end(), 0.0);
		double avg = sum / (double)de.size();
		this->m[*it].sorce[this->round - 1] = avg;
		/*cout << "编号：" << *it << " " << "姓名：" << this->m[*it].name << " "
			<< "平均分：" << this->m[*it].sorce[this->round - 1] << endl;*/
		groupScore.insert(make_pair(avg, *it));
		
		if (num % 6 == 0) {
			cout << "--------------------- 第" << num / 6 << "小组的比赛成绩名次如下 ---------------------" << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end() ; it++) {
				cout << "编号：" << it->second << " " << "姓名：" << this->m[it->second].name << " "
					<< "成绩：" << this->m[it->second].sorce[this->round - 1] << endl;
			}
			
			int count = 0;//取走前三名
			for (multimap<double, int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++) {
				if (round == 1) {
					v2.push_back(it->second);
				}
				else if (round == 2) {
					v_win.push_back(it->second);
				}
			}
			groupScore.clear();//清空残留的数据，防止下次在读取
			cout << endl;
		}

	}
	cout << "--------      >>>>>    " << "第" << round << "轮比赛结束！" << "      <<<<<    --------" << endl;
	system("pause");
}

void manage::showscore()
{
	cout << "--------------------------  第" << round << "轮的晋级名单为 --------------------------" << endl;
	vector<int>v;
	if (round == 1) {
		v = v2;
	}
	else {
		v = v_win;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "编号：" << *it << "  姓名："<<this->m[*it].name<< "成绩：" <<this-> m[*it].sorce[round-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void manage::starspeech()
{
	//1.抽签
	this->stardraw();
	//2.比赛
	this->speechcontest();
	//3.显示结果
	this->showscore();
	this->round++;
	//1.抽签
	this->stardraw();
	//2.比赛
	this->speechcontest();
	//3.显示结果
	this->showscore();
	//保存结果
	this->save();
	//重置数据
	initspeech();
	loadrecord();
	createspeaker();

}

void manage::stardraw()
{
	if (round == 1) {
		cout << "选手们正在进行第" << round << "轮抽签!" << endl;
		cout << "--------------------------------------------" << endl;
		cout<<"结果如下："<<endl;
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), [](int a) {cout << a << " "; });
		cout << endl;
	}
	if (round == 2) {
		cout << "选手们正在进行第" << round << "轮抽签!" << endl;
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
		cout << endl;
	}
	cout << "--------------------------------------------" << endl;
	system("pause");
}

void manage::save()
{
	ofstream ofs("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v_win.begin(); it != v_win.end(); it++) {
		ofs<< *it <<","<< m[*it].sorce[1] << ",";
	}
	ofs << endl;
	ofs.close();
	fileisempty = false;
	cout << "保存成功！" << endl;
}

void manage::loadrecord()
{
	
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		//cout << "文件打开失败！" << endl;
		fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空！" << endl;
		fileisempty = true;
		ifs.close();
		return;
	}
	fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs>>data) {
		//cout << data;
		int star = 0;
		int pos = -1;
		vector<string>v;
		while (1) {
			pos = data.find(",", star);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(star, pos-star);
			//cout << temp << endl;
			v.push_back(temp);
			star = pos + 1;
		}
		this->m_record.insert(make_pair(index,v));
		index++;
	}
	/*for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++) {
		cout << "第" << it->first <<"届 " << " 冠军的编号：" 
			<< it->second[0] << " 分数为：" << it->second[1] << endl;
	}*/
	ifs.close();
	
}

void manage::showrecord()
{
	if (this->fileisempty) {
		cout << "文件为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "第" << i + 1 << "届"
				<< "  冠军编号 ：" << m_record[i][0] << " 成绩: " << m_record[i][1]
				<< "  亚军编号 ：" << m_record[i][2] << " 成绩: " << m_record[i][3]
				<< "  季军编号 ：" << m_record[i][4] << " 成绩: " << m_record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void manage::clearrecord()
{
	int choice;
	cout << "是否确认清空？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		initspeech();
		loadrecord();
		createspeaker();
		cout << "清空完成！" << endl;
	}
	system("pause");
	system("cls");
}

manage::~manage()
{
}
