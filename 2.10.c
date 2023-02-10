#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() {//水仙花数
//	int i;
//	for (i = 1; i <= 100000; i++) {
//		int sum = 0;
//		int n = 1;
//		int temp = i;
//		while (temp/10){//计算位数
//			temp /= 10;
//			n++;
//		}
//		temp = i;
//		while (temp) {//求值
//			sum +=pow((temp%10),n);
//			temp /= 10;
//		}
//		if (sum == i) printf("%d ", i);
//	}
//	return 0;
//}
//void revers(char* arr) {//字符串逆序
//    int len = strlen(arr);
//    char* lift = arr;
//    char* right = arr + len - 1;
//    char temp;
//    while (lift < right) {
//        temp = *right;
//        *right = *lift;
//        *lift = temp;
//        lift++;
//        right--;
//    }
//}
//int main() {
//    char arr[256] = { 0 };
//    //scanf("%s", arr);
//    gets(arr);//读取一行，不关注有没有空格
//
//    revers(arr);
//    printf("逆序后%s ", arr);
//    return 0;
//}
//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
//
//int main() {
//	int i = 0;
//	int line;
//	printf("请输入要打印的上半部分的行数：");
//	scanf("%d", &line);
//	for (i = 0; i < line; i++) {//打印上半部分
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++) {
//			printf(" ");
//		}
//		for (j = 0; j <2*i+1;j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line-1; i++) {//打印下半部分
//		int j = 0;
//		for (j = 0; j <=i; j++) {
//			printf(" ");
//		}
//		for (j = 0; j < 2*(line-1-i)-1; j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//void move(int* arr,int sz) {//奇数放在偶数的前面
//	int lift = 0;
//	int right = sz-1;
//	while (lift<right) {
//		while (lift < right&&arr[lift] % 2 == 1) {
//			lift++;
//		}
//		while (lift < right && arr[right] % 2 == 0) {
//			right--;
//		}
//		if (lift < right) {
//			int temp = arr[right];
//			arr[right] = arr[lift];
//			arr[lift] = temp;
//		}
//	}
//}
//int main() {
//	int arr[] = {1,5,9,3};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	return 0;
//}
//void revers(char* arr, char* arr2) {//翻转arr和arr2之间的字符
//	assert(arr!=NULL);
//	assert(arr2 != NULL);
//	while (arr < arr2) {
//		char temp = *arr;
//		*arr = *arr2;
//		*arr2 = temp;
//		arr++;
//		arr2--;
//	}
//	
//}
//int is_lift_revers(char* arr1, char* arr2) {//判断arr2是不是arr1左旋生成的
//	//1.在arr1后面追加arr1
//	//strcat(str1，str2)会将dest字符串最后的'\0'覆盖掉，用于两个不同的字符串追加
//	//strncat(str1，str2，n)字符追加完成后，再追加'\0'。用于自身的追加n为追加的个数
//	//strstr(str1，str2)判断str2字符串是否是str1的字串，不是返回NULL指针，是的话返回arr2在arr1中的首字符地址;
//	int len = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len != len2) {
//		return 0;
//	}
//	strncat(arr1, arr1, len);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	else 
//		return 1;
//	
//	
//}
//void lift_revers(char *arr,int n) {//字符串左边n个数翻转到右边
//	
//	revers(arr, arr + n -1);
//	int len = strlen(arr);
//	assert(arr!=NULL);
//	assert(n <= len);
//	revers(arr + n, arr + len - 1);
//	revers(arr, arr + len - 1);
//}
//int main() {
//	char arr[30] = "asdzx";
//	char arr2[] = "dzxas";
//	if (is_lift_revers(arr, arr2))
//		printf("YEs\n");
//	else
//		printf("no\n");
//	//lift_revers(arr, 1);
//	printf("%s ", arr);
//	return 0;
//}
//在杨氏矩阵中查找要找的数
int find_n(int arr[3][3], int* row, int* col, int n) {//返回一找到 ，0没找到
	int x = 0;
	int y = *col - 1;
	while (x < *row && y >= 0) {
		if (arr[x][y] > n) {
			y--;
		}
		if (arr[x][y] < n) {
			x++;
		}
		if (arr[x][y] == n) {
			*row = x;
			*col = y;
			return 1;
		}
	}
	return 0;
}
int main() {
	int arr[3][3] = { {1,2,3},{ 2,3,4},{5,6,7} };
	int x = 3;
	int y = 3;
	int ret = find_n(arr, &x, &y, 5);
	if (ret) {
		printf("找到了！\n");
		printf("下标为：%d %d\n", x, y);
	}
	else
		printf("没找到！\n");
	return 0;
}