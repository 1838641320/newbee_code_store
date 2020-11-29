#include<windows.h>
#include<stdio.h>
int main(){
	int i,gap;
	puts("please input times per second");
	scanf("%d",&i);
	puts("press LCONTROL and VK_F9 to start auto-clicking");
	puts("to stop press LCONTROL and VK_F10");
	gap=1000/i/2;
	while(1){
		if(GetAsyncKeyState(VK_LCONTROL)&&GetAsyncKeyState(VK_F9)){
			puts("start");
			while(1){
				if(GetAsyncKeyState(VK_LCONTROL)&&GetAsyncKeyState(VK_F10)) break;
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				Sleep(gap);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				Sleep(gap);
			}
			puts("end");
		}
	}
}