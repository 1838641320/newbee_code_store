#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5+9;
ll x,y,n;
ll dx[maxn] = {},dy[maxn] = {};
int main() {
	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2>>n;
	x = x2-x1,y = y2-y1;
	getchar();
	for (int i = 1;i<=n;i++) {
		char c = getchar();
		dx[i] = dx[i-1],dy[i] = dy[i-1];
		switch (c) {
		case 'R':dx[i]++;break;
		case 'L':dx[i]--;break;
		case 'U':dy[i]++;break;
		case 'D':dy[i]--;break;
		}
	}
#define two
#ifdef one
	ll lb = 0,ub = 1e18,px=dx[n],py=dy[n];
	while (ub>lb+1) {
		ll mid = (lb+ub)/2ll,c= mid/n,m= mid%n;
		if (mid>=abs(x-c*px-dx[m])+abs(y-c*py-dy[m]))
			ub=mid;
		else lb=mid;
	}
	cout<<(ub==1e18?-1:ub);
#endif
#ifdef two
	ll lb = 0,ub = 1e18,px = dx[n],py = dy[n],ans = -1;
	while (ub>=lb) {
		ll mid = (lb+ub)/2ll,c = mid/n,m = mid%n;
		if (mid>=abs(x-c*px-dx[m])+abs(y-c*py-dy[m]))
			ub = mid-1,ans = mid;
		else lb = mid+1;
	}
	cout<<ans;
#endif
}