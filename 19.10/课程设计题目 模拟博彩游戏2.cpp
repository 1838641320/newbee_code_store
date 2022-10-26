#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
int N,guess,finish=1,menu_choice;//定义全局变量 玩家人数，猜的次数，本局游戏是否结束，游戏菜单选择. 
char line_and_cols[90];//窗口大小变量 
void position(int x, int y)//在坐标(x,y)处输出字符串ch
{COORD cd;//定义输出位置坐标 
cd.X = x;//列 
cd.Y = y;//行 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
int menu(){//显示菜单 
	char input;
	sprintf(line_and_cols,"mode con cols=%d lines=30",200);
	system(line_and_cols);
	while (1){
		system("cls");
		//----------------设置窗口宽度--------------- 
		printf("开始游戏请按Y\n退出游戏请按N\n");
		scanf("%c",&input);
		if (input=='N') {system("cls");return 0;}
		if (input=='Y') {system("cls");break;}
		input='0';}
	return 1;}

int main()
{
while(menu())
{
printf("有多少个人进行游戏？\n");
scanf("%d",&N);
system("cls"); 
//--------------------------------------- 
if (N>8) {printf("最多8个人进行游戏，程序结束\n");return 0;}//游戏人数少于9
//----------------------------------------------------------------
int c[N],a[N][5][5],b[N][5][5],bingo[N][105];//初始化数组,bingo判断 
int i1=0,i2=0,i3=0,line_add=0,i;//初始化行、列、计算中间量。循环输入计数器
//初始化随机数 
for (i1=0;i1<N;i1++) bingo[i1][102]=0;
srand(99*time(NULL));
for (i=0;i<20;i++) rand();
//----------------------
HANDLE color;
color = GetStdHandle(STD_OUTPUT_HANDLE);//控制颜色 
//为数组添加数值
for (i1=0;i1<N;i1++) 
	{line_add=1;
	for (i3=0;i3<5;i3++) 
		{for (i2=0;i2<5;i2++) 
		a[i1][i2][i3]=(rand()%16+line_add);
		line_add=line_add+16;}}
//复制，产生初始数组 
for (i1=0;i1<N;i1++) for (i2=0;i2<5;i2++) for (i3=0;i3<5;i3++) 
	{if (i2==0&&i3==0||i2==0&&i3==4||i2==4&&i3==0||i2==4&&i3==4||(i2<4&&i2>0)&&(i3<4&&i3>0)) 
		b[i1][i2][i3]=-1;
	else 
		b[i1][i2][i3]=a[i1][i2][i3];};
//------------------输出初始数组------------------------------------	
	for (i1=0;i1<N;i1++) printf("第%d人的卡片:\t\t",i1+1);
	printf("\n");
	for (i2=0;i2<5;i2++) 
		{for (i1=0;i1<N;i1++)
			{for (i3=0;i3<5;i3++) 
			if (b[i1][i2][i3]==-1)
				printf("█ ");
			else
				printf("%2d ",b[i1][i2][i3]);
			printf("\t\t");
			};
		printf("\n");}
		printf("每人依次输入猜的数字\n");
//---------------游戏进行主体---------------------------------	
//每次输入并判断卡牌数字 
for (guess=0;guess<80;guess++) {
	{for (i1=0;i1<N;i1++)//每个人的bingo判断 
		{if(bingo[i1][102]!=0)
			{position(24*i1,7);
			printf("第%d人的卡片:",i1+1);
			SetConsoleTextAttribute(color,64);
			printf("BINGO !");
			SetConsoleTextAttribute(color,7);
			}}
	}
//---------------全部人bingo则结束---------------
	finish=1;
	for (i=0;i<N;i++) if (bingo[i][102]==0) finish=0;
	if (finish==1)
	{printf("%6000c",' ');
	break;}
//-------------------依次输入猜的数字----------------------------------
	for (i=0;i<N;i++) {
		if(bingo[i][102]==0){
		printf("\n第%d个人猜的数字:",i+1);
		int q;
		for (q=0;q<guess;q++) printf("%2d ",bingo[i][q]);
			scanf("%d",&c[i]);
			}}
//-----------------------//寻找是否有相同 
	for (i=0;i<N;i++)
	{bingo[i][102]=1;
	for (i2=0;i2<5;i2++)
		for (i3=0;i3<5;i3++) 
			{bingo[i][guess]=c[i];//保存猜的数字 
			if (a[i][i2][i3]==c[i]) {
				b[i][i2][i3]=a[i][i2][i3];
				position(i*24+i3*3,1+i2);printf("%2d ",b[i][i2][i3]);//翻卡牌 
				}
			if (a[i][i2][i3]!=b[i][i2][i3]) bingo[i][102]=0;//bingo结束判断 
			}
	}
	position(0,7);
	printf("%4000c",' ');
	position(0,7);//重置光标位置 
}
//-------------------猜的次数用完---------------------------------------------
position(7,16);
SetConsoleTextAttribute(color,164);
printf("当前游戏已结束,输入e以继续\n");
SetConsoleTextAttribute(color,7);
{char end='j';while(end!='e') scanf("%c",&end);}
}
return 99;}

