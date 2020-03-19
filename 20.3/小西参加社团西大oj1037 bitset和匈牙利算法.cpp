#include<cstdio>
#include<iostream>
#include<algorithm>
#include<deque>
#include<bitset>
using namespace std;
int n,m,vice[105],a,b;
bitset<105> used;
deque<int> g[105];
int dfs(int x) {
	for (int i:g[x]) {
		if (!used.test(i)) {
			used.flip(i);
			if (vice[i]==0||dfs(vice[i])) {
				vice[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	cin>>n>>m;
	while(cin>>a>>b){
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1;i<=m;i++) {
		used.reset();
		dfs(i);
	}
	int ans=0;
	for(int i=0;i<104;i++) if(vice[i]) ans++;
	cout<<ans;
}