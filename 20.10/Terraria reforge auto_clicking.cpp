// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define mem(a,b) memset(a,b,sizeof a)
// using ll=long long;
// template<class ty>void read(ty&a){
// 	a=0;int f=0,c=getchar();
// 	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
// 	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
// 	if(f) a=-a;
// }
// template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
#include<stdio.h>
#include<windows.h>
int *p,*tp;
int main(){
	// auto t=FindWindow(NULL,(LPCWSTR)"Terraria: Terraria: Terraria:");
	DWORD pid=0;
	// GetWindowThreadProcessId(t,&pid);
	puts("ProcessId:");
	scanf("%ld",&pid);
	auto hpro=OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	char rd[1024]={},wr[1024]={};
	// scanf("%x",&p);
	// ReadProcessMemory(hpro,(void*)p,rd,4,NULL);
	// printf("%d\n",*(int*)(rd));
	//------
	// scanf("%x",&p);
	// scanf("%d",wr);
	// WriteProcessMemory(hpro,(void*)p,wr,4,NULL);
	puts("item pointer:");
	scanf("%x",&p);
	//p+=2;
	int x,n;
	while(1){
		if(GetAsyncKeyState(VK_F9)){
			ReadProcessMemory(hpro,p,&tp,4,NULL);
			tp+=0x120/4;
			ReadProcessMemory(hpro,tp,&n,4,NULL);
			x=n;
			int cnt=0;
			while(x<=n&&++cnt<150){
				printf("%d ",x);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				Sleep(10);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				Sleep(10);
				ReadProcessMemory(hpro,tp,&x,4,NULL);
			}
			puts("");
		}
	}
}