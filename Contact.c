#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
void meun() {
	printf("--------------------------------------------------------\n");
	printf("----------1.添加联系人           2.删除联系人-----------\n");
	printf("----------3.修改联系人           4.查询联系人-----------\n");
	printf("----------5.显示联系人列表       6.联系人智能排序-------\n");
	printf("--------------------------------------------------------\n");
	printf("---------------------0.退出通讯录-----------------------\n");
	printf("--------------------------------------------------------\n");
}
void initContact(struct Contact* ps) {
	memset(ps->data,0, sizeof(ps->data));
	ps->size = 0;
}
void addContact(struct Contact* ps) {
	if (ps->size == MAX) {
		printf("联系人已满，无法添加！\n");
	}
	else
	{
		printf("请输入联系人姓名：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入联系人性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入联系人年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入联系人住址：");
		scanf("%s", ps->data[ps->size].addr);
		printf("请输入联系人电话：");
		scanf("%s", ps->data[ps->size].tele);
		ps->size++;
		printf("联系人\%s保存成功！\n", ps->data[ps->size].name);
	}
}
static int FindebyName(const struct Contact*ps,char name[max_name]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {//查找
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
	
}
void ShowContact(const struct Contact*ps) {
	if (ps->size == 0) {
		printf("联系人列表为空！\n");
	}

	else{
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "姓名", "性别", "年龄", "住址", "电话");
		int i = 0;
		for (i = 0; i < ps->size; i++) {
			printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].addr,
				ps->data[i].tele
			);
		}
	}
	
}
void DelContact(struct Contact*ps) {
	char name[max_name] = {0};
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	int ret=FindebyName(ps, name);
	if (ret == -1) {
		printf("未查找到要删除的联系人!\n");
	}
	else {
		int j = 0;
		for (j = ret; j < ps->size - 1; j++) {//删除并移动数据
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("联系人：%s 已成功删除！\n", name);
	}
}
void SelectContact(const struct Contact*ps) {
	char name[max_name] = { 0 };
	printf("请输入要查找的联系人姓名：");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("未查找到该联系人!\n");
	}
	else {
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "姓名", "性别", "年龄", "住址", "电话");
		printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
			ps->data[ret].name,
			ps->data[ret].sex,
			ps->data[ret].age,
			ps->data[ret].addr,
			ps->data[ret].tele
		);
	}
}
void AlterContact(struct Contact*ps) {
	char name[max_name] = { 0 };
	printf("请输入要修改信息的联系人姓名：");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("未查找到该联系人!\n");
	}
	else {
		printf("请输入联系人姓名：");
		scanf("%s", ps->data[ret].name);
		printf("请输入联系人性别：");
		scanf("%s", ps->data[ret].sex);
		printf("请输入联系人年龄：");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入联系人住址：");
		scanf("%s", ps->data[ret].addr);
		printf("请输入联系人电话：");
		scanf("%s", ps->data[ret].tele);
		printf("联系人信息修改成功！\n");
	}
}
static int com_name(const void* pa1,const void *pa2) {//按姓名排序
	return strcmp(((struct Contact*)pa1)->data->name,((struct Contact*)pa2)->data->name);
}
void SortContact(struct Contact*ps) {
	qsort(ps->data, ps->size, sizeof(ps->data[0]), com_name);
	printf("排序完成！\n");
}


