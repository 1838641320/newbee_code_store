#pragma G++ optimize(“O2”)
//#pragma GCC optimize(“O2”)
#include <bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef pair<int,int> pii;
const int maxn=59;
__gnu_pbds::priority_queue<pii,greater<pii>> pq[maxn];
int n,m,par[maxn];
int findp(int x){return par[x]==x?x:par[x]=findp(par[x]);}
int boruvka(){
	int ans=0,fa,fb;
	bool update=1;
	for(;update;){
		update=0;
		for(int i=1;i<=n;i++){
			fb=fa=findp(i);
			for(;pq[fa].empty()==0;pq[fa].pop()){
				fb=findp(pq[fa].top().second);
				if(fa!=fb) break;
			}
			if(pq[fa].empty()) continue;
			ans+=pq[fa].top().first;
			update=1;
			par[fa]=fb;
			pq[fb].join(pq[fa]);
		}
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++) par[i]=i,pq[i].clear();
		rep(i,0,m){
			int f,t,c;scanf("%d%d%d",&f,&t,&c);
			pq[f].push({c,t});
			pq[t].push({c,f});
		}
		printf("%d\n",boruvka());
	}
}