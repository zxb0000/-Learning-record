#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main() {
//	FILE* fp = fopen("text.txt", "r");
//	if (fp == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fputc('s', fp);//写入时字符应使用's'单引号
//	fputc('s', fp);
//	fputc('a', fp);
//	fputc('w', fp);
//	printf("%c",fgetc(fp));//读取字符
//	printf("%c",fgetc(fp));
//	printf("%c",fgetc(fp));
//	printf("%c",fgetc(fp));
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}
//int main() {
//	char buf[1024] = { 0 };
//	FILE* fp = fopen("text.txt", "w");
//	if (fp == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//fgets(buf, 1024, fp);
//	//printf("%s", buf);
//	//fgets(buf, 1024, fp);
//	//printf("%s", buf);
//	//fgets(buf, 1024, fp);
//	//puts(buf);//puts打印完成后会进行换行
//	//fclose(fp);
//	fputs("hello\n", fp);//不会换行，需要自己加
//	fputs("word", fp);
//	fp = NULL;
//	return 0;
//}
int main() {
	char buf[1024] = { 0 };
	struct S {
		char a[20];
		int b;
		float f;
	};
	//fgets(buf, 1024, stdin);//在输入流获取信息，存放在buf，个数为1024
	//fputs(buf, stdout);//输出流，等价于下面gets和puts
	//gets(buf);
	//puts(buf);
	struct S S = {"dd",20,3.14f};
	struct S temp = { 0 };
	FILE*fp=fopen("text.txt", "rb");
	if (fp == NULL) {
		return 0;
	}
	//格式化输出数据
	//fprintf(fp, "%s %d %f", S.a, S.b, S.f);//fp输出的流 （可以是文件流或者输出流）  写入的格式   内容来源
	//格式化输入
	//fscanf(fp, "%s %d %f", &S.a, &S.b, &S.f);
	fwrite(&S,sizeof(struct S),1, fp);//Writes data to a stream.
	fread(&temp,sizeof(struct S),1,fp);//Reads data from a stream
	printf("%s %d %f", temp.a, temp.b, temp.f);
	fclose(fp);
	fp == NULL;
	return 0;
}