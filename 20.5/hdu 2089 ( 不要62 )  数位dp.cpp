#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+9,logn=20;
ll n,m,dp[20][2]={},bi[20];
ll dfs(int pos,int sta,int limit) {
	if (pos==-1) return 1;
	if (!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
	ll up=limit?bi[pos]:9,res=0;
	for(int i=0;i<=up;i++) {
		if (i==4||sta&&i==2) continue;
		res+=dfs(pos-1,i==6,limit&&i==up);
	}
	if (!limit) dp[pos][sta]=res;
	return res;
}
ll solve(ll x) {
	int pos=0;
	while (x) bi[pos++]=x%10,x/=10;
	return dfs(pos-1,0,1);
}
int main() {
	mem(dp,-1);
	while (cin>>n>>m,n||m) 
		printf("%lld\n",solve(m)-solve(n-1));
}