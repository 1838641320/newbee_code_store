#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
int t;
int main() {
	cin>>t;
	for(int kase=1;kase<=t;kase++){
		double t,i,n;
		int minus=0;
		cin>>t;if (t<0) minus=1,t=-t;
		for (i=32.0;i>1.0;i-=1.0) {
			if (minus) i-=1.0;
			n=floor(pow(t,1.0/i)+1e-9);
			double tt=pow(n,i);
			if (fabs(t-tt)<(double)1e-9) 
				break;
		}
		printf("Case %d: %.0lf\n",kase,i);
	}
}