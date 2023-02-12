#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memcpy(void* arr1, const void* arr2, int num) {
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	void* ret = arr1;
	while (num--) {
		*(char*)arr1 = *(char*)arr2;
		++(char*)arr1;
		++(char*)arr2;
	}
	return ret;
}
void* my_memmove(void* arr1, const void* arr2, int num) {
	void* ret = arr1;
	if (arr2 > arr1) {
		while (num--) {
			*(char*)arr1 = *(char*)arr2;
			++(char*)arr1;
			++(char*)arr2;
		}
	}
	else{
		while (num--) {
			*((char*)arr1+num) = *((char*)arr2+num);
		}
	}
	return ret;
}
typedef struct stu {
	char name[20];
	int age;
}stu;
int main() {
	/*stu arr2[] = {{"展现改善",12},{"历史",20}};
	stu arr1[3] = { 0 };*/
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1+5, arr1,20);
	return 0;
 }