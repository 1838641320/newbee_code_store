#include"s.h"
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e6+9,maxp=1e4+9;
int text[maxn],pattern[maxp],Next[maxp],n,m;
void getNext(int *p,int *next) {
	int i=0,j=-1;
	next[0]=-1;
	while (i<m) {
		if (j==-1||p[i]==p[j])
			if (p[++j]==p[++i])
				next[i]=next[j];
			else next[i]=j;
		else j=next[j];
	}
}
int KMP(int *t,int *p,int *next) {
	getNext(p,next);
	int i=0,j=0;
	while (i<n&&j<m) {
		if (j==-1||t[i]==p[j])
			i++,j++;
		else j=next[j];

	}
	return j==m?i-m+1:-1;
}
int main() {
	int T;cin>>T;
	while (T--) {
		scanf("%d%d",&n,&m);
		rep(i,0,n) scanf("%d",&text[i]);
		rep(i,0,m) scanf("%d",&pattern[i]);
		printf("%d\n",KMP(text,pattern,Next));
	}
}