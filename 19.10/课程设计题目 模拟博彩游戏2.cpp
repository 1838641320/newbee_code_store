#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
int N,guess,finish=1,menu_choice;//����ȫ�ֱ��� ����������µĴ�����������Ϸ�Ƿ��������Ϸ�˵�ѡ��. 
char line_and_cols[90];//���ڴ�С���� 
void position(int x, int y)//������(x,y)������ַ���ch
{COORD cd;//�������λ������ 
cd.X = x;//�� 
cd.Y = y;//�� 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
int menu(){//��ʾ�˵� 
	char input;
	sprintf(line_and_cols,"mode con cols=%d lines=30",200);
	system(line_and_cols);
	while (1){
		system("cls");
		//----------------���ô��ڿ��--------------- 
		printf("��ʼ��Ϸ�밴Y\n�˳���Ϸ�밴N\n");
		scanf("%c",&input);
		if (input=='N') {system("cls");return 0;}
		if (input=='Y') {system("cls");break;}
		input='0';}
	return 1;}

int main()
{
while(menu())
{
printf("�ж��ٸ��˽�����Ϸ��\n");
scanf("%d",&N);
system("cls"); 
//--------------------------------------- 
if (N>8) {printf("���8���˽�����Ϸ���������\n");return 0;}//��Ϸ��������9
//----------------------------------------------------------------
int c[N],a[N][5][5],b[N][5][5],bingo[N][105];//��ʼ������,bingo�ж� 
int i1=0,i2=0,i3=0,line_add=0,i;//��ʼ���С��С������м�����ѭ�����������
//��ʼ������� 
for (i1=0;i1<N;i1++) bingo[i1][102]=0;
srand(99*time(NULL));
for (i=0;i<20;i++) rand();
//----------------------
HANDLE color;
color = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ 
//Ϊ���������ֵ
for (i1=0;i1<N;i1++) 
	{line_add=1;
	for (i3=0;i3<5;i3++) 
		{for (i2=0;i2<5;i2++) 
		a[i1][i2][i3]=(rand()%16+line_add);
		line_add=line_add+16;}}
//���ƣ�������ʼ���� 
for (i1=0;i1<N;i1++) for (i2=0;i2<5;i2++) for (i3=0;i3<5;i3++) 
	{if (i2==0&&i3==0||i2==0&&i3==4||i2==4&&i3==0||i2==4&&i3==4||(i2<4&&i2>0)&&(i3<4&&i3>0)) 
		b[i1][i2][i3]=-1;
	else 
		b[i1][i2][i3]=a[i1][i2][i3];};
//------------------�����ʼ����------------------------------------	
	for (i1=0;i1<N;i1++) printf("��%d�˵Ŀ�Ƭ:\t\t",i1+1);
	printf("\n");
	for (i2=0;i2<5;i2++) 
		{for (i1=0;i1<N;i1++)
			{for (i3=0;i3<5;i3++) 
			if (b[i1][i2][i3]==-1)
				printf("�� ");
			else
				printf("%2d ",b[i1][i2][i3]);
			printf("\t\t");
			};
		printf("\n");}
		printf("ÿ����������µ�����\n");
//---------------��Ϸ��������---------------------------------	
//ÿ�����벢�жϿ������� 
for (guess=0;guess<80;guess++) {
	{for (i1=0;i1<N;i1++)//ÿ���˵�bingo�ж� 
		{if(bingo[i1][102]!=0)
			{position(24*i1,7);
			printf("��%d�˵Ŀ�Ƭ:",i1+1);
			SetConsoleTextAttribute(color,64);
			printf("BINGO !");
			SetConsoleTextAttribute(color,7);
			}}
	}
//---------------ȫ����bingo�����---------------
	finish=1;
	for (i=0;i<N;i++) if (bingo[i][102]==0) finish=0;
	if (finish==1)
	{printf("%6000c",' ');
	break;}
//-------------------��������µ�����----------------------------------
	for (i=0;i<N;i++) {
		if(bingo[i][102]==0){
		printf("\n��%d���˲µ�����:",i+1);
		int q;
		for (q=0;q<guess;q++) printf("%2d ",bingo[i][q]);
			scanf("%d",&c[i]);
			}}
//-----------------------//Ѱ���Ƿ�����ͬ 
	for (i=0;i<N;i++)
	{bingo[i][102]=1;
	for (i2=0;i2<5;i2++)
		for (i3=0;i3<5;i3++) 
			{bingo[i][guess]=c[i];//����µ����� 
			if (a[i][i2][i3]==c[i]) {
				b[i][i2][i3]=a[i][i2][i3];
				position(i*24+i3*3,1+i2);printf("%2d ",b[i][i2][i3]);//������ 
				}
			if (a[i][i2][i3]!=b[i][i2][i3]) bingo[i][102]=0;//bingo�����ж� 
			}
	}
	position(0,7);
	printf("%4000c",' ');
	position(0,7);//���ù��λ�� 
}
//-------------------�µĴ�������---------------------------------------------
position(7,16);
SetConsoleTextAttribute(color,164);
printf("��ǰ��Ϸ�ѽ���,����e�Լ���\n");
SetConsoleTextAttribute(color,7);
{char end='j';while(end!='e') scanf("%c",&end);}
}
return 99;}

