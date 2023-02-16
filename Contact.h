 #pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define defcap 3//初始通讯录大小
#define max_name 20
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
	SORT,
	SAVE
};
void meun();
typedef struct people {
	char name[max_name];
	char sex[max_sex];
	char addr[max_addr];
	char tele[max_tele];
	int age;
}people;
typedef struct Contact {
	int cap;
	int size;
	struct people* data;
}Contact;
void initContact(struct Contact*);//初始化结构体
void addContact(struct Contact*);//添加联系人
void ShowContact(const struct Contact*);//显示联系表
void DelContact(struct Contact*);//删除联系人
void SelectContact(const struct Contact*);//查找联系人
void AlterContact(struct Contact*);//修改联系人
void SortContact(struct Contact*);//联系人排序
void DestoryContact(struct Contact*);//销毁联系表
void SaveContact(Contact*);//保存联系人
void ReadContact(Contact*);//读取联系人



