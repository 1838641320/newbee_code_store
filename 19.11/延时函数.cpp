#include<stdio.h>
#include<time.h>
#include <windows.h>
COORD cd;
void pos(){//������(x,y)������ַ���ch{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);}

void setColor(int color)//�Զ����������ɫ����
{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ;}
//��ʱ������ʼ------------------------- 
void delay (int x){
	clock_t start=clock(),finish=0;
	while((finish-start)<x)finish=clock();}
//��ʱ��������------------------------- 

int main(){
	unsigned times=0;
	while(1) {
			delay(100);
			//times++;//��ʱ 
			cd.X=(cd.X+1)%30;
			cd.Y=(cd.Y+1)%14;
			pos();
			printf("��");	
	}
}
