#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
ll l,r,dp[20][50][2520];
int bi[20];
char mp[2529]={};
ll dfs(int pos,int sta,int mod,int limit){
	if(pos==-1) {
		if(mod%sta) return 0;
		return 1;
	}
	if(!limit&&dp[pos][mp[sta]][mod]!=-1)
		return dp[pos][mp[sta]][mod];
	int up=limit?bi[pos]:9;
	ll res=0;
	for(int i=0;i<=up;i++){
		if(i==0) res+=dfs(pos-1,sta,(mod*10+i)%2520,limit&&i==up);
		else res+=dfs(pos-1,lcm(sta,i),(mod*10+i)%2520,limit&&i==up);
	}
	if(!limit) dp[pos][mp[sta]][mod]=res;
	return res;
}
ll solve(ll n){
	int pos=0;
	for(;n;n/=10) bi[pos++]=n%10;
	return dfs(pos-1,1,0,1);
}
int main(){
	vector<int> temp;
	for(int i=1;i<=8;i*=2) for(int j=1;j<=9;j*=3)
		temp.push_back(i*j),temp.push_back(i*j*5),temp.push_back(i*j*7),temp.push_back(i*j*35);
	sort(temp.begin(),temp.end());
	for(char i=0;i<48;i++) mp[temp[i]]=i;
	memset(dp,-1,sizeof dp);
	int __;scanf("%d",&__);
	while(__--){
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
}