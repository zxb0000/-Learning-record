#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void getmem(char* p) {
	p = (char*)malloc(100);
}
void test() {
	char* str =NULL;
	getmem(str);
	//这个地方为传值，传送的是str的值，当p接受后为str的拷贝（p和str同为char*类型，所以是传值），并不影响原来的值，要想进行传地址需要&str，
	//并将函数的形参改为二级指针，解引用后进行malloc，这也才能正确的申请空间给str；
	printf(str);
	strcpy(str, "hello");
	printf(str);
}
int main() {
	test();
	return 0;
}