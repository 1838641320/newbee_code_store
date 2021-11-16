#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+9;
vector<int> g[maxn];
int szt[maxn],son[maxn];
bool vis[maxn];//has been root,act as boundary
int szn,root;
bitset<100009> dp[maxn],ans;
int a[maxn];
void getroot(int x,int pa){
	szt[x]=1;son[x]=0;
	for(int v:g[x])if(v!=pa&&!vis[v]){
		getroot(v,x);
		szt[x]+=szt[v];
		son[x]=max(son[x],szt[v]);//max subtree size
	}
	son[x]=max(son[x],szn-szt[x]);
	if(son[root]>son[x]) root=x;
}
void dfs(int x,int pa){//the main 'conquer' part
	for(int v:g[x])if(v!=pa&&!vis[v]){
		dp[v]=dp[x]<<a[v];
		dfs(v,x);
		dp[x]|=dp[v];
	}
}
void divide(int x){//now x is the new root
	vis[x]=1;
	dp[x].reset();
	dp[x].set(a[x]);
	dfs(x,x);
	ans|=dp[x];
	for(int v:g[x])if(!vis[v]){
		son[root=0]=szn=szt[v];//looks odd but amazing detail
		getroot(v,v);
		divide(root);
	}
}
int main(){
	int t=1,n,m;
	for(scanf("%d",&t);t--;puts("")) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) 
			g[i].clear(),dp[i].reset(),vis[i]=0;
		ans.reset();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			g[v].push_back(u);
			g[u].push_back(v);
		}
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		son[root=0]=szn=n;
		getroot(1,1);
		divide(root);
		for(int i=1;i<=m;i++) 
			printf("%d",ans.test(i));
	}
}