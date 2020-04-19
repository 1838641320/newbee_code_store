#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e3+9,maxm=2e2+9;
typedef pair<int,int> P;
int n,b1,b2,ps[maxn]={},ss[maxn]={},used[maxn]={};
priority_queue<P> p,s,d;
int main() {
	cin>>n>>b1>>b2;
	for (int i=1;i<=n;i++) { scanf("%d",ps+i);p.push({ps[i],i}); }
	for (int i=1;i<=n;i++) { scanf("%d",ss+i);s.push({ss[i],i}); }
	int ans=0;
	while (b1--) {
		ans+=p.top().first;
		int who=p.top().second;
		used[who]=1;
		d.push({ss[who]-ps[who],who});
		p.pop();
	}
	while (b2--) {
		while (!p.empty()&&used[p.top().second]) p.pop();
		while (!s.empty()&&used[s.top().second]) s.pop();
		int choice1=p.top().first+d.top().first,choice2=s.top().first;
		if (choice1>choice2) {
			int who1=p.top().second,who2=d.top().second;
			used[who1]=1,used[who2]=2;
			ans+=choice1;
			d.pop();
			d.push({ss[who1]-ps[who1],who1});
			p.pop();
		}
		else {
			used[s.top().second]=2;
			ans+=choice2;
			s.pop();
		}
	}
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++) if (used[i]==1) printf("%d ",i);
	puts("");
	for (int i=1;i<=n;i++) if (used[i]==2) printf("%d ",i);
}