#define ROW 3 
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
void meun();
void game();
void Initbord(char arr[ROW][COL], int row, int col);
void Display(char arr[ROW][COL], int row, int col);
void Playermove(char arr[ROW][COL],int row,int  col);
void Computermove(char arr[ROW][COL], int row, int col);
char Iswin(char arr[ROW][COL],int  row,int col);

