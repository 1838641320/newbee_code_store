#include<bits/stdc++.h>
using namespace std;
int n,m,match[105],a,b,ans=0;
char used[105];
vector<int> g[105];
int dfs(int x) {
	for (int i:g[x]) {
		if (used[i]) continue;
		used[i]=1;
		if (match[i]==0||dfs(match[i])) return match[i]=x,1;
    }
	return 0;
}
int main() {
	for(cin>>n>>m;cin>>a>>b;) g[a].push_back(b);
	for (int i=1;i<=m;i++) memset(used,0,sizeof used),ans+=dfs(i);
	cout<<ans;
}