#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
int judge(int x) {
	int res=0;
	while (x) x/=5,res+=x;
	return res;
}
void solve() {
	int q,ub=1e9,lb=0;
	scanf("%d",&q);
	while (ub-lb>1) {
		int mid=(ub+lb)/2;
		if (judge(mid)>=q) ub=mid;
		else lb=mid;
	}
	if (judge(ub)!=q) puts("impossible");
	else printf("%d\n",ub);
}
int main() {
	int t;cin>>t;
	rep(i,1,t+1) printf("Case %d: ",i),solve();
}