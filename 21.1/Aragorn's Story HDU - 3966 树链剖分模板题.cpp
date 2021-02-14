#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=5e4+9;
int n,m,p,L,R,D,pos,u,v;
int tr[maxn*4]={};
#define lch in*2
#define rch in*2+1
#define mid (l+r>>1)
vector<int> g[maxn];
int dfn[maxn],idcount,top[maxn],deep[maxn];
int par[maxn],hc[maxn],szt[maxn],rdf[maxn];
int a[maxn];
void dfs(int x){
	szt[x]=1,hc[x]=0;
	for(int i:g[x]) if(i!=par[x]){
		par[i]=x,deep[i]=deep[x]+1;
		dfs(i),szt[x]+=szt[i];
		if(hc[x]==0||szt[i]>szt[hc[x]]) hc[x]=i;
	}
}
void ddfs(int x){
	dfn[x]=idcount++;
	rdf[dfn[x]]=x;
	if(hc[x]==0) return;
	top[hc[x]]=top[x],ddfs(hc[x]);
	for(int i:g[x]) if(i!=hc[x]&&i!=par[x])
		top[i]=i,ddfs(i);
}
void build(int in=1,int l=1,int r=n){
	if(l==r) return void(tr[in]=a[rdf[l]]);
	build(lch,l,mid),build(rch,mid+1,r);
	tr[in]=0;
}
void update(int in=1,int l=1,int r=n){
	if(l>R||r<L) return ;
	if(l>=L&&r<=R) {tr[in]+=D;return;}
	update(lch,l,mid),update(rch,mid+1,r);
}
int query(int in=1,int l=1,int r=n){
	if(l==r) return tr[in];
	tr[lch]+=tr[in],tr[rch]+=tr[in];
	tr[in]=0;
	return pos<=mid?query(lch,l,mid):query(rch,mid+1,r);
}
void change(int u,int v){
	while(top[u]!=top[v]){//deep[top[u]]>=deep[top[v]]
		if(deep[top[u]]<deep[top[v]]) swap(u,v);
		L=dfn[top[u]],R=dfn[u],update();
		u=par[top[u]];
	}//deep[u]>=deep[v]
	if(deep[u]<deep[v]) swap(u,v);
	L=dfn[v],R=dfn[u],update();
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&p)){
		for(int i=1;i<=n;i++) 
			scanf("%d",&a[i]),g[i].clear();
		while(m--){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		par[1]=1;
		deep[1]=1;dfs(1);
		top[1]=idcount=1;ddfs(1);
		build();
		while(p--){
			char c;scanf(" %c",&c);
			if(c=='Q') {
				scanf("%d",&pos);
				pos=dfn[pos];
				printf("%d\n",query());
			}
			else {
				scanf("%d%d%d",&u,&v,&D);
				if(c=='D') D=-D;
				change(u,v);
			}
		}
	}
}