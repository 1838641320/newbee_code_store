//#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e6+9,m=1e6;
int ty[maxn],id[maxn],s[maxn],ans[maxn],n;
vector<int> g[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char in[12],*p=in+1;
		scanf("%s",in);
		ty[i]=in[0]=='s'?1:-1;
		id[i]=strtol(p,&p,10);
		g[id[i]].push_back(i);
	}
	for(int id=1;id<=m;id++){
		int sum=0,minv=0;
		for(int i:g[id]){
			sum+=ty[i];
			s[i]=sum;
			minv=min(minv,sum);
		}
		if(sum) continue;
		for(int i=0,sz=g[id].size();i<sz;i++){
			if(s[g[id][i]]==minv){
				if(i<sz-1){
					ans[g[id][i]+1]++,ans[g[id][i+1]+1]--;
				}
				else {
					ans[1]++;ans[g[id][i]+1]++;
					ans[g[id][0]+1]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
	int p=1,pv=ans[1];
	for(int i=1;i<=n;i++)
		if(pv<ans[i]) pv=ans[i],p=i;
	printf("%d %d\n",p,pv);
}