#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//#include <windows.h>
int N,guess;
void number_initialize (void);
int main(){
printf("有多少个人进行游戏？\n");
scanf("%d",&N);
if (N>8) {printf("最多8个人进行游戏，程序结束\n");return 0;}//游戏人数少于9
//----------------------------------------------------------------
int c[N],a[N][5][5],b[N][5][5],bingo[N][105];//初始化数组,bingo判断 
int i1=0,i2=0,i3=0,line_add=0,i;//初始化行、列、计算中间量。循环输入计数器
for (i1=0;i1<N;i1++) {bingo[i1][102]=0;}
srand(time(NULL));//初始化随机数 
//HANDLE hOut;
//hOut = GetStdHandle(STD_OUTPUT_HANDLE);//控制颜色 
//添加数值
for (i1=0;i1<N;i1++) 
	{line_add=1;
	for (i3=0;i3<5;i3++) 
		{for (i2=0;i2<5;i2++) 
		a[i1][i2][i3]=(rand()%16+line_add);
		line_add=line_add+16;}}
//复制，产生初始数组 
for (i1=0;i1<N;i1++)for (i2=0;i2<5;i2++) for (i3=0;i3<5;i3++) 
	{if (i2==0&&i3==0||i2==0&&i3==4||i2==4&&i3==0||i2==4&&i3==4||(i2<4&&i2>0)&&(i3<4&&i3>0)) 
		b[i1][i2][i3]=-1;
	else 
		b[i1][i2][i3]=a[i1][i2][i3];};
//----------------------------------------------------------------	
//输出初始数组,并每次输入并判断卡牌数字 
for (guess=0;guess<80;guess++) {
	system("cls");
	{for (i1=0;i1<N;i1++)
	{if(bingo[i1][102]==0)
	printf("第%d人的卡片:\t\t",i1+1);
	else
	{printf("第%d人的卡片:",i1+1);/*SetConsoleTextAttribute(hOut,64);*/printf("BINGO !");/*SetConsoleTextAttribute(hOut,7);*/printf("     ");}}
	printf("\n");
	for (i2=0;i2<5;i2++) 
		{for (i1=0;i1<N;i1++)
			{for (i3=0;i3<5;i3++) 
			if (b[i1][i2][i3]==-1)
				printf("■ ");
			else
				printf("%2d ",b[i1][i2][i3]);
			printf("\t\t");
			};
		printf("\n");}}
	for (i=0;i<N;i++) 
	{if(bingo[i][102]==0) break;
	else return 0;}//全部人bingo则结束 
//----------------------------------------------------------------
	printf("每人依次输入猜的数字\n\n");
	for (i=0;i<N;i++) {
		if(bingo[i][102]==0){
		printf("第%d个人猜的数字:",i+1);
		int q;
		for (q=0;q<guess;q++) printf("%2d ",bingo[i][q]);
			scanf("%d",&c[i]);}}
//-----------------------//寻找是否有相同 
	for (i=0;i<N;i++)
	{bingo[i][102]=1;
	for (i2=0;i2<5;i2++)
		for (i3=0;i3<5;i3++) 
			{bingo[i][guess]=c[i];
			if (a[i][i2][i3]==c[i]) b[i][i2][i3]=a[i][i2][i3];
			if (a[i][i2][i3]!=b[i][i2][i3]) bingo[i][102]=0;
			}
	}
}
//-------------------猜的次数用完---------------------------------------------
return 0;}
