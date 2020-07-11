#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=5e5+9;
vector<pair<int,int>> ans;
queue<int> que;
vector<int> g[maxn];
int d[maxn],n,m,f,t;
bool vis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d",&f,&t);
		g[f].push_back(t);g[t].push_back(f);
		d[f]++,d[t]++;
	}
	mem(vis,0);
	for(int i=1;i<=n;i++) if(d[i]==1) que.push(i);
	while(!que.empty()){//delete "leaves"
		int u=que.front();que.pop();
		for(int v:g[u])
			if(vis[v]==0&&--d[v]==1)
				vis[v]=1,que.push(v);
	}
	mem(vis,0);
	for(int i=1;i<=n;i++) if(d[i]>1) que.push(i);
	while(!que.empty()){//find loops
		int u=que.front();que.pop();
		for(int v:g[u])
			if(vis[v]==0)
				vis[v]=1,que.push(v);
	}
	for(int i=1;i<=n;i++){
		for(int v:g[i]){
			if(!vis[i]&&g[i].size()==1)
				ans.push_back({i,v});
			if(vis[i]&&d[i]>1&&d[v]==1)
				ans.push_back({i,v});
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto i:ans) printf("%d %d\n",i.first,i.second);
}