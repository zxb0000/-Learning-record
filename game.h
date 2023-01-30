#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define degree 10//地雷的数目
void meun();
void game();
void Initbord(char arr[ROWS][COLS], int rows,int cols,char set);
void Displaybord(char arr[ROWS][COLS],int row,int  col);
void Initmine(char arr[ROWS][COLS],int row,int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


