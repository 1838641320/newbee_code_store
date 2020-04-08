#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int ar[200][200],p,mn,n;
void solve(int x,string ss) {
	for (int i = 0; i<p; ++i) {
		if (x&(1<<i)) continue;
		char c = 'a'+i,pre;
		string s;
		int t = (x|(1<<i));
		for (char j:ss) {
			if (j!=c) {
				s += j;
				if (s.size()>1&&ar[pre][j]==0) goto bre;
				pre = j;
			}
		}
		mn = min(mn,(int)s.size());
		solve(t,s);
		break;
	bre:;
	}
}
int main() {
	string s;
	cin>>n>>p>>s;
	mn = s.size();
	for (int i = 0; i<p; ++i) for (int j = 0; j<p; ++j) cin>>ar['a'+i]['a'+j];
	solve(0,s);
	cout<<mn<<endl;
}