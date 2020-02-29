#include<iostream>
#include<vector>
#define pb push_back
const int maxn = 1e2+8;
const char *a[] = {"FILL(1)\n","FILL(2)\n","DROP(1)\n","DROP(2)\n","POUR(1,2)\n","POUR(2,1)\n"};
using namespace std;
int A,B,C,dp[maxn][maxn] = {0};
vector<pair<int,int> > route,place;
vector<int> ans;
void solve() {
	dp[0][0] = 1;
	place.pb({0,0});
	route.pb({-1,-1});
	int ti = -1,pi = -1,a,b;
	while (1) {
		ti++,pi++;
		if (ti==route.size()||pi==place.size()) return;
		pair<int,int> it = route[ti],ip = place[pi];
		if (ip.first==C||ip.second==C) break;
		int ai = ip.first,bi = ip.second;
		if (dp[A][bi]==0) {//FILL(1)
			route.pb({ti,0});
			place.pb({A,bi});
			dp[A][bi] = 1;
		}
		if (dp[ai][B]==0) {//FILL(2)
			route.pb({ti,1});
			place.pb({ai,B});
			dp[ai][B] = 1;
		}
		if (dp[0][bi]==0) {//DROP(1)
			route.pb({ti,2});
			place.pb({0,bi});
			dp[0][bi] = 1;
		}
		if (dp[ai][0]==0) {//DROP(2)
			route.pb({ti,3});
			place.pb({ai,0});
			dp[ai][0] = 1;
		}
		if (ai!=0&&bi!=B) {//POUR(1,2)
			a = bi+ai-B>0?bi+ai-B:0;
			b = a?B:ai+bi;
			if (dp[a][b]==0) {
				route.pb({ti,4});
				place.pb({a,b});
				dp[a][b] = 1;
			}
		}
		if (bi!=0&&ai!=A) {//POUR(2,1)
			b = bi+ai-A>0?bi+ai-A:0;
			a = b?A:ai+bi;
			if (dp[a][b]==0) {
				route.pb({ti,5});
				place.pb({a,b});
				dp[a][b] = 1;
			}
		}
	}
	while (ti) {
		ans.pb(route[ti].second);
		ti = route[ti].first;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>A>>B>>C;
	solve();
	if (ans.size()==0) { cout<<"impossible";return 0; }
	cout<<ans.size()<<'\n';
	for (int i = ans.size()-1;i>=0;i--) cout<<a[ans[i]];
}