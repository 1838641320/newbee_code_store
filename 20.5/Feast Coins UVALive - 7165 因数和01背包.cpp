#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=5e3+9;
ll dp[maxn];
int S,N;
struct Coin{ int v,c; } coin[59];
ll ways(int cnt){
	memset(dp,0,sizeof dp);
	dp[0]=1;
	rep(j,0,N){
		if (coin[j].c<cnt) break;
		int iv=cnt*coin[j].v;
		for (int k=S-iv;k>=0;k--)
			dp[k+iv]+=dp[k];
	}
	return dp[S];
}
void solve(int kase){
	scanf("%d%d",&S,&N);
	rep(i,0,N){
		scanf("%d%d",&coin[i].v,&coin[i].c);
	}
	sort(coin,coin+N,[](Coin &a,Coin &b){return a.c>b.c;});
	ll ans=0;
	for (int i=1;i*i<=S;i++)
		if (S%i==0) {
			ans+=ways(i);
			if (i*i!=S) ans+=ways(S/i);
		}
	printf("Case %d: %lld\n",kase,ans);
}
int main(){
	int t;cin>>t;
	rep(i,1,t+1) solve(i);
}