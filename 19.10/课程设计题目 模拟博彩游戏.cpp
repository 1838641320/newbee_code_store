#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//#include <windows.h>
int N,guess;
void number_initialize (void);
int main(){
printf("�ж��ٸ��˽�����Ϸ��\n");
scanf("%d",&N);
if (N>8) {printf("���8���˽�����Ϸ���������\n");return 0;}//��Ϸ��������9
//----------------------------------------------------------------
int c[N],a[N][5][5],b[N][5][5],bingo[N][105];//��ʼ������,bingo�ж� 
int i1=0,i2=0,i3=0,line_add=0,i;//��ʼ���С��С������м�����ѭ�����������
for (i1=0;i1<N;i1++) {bingo[i1][102]=0;}
srand(time(NULL));//��ʼ������� 
//HANDLE hOut;
//hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ 
//�����ֵ
for (i1=0;i1<N;i1++) 
	{line_add=1;
	for (i3=0;i3<5;i3++) 
		{for (i2=0;i2<5;i2++) 
		a[i1][i2][i3]=(rand()%16+line_add);
		line_add=line_add+16;}}
//���ƣ�������ʼ���� 
for (i1=0;i1<N;i1++)for (i2=0;i2<5;i2++) for (i3=0;i3<5;i3++) 
	{if (i2==0&&i3==0||i2==0&&i3==4||i2==4&&i3==0||i2==4&&i3==4||(i2<4&&i2>0)&&(i3<4&&i3>0)) 
		b[i1][i2][i3]=-1;
	else 
		b[i1][i2][i3]=a[i1][i2][i3];};
//----------------------------------------------------------------	
//�����ʼ����,��ÿ�����벢�жϿ������� 
for (guess=0;guess<80;guess++) {
	system("cls");
	{for (i1=0;i1<N;i1++)
	{if(bingo[i1][102]==0)
	printf("��%d�˵Ŀ�Ƭ:\t\t",i1+1);
	else
	{printf("��%d�˵Ŀ�Ƭ:",i1+1);/*SetConsoleTextAttribute(hOut,64);*/printf("BINGO !");/*SetConsoleTextAttribute(hOut,7);*/printf("     ");}}
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
		printf("\n");}}
	for (i=0;i<N;i++) 
	{if(bingo[i][102]==0) break;
	else return 0;}//ȫ����bingo����� 
//----------------------------------------------------------------
	printf("ÿ����������µ�����\n\n");
	for (i=0;i<N;i++) {
		if(bingo[i][102]==0){
		printf("��%d���˲µ�����:",i+1);
		int q;
		for (q=0;q<guess;q++) printf("%2d ",bingo[i][q]);
			scanf("%d",&c[i]);}}
//-----------------------//Ѱ���Ƿ�����ͬ 
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
//-------------------�µĴ�������---------------------------------------------
return 0;}
