#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using ll=long long;
using namespace std;
ll dp[64][2][2][2]={},x;
int bi[64]={},am[109]={},m;
ll calc(int lim,int s,int t){
	int res=0,hi=lim?x%128:127;
	for(int i=0;i<=hi;i++){
		int f=1;
		for(int j=0;j<m&&f;j++)
			if(i+j<128) f&=(__builtin_parity(i+j)^s)==am[j];
			else f&=(__builtin_parity(i+j)^s^t)==am[j];
		res+=f;
	}
	return res;
}
ll dfs(int pos,int lim,int s,int t){
	ll&res=dp[pos][lim][s][t];
	if(res!=-1) return res;
	if(pos<=6) return res=calc(lim,s,t);
	res=0;
	int up=lim?bi[pos]:1;
	for(int i=0;i<=up;i++) 
		res+=dfs(pos-1,lim&&i==up,s^i,i&(!t));
	return res;
}
ll solve(){
	mem(dp,-1);
	int len=0;
	for(ll xi=x;xi;xi>>=1) bi[len++]=xi&1;
	return dfs(len-1,1,0,0);
}
int main() {
	int ___;
	for(scanf("%d",&___);___--;){
		scanf("%d%lld",&m,&x);
		rep(i,0,m) scanf("%d",&am[i]);
		printf("%lld\n",solve());
	}
}