#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
POINT p;
int main(){
	while(1){
		GetCursorPos(&p);
		printf("%d %d\n",p.x,p.y);
		if(p.x<100&&p.y<100) break;
		Sleep(100);
	}
	rep(i,0,9) {
		Sleep(100);
		SetCursorPos(623,411);
	}
}