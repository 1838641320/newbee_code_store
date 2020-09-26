// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
using namespace std;
const ll mod=1e9+7;
const int maxn=1e2+9,base=1100;
ll dp[maxn][2*base][2][2],len,bi[maxn]={};
char s[maxn]={};
ll dfs(int pos,int bis,int la,int lb){
	if(pos==len) return bis>base;
	ll &DP=dp[pos][bis][la][lb];
	if(DP!=-1) return DP;
	DP=0;
	int up=lb?9:bi[pos];
	for(int i=0;i<=up;i++) {//B
		int upa=la?9:i;
		for(int j=0;j<=upa;j++)//A
			DP+=dfs(pos+1,bis+j-i,la|(j<upa),lb|(i<up));
		DP%=mod;
	}
	return DP;
}
int main() {
	mem(dp,-1);
	scanf("%s",s);
	len=strlen(s);
	rep(i,0,len) bi[i]=s[i]-'0';
	printf("%lld\n",dfs(0,base,0,0));
}