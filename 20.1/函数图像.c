#include<stdio.h>
#include<windows.h>
#include<math.h>
static void SetPos(int x, int y){
	COORD point = { x, y };
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(HOutput, point);
}
void print(int x,int y){
	SetPos(2*x,y);
	putchar('@');
}
void print2(int x,int y){
	SetPos(2*x,y);
	putchar('*');
}
short function(double X,double Y){
	double scale=0.1;
	double precise=0.06
	;
	double x=X*scale,y=Y*scale//-----------
	;
	double re=log(y)
	;
	double dim=x*x
	;
	return fabs(re-dim)<precise?1:0;
}
int main(){
	//getchar();
	system("mode con cols=400 lines=400");
	for(double i=-100;i<100;puts(""),i+=1) for(int j=-100;j<100;j+=1)
		if(function(i,j)) print(100.0+i,100.0-j);
	for(int i=-100;i<100;i++) print2(100+i,100);
	for(int i=-100;i<100;i++) print2(100,100+i);
	SetPos(500,0);
	getchar();
}
