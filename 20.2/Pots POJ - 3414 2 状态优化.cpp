#include<iostream>
#include<vector>
#define pb push_back
const int maxn = 1e2+8,dir[6][2] = {{2,0},{2,1},{0,2},{1,2},{0,1},{1,0}};
const char *a[] = {"FILL(1)\n","FILL(2)\n","DROP(1)\n","DROP(2)\n","POUR(1,2)\n","POUR(2,1)\n"};
using namespace std;
int C,dp[maxn][maxn] = {0},cup[3] = {0,0,1e9};
vector<pair<int,int> > route,place;
vector<int> ans;
void solve() {
	dp[0][0] = 1;
	place.pb({0,0});
	route.pb({-1,-1});
	int ti = -1,pi = -1,a,b;
	while (1) {
		ti++,pi++;
		if (ti==route.size()) return;
		pair<int,int> it = route[ti],ip = place[pi];
		if (ip.first==C||ip.second==C) break;
		int ai = ip.first,bi = ip.second;
		for (int i = 0;i<6;i++) {
			int f = dir[i][0],t = dir[i][1],c[3] = {ai,bi,1e8};
			int sum = c[f]+c[t],cap = cup[t];
			c[f] = sum>cap?sum-cap:0;
			c[t] = sum>cap?cap:sum;
			int a = c[0],b = c[1];
			if (dp[a][b]==0) {
				route.pb({ti,i});
				place.pb({a,b});
				dp[a][b] = 1;
			}
		}
	}
	for (;ti;ti = route[ti].first) 
		ans.pb(route[ti].second);
}
int main() {
	ios::sync_with_stdio(false);
	cin>>cup[0]>>cup[1]>>C;
	solve();
	if (ans.size()==0) { cout<<"impossible";return 0; }
	cout<<ans.size()<<'\n';
	for (int i = ans.size()-1;i>=0;i--) cout<<a[ans[i]];
}