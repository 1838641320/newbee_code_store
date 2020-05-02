#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
ll n,m,a[maxn]={},lb,ub,mid;
int judge(int days) {
	ll total=0;
	for (int i=0;a[i]-i/days>0;i++) total+=a[i]-i/days;
	return total>=m;
}
int main() {
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	for (lb=0,ub=n+1;ub-lb>1;) {
		mid=(lb+ub)/2;
		if (judge(mid)) ub=mid;
		else lb=mid;
	}
	cout<<(ub>n?-1:ub);
}