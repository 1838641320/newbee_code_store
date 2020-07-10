#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=209;
char used[maxn];
int n,m,link[maxn],color[maxn];
vector<int> g[maxn];
bool dfs(int x){
	for(int t:g[x]){
		if(used[t]) continue;used[t]=1;
		if(link[t]==-1||dfs(link[t]))
			return link[t]=x,1;
	}
	return 0;
}
bool col(int x,int c){
	color[x]=c;
	for(int t:g[x]){
		if(color[t]==c) return 0;
		if(color[t]==0&&col(t,-c)==0) return 0;
	}
	return 1;
}
int main(){
	int f,t;
	while(~scanf("%d%d",&n,&m)){
		mem(color,0);mem(link,-1);
		rep(i,0,n+2) g[i].clear();
		rep(i,0,m) {
			scanf("%d%d",&f,&t);
			g[f].push_back(t);
			g[t].push_back(f);
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(color[i]) continue;
			if(col(i,1)==0) { flag=0; break; }
		}
		if(flag==0) { puts("No");continue; }
		int ans=0;
		for(int i=1;i<=n;i++){
			if(color[i]==1){
				mem(used,0),ans+=dfs(i);
			}
		}
		printf("%d\n",ans);
	}
}