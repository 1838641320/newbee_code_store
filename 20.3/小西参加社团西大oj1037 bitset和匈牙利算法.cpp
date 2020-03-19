#include<bits/stdc++.h>
using namespace std;
int n,m,vice[105],a,b;
bitset<105> used;
deque<int> g[105];
int dfs(int x) {
	for (int i:g[x]) 
		if (!used.test(i)) {
			used.flip(i);
			if (vice[i]==0||dfs(vice[i])) return vice[i] = x;
		}
	return 0;
}
int main() {
	for(cin>>n>>m;cin>>a>>b;) g[a].push_back(b);
	for (int i = 1;i<=m;i++) used.reset(),dfs(i);
	cout<<count_if(vice,vice+104,[](int x){return x;});
}
