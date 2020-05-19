#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=50000+9,maxl=1e6+9;
typedef long long ll;
vector<int> prime;
void shai() {
	bool pvis[maxn]={};int end=maxn-4;
	rep(i,2,end) {
		if (!pvis[i]) prime.push_back(i);
		for (int j:prime) {
			if (j*i>=end) break;
			pvis[j*i]=1;
			if (i%j==0) break;
		}
	}
}
bool vis[maxl]={};
int solve() {
	ll a,b,res=0;cin>>a>>b;
	memset(vis,0,b-a+3);
	for (ll p:prime) {
		for (ll i=max(2ll,(a+p-1)/p)*p;i<=b;i+=p)
			vis[i-a]=1;
	}
	for (int i=0,ed=b-a;i<=ed;i++) res+=vis[i]==0;
	if (a==1) res--;
	return res;
}
int main() {
	shai();
	int t;cin>>t;
	rep(i,1,t+1) printf("Case %d: %d\n",i,solve());
}