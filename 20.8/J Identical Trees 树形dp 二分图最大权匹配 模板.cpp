#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=509;
vector<int> g1[maxn],g2[maxn];

namespace bitmach{
	int G[maxn][maxn],ex[maxn],ey[maxn],ly[maxn],n;
	void bfs(int sx){
		int slack[maxn],pre[maxn]={},x,y=0,nexy=0,d;
		char vis[maxn]={};
		ly[y]=sx;mem(slack,0x3f);
		while(ly[y]){
			x=ly[y],d=0x3f3f3f3f,vis[y]=1;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				int gap=ex[x]+ey[i]-G[x][i];
				if(slack[i]>gap)
					slack[i]=gap,pre[i]=y;
				if(d>slack[i])
					d=slack[i],nexy=i;
			}
			for(int i=0;i<=n;i++){
				if(vis[i]) ex[ly[i]]-=d,ey[i]+=d;
				else slack[i]-=d;
			}
			y=nexy;
		}
		while(y) ly[y]=ly[pre[y]],y=pre[y];
	}
	int KM(int n_){
		n=n_;
		mem(ly,0),mem(ex,0),mem(ey,0);
		for(int x=1;x<=n;x++) bfs(x);
		int ans=0;
		for(int y=1;y<=n;y++) if(ly[y])
			ans+=G[ly[y]][y];
		return ans;
	}
}
//https://ac.nowcoder.com/acm/contest/view-submission?submissionId=44652873
int dp[maxn][maxn]={};
int dp_(int u,int v){
	dp[u][v]=(u!=v);
	int usz=g1[u].size(),vsz=g2[v].size();
	if(usz!=vsz) 
		return dp[u][v]=1000;
	if(usz==0) 
		return dp[u][v];
	for(int i:g1[u]) for(int j:g2[v]) 
		dp_(i,j);
	for(int i=0;i<usz;i++) for(int j=0;j<vsz;j++)
		bitmach::G[i+1][j+1]=-dp[g1[u][i]][g2[v][j]];
	dp[u][v]-=bitmach::KM(usz);
	return dp[u][v];
}
int main(){
	int n;scanf("%d",&n);
	int root1,root2;
	for(int i=1,pa;i<=n;i++){
		scanf("%d",&pa);
		if(pa) g1[pa].push_back(i);
		else root1=i;
	}
	for(int i=1,pa;i<=n;i++){
		scanf("%d",&pa);
		if(pa) g2[pa].push_back(i);
		else root2=i;
	}
	printf("%d\n",dp_(root1,root2));
}