#include<stdio.h>
#include<time.h>
#include <windows.h>
COORD cd;
void pos(){//在坐标(x,y)处输出字符串ch{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);}

void setColor(int color)//自定义的文字颜色函数
{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ;}
//延时函数开始------------------------- 
void delay (int x){
	clock_t start=clock(),finish=0;
	while((finish-start)<x)finish=clock();}
//延时函数结束------------------------- 

int main(){
	unsigned times=0;
	while(1) {
			delay(100);
			//times++;//延时 
			cd.X=(cd.X+1)%30;
			cd.Y=(cd.Y+1)%14;
			pos();
			printf("█");	
	}
}
