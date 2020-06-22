#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a,_=b;i<_;i++)
using namespace std;
typedef long long ll;
ll l,r,dp[20][1024][10];
int bi[20],k;
int trans(int sta,int n){
	int p=n;
	while((sta&(1<<p))==0&&p<=9) p++;
	sta=sta&~(1<<p)|(1<<n);
	return sta;
}
int getbits(int x){
	int sum=0;
	while(x) sum+=x&1,x/=2;
	return sum;
}
ll dfs(int pos,int sta,int limit){
	if(pos==-1) {
		if(k==1&&sta==0) return 1;
		return getbits(sta)==k;
	}
	if(!limit&&dp[pos][sta][k]!=-1) 
		return dp[pos][sta][k];
	int up=limit?bi[pos]:9;
	ll res=0;
	for(int i=0;i<=up;i++){
		if(sta==0&&i==0) res+=dfs(pos-1,0,limit&&i==up);
		else res+=dfs(pos-1,trans(sta,i),limit&&i==up);
	}
	if(!limit) 
		dp[pos][sta][k]=res;
	return res;
}
ll solve(ll x){
	int len=0;
	for(;x;x/=10) bi[len++]=x%10;
	return dfs(len-1,0,1);
}
int main(){
	memset(dp,-1,sizeof dp);
	int __;scanf("%d",&__);
	for(int i=1;i<=__;i++){
		scanf("%lld %lld %d",&l,&r,&k);
		printf("Case #%d: %lld\n",i,solve(r)-solve(l-1ll));
	}
}