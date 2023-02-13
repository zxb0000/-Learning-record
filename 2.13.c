#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
enum sex {
	male,
	famale
};

int check_sys() {
	union Un{
		int i;
		char a;
	};
	union Un u = {1};// 初值需要用 “{}” 括起来。
	return u.a;//返回1小端，返回0大端
}
int main() {
	//enum sex sex1 = male;
	int rect = check_sys();
	printf("%d", rect);
}