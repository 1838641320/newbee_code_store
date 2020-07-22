#include"s.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+9;
typedef pair<int,int> pii;
void solve(){
	pair<int,int> a[maxn]={};
	long double b[maxn]={};
	set<pii> se;
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n,greater<pii>());
	for(int i=1;i<n;i++) if(a[i]==a[i-1])
		se.insert(a[i]);
	n=unique(a,a+n)-a;
	vector<pii> ra={a[0]};
	for(int i=1;i<n;i++) if(a[i].second>ra.back().second)
		ra.push_back(a[i]);
	vector<int> dq={0};
	b[0]=0.0l;
	for(int i=1;i<ra.size();i++){
		while(dq.empty()==0){//用单调栈维护x轴坐标递增的点
			int p=dq.back();
			b[i]=(1.0l*ra[p].first-ra[i].first)/(1.0l*ra[i].second-ra[p].second);
			if(b[i]>b[p]) break;
			dq.pop_back();
		}
		dq.push_back(i);
	}
	printf("%d\n",count_if(dq.begin(),dq.end(),[&](int a){return se.count(ra[a])==0;}));
}
int main(){
	int t;cin>>t;
	while(t--) solve();
}