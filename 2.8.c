#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
struct stu {
	char name[10];
	int age;
};
int com_int(void* e1, void* e2) {
	return *(int*)e1 - *(int*)e2;
}
int com_age(const void* e1, const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int com_name(const void* e1, const void* e2) {
	return strcmp(((struct stu*)e1)->name, (((struct stu*)e2)->name));//strcmp e1大于e2返回正数，等于返回0，小于返回负数
}
void swap( char* e1, char* e2,int width) {
	int i = 0;
	
	for (i = 0; i < width; i++) {
		char temp=0;
		temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;//交换下两个字符
		e2++;
	}
}
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2)) {//cmp指向的函数比较e1和e2，e1大于e2返回大于零的数，等于---0，小于---负数
	int i;
	for (i = 0; i < sz - 1; i++) {
		int j;
		for (j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)base+j*width,(char*) base+(j+1)*width)>0) 
			{//把指针转换为char类型（一个字节）的方便进行比较，每次移动的距离为需要比较元素的类型大小
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
				//一个字节一个字节的进行交换；width为元素类型的字节大小，即需要交换多少个字节
			}
		}
	}
}

int main() {
	struct stu s[3] = {{"zhang",10},{"li",15},{"scan",24}};
	//int sz = sizeof(arr) / sizeof(arr[0]);
	///qsort(arr, sz, sizeof(arr[0]), com_age);
	//第一个参数：待排数组的首元素地址
	//2；待排元素的个数
	//3:	 待排元素所占空间大小的字节
	//4：比较函数指针
	//int arr[10] = { 1,5,7,3,4,6,8,9,2,8 };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]),com_name);
	return 0;
}