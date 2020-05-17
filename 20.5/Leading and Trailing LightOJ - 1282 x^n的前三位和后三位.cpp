#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int T,res1,res2,x,n;
double y,no;
int qpow(int x,int n) {
	int c=1;
	for (x%=1000;n;n/=2,x=(x*x)%1000) if (n&1) c=(c*x)%1000;
	return c;
}
int main() {
	cin>>T;
	rep(i,1,T+1) {
		scanf("%d %d",&x,&n);
		y=modf((double)n*log10(x),&no);
		res1=pow(10,y)*100;
		res2=qpow(x,n);
		printf("Case %d: %d %03d\n",i,res1,res2);
	}
}