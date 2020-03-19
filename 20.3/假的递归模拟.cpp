#include<cstdio>
#include<stack>
#define simulate
using namespace std;
struct in {char a,b,c;int n;};
stack<in> lay;
stack<int> esp;
#ifdef simulate
void hanno(char a,char b,char c,int n) {
	lay.push({a,b,c,n});
	call:
	in now=lay.top();
	if (now.n==1) printf("%c  %c\n",now.a,now.c);
	else {
		lay.push({now.a,now.c,now.b,now.n-1});
		esp.push(1);
		goto call;
		back1:
		now = lay.top();
		printf("%c  %c\n",now.a,now.c);
		lay.push({now.b,now.a,now.c,now.n-1});
		esp.push(2);
		goto call;
		back2:;
	}
	lay.pop();
	if(lay.empty()) return;
	int ret = esp.top();esp.pop();
	if(ret==1) goto back1;
	else goto back2;
}
#endif
#ifndef simulate
void hanno(char a,char b,char c,int n) {
	if(n==1) printf("%c  %c\n",a,c);
	else {
		hanno(a,c,b,n-1);
		printf("%c  %c\n",a,c);
		hanno(b,a,c,n-1);
	}
}
#endif
int main() {
	int n;
	scanf("%d",&n);
	hanno('a','b','c',n);
}