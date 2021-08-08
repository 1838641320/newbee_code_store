#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define per(i,a,b) for(int i=a;i>(int)b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef __uint128_t ull;
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c&15);
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
//-------------------------------------------
#include<queue>
const int maxn=1e5+9;
#define lch in*2
#define rch in*2+1
#define mid ((l+r)>>1)
vector<int> g[maxn];
int dfn[maxn],idc,top[maxn],deep[maxn];
int par[maxn],hc[maxn],szt[maxn],rdf[maxn];
void dfs(int x){
	szt[x]=1,hc[x]=0;
	for(int i:g[x]) if(i!=par[x]){
		par[i]=x,deep[i]=deep[x]+1;
		dfs(i),szt[x]+=szt[i];
		if(hc[x]==0||szt[i]>szt[hc[x]]) hc[x]=i;
	}
}
void ddfs(int x){
	dfn[x]=idc++;
	rdf[dfn[x]]=x;
	if(hc[x]==0) return;
	top[hc[x]]=top[x],ddfs(hc[x]);
	for(int i:g[x]) if(i!=hc[x]&&i!=par[x])
		top[i]=i,ddfs(i);
}
struct node{ll x2,x,i;} tr[maxn*4];
int P,n;
node query(int in=1,int l=1,int r=n){
	if(l==r) return tr[in];
	node ret=tr[in],els;
	if(P<=mid) els=query(lch,l,mid);
	else els=query(rch,mid+1,r);
	ret.x2+=els.x2,ret.x+=els.x,ret.i+=els.i;
	return ret;
}
int L,R;
void update(const node&up,int in=1,int l=1,int r=n){
	if(l>R||r<L) return;
	if(l>=L&&r<=R){
		tr[in].x2+=up.x2;
		tr[in].x+=up.x;
		tr[in].i+=up.i;
		return;
	}
	update(up,lch,l,mid);
	update(up,rch,mid+1,r);
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if(deep[top[a]]>deep[top[b]])
			a=par[top[a]];
		else b=par[top[b]];
	}
	return deep[a]>deep[b]?b:a;
}
void change(int a,int b){
	node upd={1,0,0};
	ll le=1,ri=deep[a]+deep[b]-2*deep[lca(a,b)]+1;
	while(top[a]!=top[b]){
		if(deep[top[a]]>deep[top[b]]){
			L=dfn[top[a]],R=dfn[a];
			upd.x=-2*(L-le),
			upd.i=(L-le)*(L-le);
			update(upd);a=par[top[a]];
			le+=R-L+1;
		}
		else {
			L=dfn[top[b]],R=dfn[b];
			upd.x=-2*(L+ri),
			upd.i=(L+ri)*(L+ri),
			update(upd);b=par[top[b]];
			ri-=R-L+1;
		}
	}
	if(deep[a]<deep[b]){
		L=dfn[a],R=dfn[b];
		upd.x=-2*(L-le);
		upd.i=(L-le)*(L-le);
		update(upd);
	}
	else{
		L=dfn[b],R=dfn[a];
		upd.x=-2*(L+ri);
		upd.i=(L+ri)*(L+ri);
		update(upd);
	}
}
void solve(){
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u,v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	deep[1]=1,dfs(1);
	idc=1,top[1]=1,ddfs(1);
	int q,op,a,b;
	read(q);
	for(int i=1;i<=q;i++){
		read(op,a);
		if(op==2){
			P=dfn[a];
			auto res=query();
			ll res1=res.x2*P*P+res.x*P+res.i;
			printf("%lld\n",res1);
		}
		else read(b),change(a,b);
	}
}
int main(){
	// int t;read(t);
	// while(t--) 
		solve();
}