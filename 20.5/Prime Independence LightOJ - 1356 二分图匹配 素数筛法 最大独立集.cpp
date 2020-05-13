#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=5e5+9,maxm=4e4+9;
int T,n,ans,exist[maxn],a[maxm];
vector<int> prime;
bool pvis[maxn];
void shai(int n) {
	pvis[0]=pvis[1]=1;
	rep(i,2,n) if (pvis[i]==0) {
		prime.push_back(i);
		for (int j=i*i;j>0&&j<n;j+=i) pvis[j]=1;
	}
}
vector<int> G[maxm];
bool used[maxm],num[maxm];
int match[maxm];
int dfs(int x) {
	for (int i:G[x]) {
		if (used[i]) continue;used[i]=1;
		if (match[i]==-1||dfs(match[i]))
			return match[i]=x,1;
	}
	return 0;
}
inline void addedge(int i,int p) { G[i].push_back(p),G[p].push_back(i); }
void build_() {
	rep(i,0,n) G[i].clear();
	rep(i,0,n) {
		int t=a[i],cnt=0,tt=t,p;
		for (int j:prime) {
			if (j*j>tt) break;
			while (tt%j==0) cnt++,tt/=j;
		}
		if (tt>1) cnt++;cnt%=2;
		num[i]=cnt;
		for (int j=2;j*j<=t;j++) {
			if (t%j==0) {
				int div=t/j;
				if (pvis[j]==0&&((p=exist[div])!=-1))
					addedge(i,p);
				if (pvis[div]==0&&((p=exist[j])!=-1))
					addedge(i,p);
			}
		}
		if (pvis[t]==0&&((p=exist[1])!=-1))addedge(i,p);
	}
}
int main() {
	shai(maxn-4);
	cin>>T;
	for (int TT=1;TT<=T;TT++) {
		cin>>n;ans=0;
		mem(exist,-1);
		rep(i,0,n) scanf("%d",a+i);
		rep(i,0,n) exist[a[i]]=i;
		mem(num,0);
		build_();
		mem(match,-1);
		rep(i,0,n) if (num[i])
			memset(used,0,n+6),ans+=dfs(i);
		printf("Case %d: %d\n",TT,n-ans);
	}
}