 #pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define defcap 3//��ʼͨѶ¼��С
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
void initContact(struct Contact*);//��ʼ���ṹ��
void addContact(struct Contact*);//�����ϵ��
void ShowContact(const struct Contact*);//��ʾ��ϵ��
void DelContact(struct Contact*);//ɾ����ϵ��
void SelectContact(const struct Contact*);//������ϵ��
void AlterContact(struct Contact*);//�޸���ϵ��
void SortContact(struct Contact*);//��ϵ������
void DestoryContact(struct Contact*);//������ϵ��
void SaveContact(Contact*);//������ϵ��
void ReadContact(Contact*);//��ȡ��ϵ��



