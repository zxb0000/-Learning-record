 #pragma once
#include<stdio.h>
#include<string.h>
#define max_name 20
#define MAX 1000//通讯录最大储存人数
#define max_sex 6
#define max_addr 30
#define max_tele 12
enum Opiton {
	EXIT,
	ADD,
	DELE,
	ALTER,
	SELECT,
	SHOW,
	SORT
};
void meun();
struct people {
	char name[max_name];
	char sex[max_sex];
	char addr[max_addr];
	char tele[max_tele];
	int age;
};
struct Contact {
	struct people data[MAX];
	int size;
};
void initContact(struct Contact*);//初始化结构体
void addContact(struct Contact*);//添加联系人
void ShowContact(const struct Contact*);//显示联系表
void DelContact(struct Contact*);//删除联系人
void SelectContact(const struct Contact*);//查找联系人
void AlterContact(struct Contact*);//修改联系人
void SortContact(struct Contact*);//联系人排序


