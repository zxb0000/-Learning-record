#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
void meun() {
	printf("--------------------------------------------------------\n");
	printf("----------1.�����ϵ��           2.ɾ����ϵ��-----------\n");
	printf("----------3.�޸���ϵ��           4.��ѯ��ϵ��-----------\n");
	printf("----------5.��ʾ��ϵ���б�       6.��ϵ����������-------\n");
	printf("---------------------7.����ͨѶ¼-----------------------\n");
	printf("---------------------0.�˳�ͨѶ¼-----------------------\n");
	printf("--------------------------------------------------------\n");
}
void initContact(struct Contact* ps) {
	ps->data = (people *)malloc(defcap * sizeof(people));
	if (ps->data == NULL) {
		return;
	}
	ps->cap = defcap;
	ps->size = 0;
	FILE* fp = fopen("Contact.dat", "ab");//�����洢�ļ�
	if (fp == NULL) {
		printf("initContact:%s", strerror(errno));
		return;
	}
	fclose(fp);
	fp = NULL;
	ReadContact(ps);
}
void check_cap(Contact* ps) {
	if (ps->cap == ps->size) {
		people* pst = realloc(ps->data, (ps->cap + 2) * sizeof(people));
		if (pst != NULL) {
			ps->data = pst;
			printf("�ڴ����ӳɹ���\n");
			ps->cap += 2;
		}
		else {
			printf("�ڴ�����ʧ�ܣ�\n");
		}
	}
}
void addContact(struct Contact* ps) {
	check_cap(ps);
	printf("��������ϵ��������");
	scanf("%s", ps->data[ps->size].name);
	printf("��������ϵ���Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("��������ϵ�����䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("��������ϵ��סַ��");
	scanf("%s", ps->data[ps->size].addr);
	printf("��������ϵ�˵绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("��ϵ��%s����ɹ���\n", ps->data[ps->size].name);
	ps->size++;
	/*if (ps->size == MAX) {
		printf("��ϵ���������޷���ӣ�\n");
	}
	else
	{
		printf("��������ϵ��������");
		scanf("%s", ps->data[ps->size].name);
		printf("��������ϵ���Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("��������ϵ�����䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("��������ϵ��סַ��");
		scanf("%s", ps->data[ps->size].addr);
		printf("��������ϵ�˵绰��");
		scanf("%s", ps->data[ps->size].tele);
		ps->size++;
		printf("��ϵ��\%s����ɹ���\n", ps->data[ps->size].name);
		}*/
	
}
static int FindebyName(const struct Contact*ps,char name[max_name]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {//����
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
	
}
void ShowContact(const struct Contact*ps) {
	if (ps->size == 0) {
		printf("��ϵ���б�Ϊ�գ�\n");
	}

	else{
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "סַ", "�绰");
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
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	int ret=FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�Ҫɾ������ϵ��!\n");
	}
	else {
		int j = 0;
		for (j = ret; j < ps->size - 1; j++) {//ɾ�����ƶ�����
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("��ϵ�ˣ�%s �ѳɹ�ɾ����\n", name);
	}
}
void SelectContact(const struct Contact*ps) {
	char name[max_name] = { 0 };
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�����ϵ��!\n");
	}
	else {
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "סַ", "�绰");
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
	printf("������Ҫ�޸���Ϣ����ϵ��������");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�����ϵ��!\n");
	}
	else {
		printf("��������ϵ��������");
		scanf("%s", ps->data[ret].name);
		printf("��������ϵ���Ա�");
		scanf("%s", ps->data[ret].sex);
		printf("��������ϵ�����䣺");
		scanf("%d", &(ps->data[ret].age));
		printf("��������ϵ��סַ��");
		scanf("%s", ps->data[ret].addr);
		printf("��������ϵ�˵绰��");
		scanf("%s", ps->data[ret].tele);
		printf("��ϵ����Ϣ�޸ĳɹ���\n");
	}
}
static int com_name(const void* pa1,const void *pa2) {//����������
	return strcmp(((people*)pa1)->name,((people*)pa2)->name);
}

void SortContact(struct Contact*ps) {
	qsort(ps->data, ps->size, sizeof(people), com_name);
	printf("������ɣ�\n");
}
void DestoryContact(struct Contact*ps) {
	free(ps->data);
	ps->data = NULL;
	printf("�Ѿ��˳�ͨѶ¼��\n");
}
void SaveContact(Contact*ps) {
	int i = 0;
	FILE* Wfp = fopen("Contact.dat", "wb");
	if (Wfp == NULL) {
		printf("SaveContact: %s\n", strerror(errno));
		return;
	}
	for(i=0;i<ps->size;i++){
		fwrite(&ps->data[i], sizeof(people), 1, Wfp);
	}
	fclose(Wfp);
	Wfp = NULL;
	printf("ͨѶ¼����ɹ���\n");
}
void ReadContact(Contact* ps) {
	people temp = { 0 };
	FILE* Rfp = fopen("Contact.dat", "rb");
	if (Rfp == NULL) {
		printf("ReadContact: %s\n", strerror(errno));
		return;
	}
	while (fread(&temp, sizeof(people), 1, Rfp)) {
		check_cap(ps);
		ps->data[ps->size] = temp;
		ps->size++;
	}
	fclose(Rfp);
	Rfp = NULL;
}


