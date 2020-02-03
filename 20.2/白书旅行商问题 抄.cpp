#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
constexpr auto maxn=15;
int n,d[maxn][maxn],dp[1<<maxn][maxn];
int rec(int s,int v){
	if(dp[s][v]>=0) return dp[s][v];
	if(s==(1<<n)-1&&v==0) return dp[s][v]=0;
	int res=0x3f3f3f3f;
	for(int u=0;u<n;u++) if(!(s>>u&1))
		res=min(res,rec(s|1<<u,u)+d[v][u]);
	return dp[s][v]=res;
}
void s(){
	memset(dp,-1,sizeof(dp));
	printf("%d",rec(0,0));
}
void solve(){
	for(int s=0;s<1<<n;s++) memset(dp[s],0x3f,s+n);
	dp[(1<<n)-1][0]=0;
	for(int s=(1<<n)-2;s>=0;s--) for(int v=0;v<n;v++)
		for(int u=0;u<n;u++) if(!(s>>u&1))
			dp[s][v]=min(dp[s][v],dp[s|1<<u][u]+d[v][u]);
	printf("%d\n",dp[0][0]);
}
int main(){}