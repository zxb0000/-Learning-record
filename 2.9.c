#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//int main() {
//	int arr[] = { 1,2,3,4,5 };//内存中//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//	int* parr = (int*)(&arr + 1);
//	int* parr2 = (int*)((int)arr + 1);//arr的值加一，相当于加上一个字节，
//	printf("%x ", parr[-1]);//5
//	printf("%x ", *parr2);//2000000
//	return 0;
//}
//int main() {
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	//p指向有四个整型元素的数组，但是a是5*5=25个整型元素，所以将p+1相当于移动4个整型
//	//*（p+4）是p[4]的第一个元素
//	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//p[4][2]=*(p+4)[2]=*(*(p+4)+2)
//	return 0;
//}
//int main() {
//	char* a[] = { "work","at","alibaba" };//指针数组，存放的是字符串首字符的地址
//	char** pa = a;
//	pa++;//将a指向的地址加一，即指向了数组的第二个
//	printf("%s\n", *pa);//%s，从地址开始打印，直到遇到“\n”
//	return 0;
//}
int main() {
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *--*++cpp+3);
	//ER
	printf("%s\n", *cpp[-2]+3);
	//ST ----cpp[-2]=*(cpp-2)
	printf("%s\n", cpp[-1][-1]+1);
	//EW------cpp[-1][-1]+1===*(cpp-1)[-1]+1==*((*cpp-1)-1)+1
	return 0;
}