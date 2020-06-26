#include"s.h"
#include<bits/stdc++.h>
#define mid (l+r)/2
#define lch in*2
#define rch in*2+1
using namespace std;
const int maxn=5e4+9;
int cnt=1,dfsn[maxn*2],sz=0,head[maxn];
struct { int to,nex; }G[maxn];
int l[maxn],r[maxn],tr[maxn*8];
int N,L,R,I,D;
void pushdown(int in,int l,int r){
	tr[lch]=tr[rch]=tr[in];
	tr[in]=-1;
}
void update(int in=1,int l=1,int r=N){
	if(l>R||r<L) return;
	if(L<=l&&R>=r) return void(tr[in]=D);
	if(~tr[in]) pushdown(in,l,r);
	update(lch,l,mid);update(rch,mid+1,r);
}
int query(int in=1,int l=1,int r=N){
	if(l>I||r<I) return -1;
	if(l==I&&r==I) return tr[in];
	if(~tr[in]) pushdown(in,l,r);
	return max(query(lch,l,mid),query(rch,mid+1,r));
}
void dfs(int n){
	l[n]=cnt++;
	for(int u=head[n];~u;u=G[u].nex)
		dfs(G[u].to);
	r[n]=cnt++;
}
void solve(){
	memset(tr,-1,sizeof tr);
	memset(head,-1,sizeof head);
	cnt=1;sz=0;
	int n;scanf("%d",&n);
	bool sub[maxn]={};
	for(int i=1;i<n;i++){
		int f,t;
		scanf("%d%d",&t,&f);
		sub[t]=1;
		G[sz]={t,head[f]};
		head[f]=sz++;
	}
	int dfst;
	for(dfst=1;dfst<=n;dfst++) 
		if(sub[dfst]==0) break;
	dfs(dfst);
	N=2*n;
	int m,v;scanf("%d",&m);
	while(m--){
		char cmd[3];scanf("%s%d",cmd,&v);
		if(*cmd=='C')
			I=l[v],printf("%d\n",query());
		else {
			scanf("%d",&D);
			L=l[v],R=r[v];
			update();
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;t--;)
		printf("Case #%d:\n",i++),solve();
}