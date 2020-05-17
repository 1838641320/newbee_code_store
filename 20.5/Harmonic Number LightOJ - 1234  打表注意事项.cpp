#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e8+9;
double ans[1000009]={};
int T,n;
int main() {
	double ttt=0;
	for (int i=1;i<maxn-1;i++) {
		ttt+=1.0/(double)i;
		if (i%100==0) ans[i/100]=ttt;
	}
	scanf("%d",&T);
	rep(i,1,T+1) {
		scanf("%d",&n);
		double out=ans[n/100];
		rep(i,(n/100)*100,n) 
			out+=1.0/(i+1.0);
		printf("Case %d: %.10lf\n",i,out);
	}
}