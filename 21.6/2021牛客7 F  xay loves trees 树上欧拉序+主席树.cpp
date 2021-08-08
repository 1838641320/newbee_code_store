#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=(int)b;i++)
using namespace std;
const int maxn=3e5+9;
vector<int> g[maxn],g2[maxn];
int li[maxn],ri[maxn],rt[maxn];
int n,ans,sz,tot;
struct node{int ma,lc,rc,lz;}tr[maxn*50];
void pushdown(int in){
	if(tr[in].lz==0) return;
	int lc=tr[in].lc=++tot,rc=tr[in].rc=++tot;
	tr[lc].ma=tr[rc].ma=tr[lc].lz=tr[rc].lz=tr[in].lz;
	tr[in].lz=0;
}
int query(int rt,int L,int R,int l=1,int r=n){
	if(!rt) return 0;
	if(l>=L&&r<=R) return tr[rt].ma;
	pushdown(rt);
	int ret=0,mid=(l+r)/2;
	if(L<=mid) ret=max(ret,query(tr[rt].lc,L,R,l,mid));
	if(R>mid) ret=max(ret,query(tr[rt].rc,L,R,mid+1,r));
	return ret;
}
void update(int&rt,int L,int R,int v,int l=1,int r=n){
	tr[++tot]=tr[rt];rt=tot;
	tr[rt].ma=v;
	if(l>=L&&r<=R) {
		tr[tot].lz=tr[tot].ma=v;
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid) update(tr[rt].lc,L,R,v,l,mid);
	if(R>mid) update(tr[rt].rc,L,R,v,mid+1,r);
}
void dfs1(int x,int p,int deep,int lasd){
	lasd=max(lasd,query(rt[p],li[x],ri[x]));
	ans=max(ans,deep-lasd);
	rt[x]=rt[p];
	update(rt[x],li[x],ri[x],deep);
	for(int i:g[x]) if(i!=p) dfs1(i,x,deep+1,lasd);
}
void dfs2(int x,int p){
	li[x]=++sz;
	for(int i:g2[x]) if(i!=p) dfs2(i,x);
	ri[x]=sz;
}
void solve(){
	scanf("%d",&n);
	rep(i,0,tot) tr[i]=tr[0];
	rep(i,0,n) g[i].clear(),g2[i].clear();
	int u=0,v=0;
	rep(i,2,n){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i,2,n){
		scanf("%d%d",&u,&v);
		g2[u].push_back(v);
		g2[v].push_back(u);
	}
	sz=0,tot=0;
	dfs2(1,0);
	ans=1;
	dfs1(1,0,1,0);
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	rep(i,1,t)
		solve();
}