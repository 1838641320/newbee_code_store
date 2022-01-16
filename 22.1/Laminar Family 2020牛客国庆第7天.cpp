#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int n,q;
vector<int> g[maxn];
namespace seg{//线段树
	#define lch in*2
	#define rch in*2+1
	#define mid ((l+r)/2)
	struct pii{int mi,ma;}nd[maxn*4];//区间最值查询
	int lz[maxn*4];
	pii pushup(pii a,pii b){
		a.mi=min(a.mi,b.mi);
		a.ma=max(a.ma,b.ma);
		return a;
	}
	void pushdown(int in){
		if(!lz[in]) return;
		nd[lch]=nd[rch]={lz[in],lz[in]};
		lz[lch]=lz[rch]=lz[in];
		lz[in]=0;
	}//记得酌情考虑是否需要build函数初始化
	int L,R,D;
	void update(int in=1,int l=1,int r=n){//区间设置数
		if(l>=L&&r<=R) {
			nd[in]={D,D};lz[in]=D;return;
		}
		pushdown(in);
		if(L<=mid) update(lch,l,mid);
		if(R>mid) update(rch,mid+1,r);
		nd[in]=pushup(nd[lch],nd[rch]);
	}//询问是区间覆盖模型，不用考虑零元
	pii query1(int in=1,int l=1,int r=n){
		if(l>=L&&r<=R) return nd[in];
		pushdown(in);
		if(R<=mid) return query1(lch,l,mid);
		if(L>mid) return query1(rch,mid+1,r);
		return pushup(query1(lch,l,mid),query1(rch,mid+1,r));
	}
}
namespace shu{//树链剖分
	int dfn[maxn],idc,top[maxn],deep[maxn];
	int par[maxn],hc[maxn],szt[maxn],rdf[maxn];
	void dfs(int x){
		szt[x]=1,hc[x]=0;
		for(int i:g[x])if(i!=par[x]){
			par[i]=x,deep[i]=deep[x]+1;
			dfs(i),szt[x]+=szt[i];
			if(hc[x]==0||szt[i]>szt[hc[x]]) hc[x]=i;
		}
	}
	void ddfs(int x){
		rdf[dfn[x]=idc++]=x;
		if(hc[x]==0) return;
		top[hc[x]]=top[x],ddfs(hc[x]);
		for(int i:g[x]) if(i!=hc[x]&&i!=par[x])
			top[i]=i,ddfs(i);
	}
	int lca(int u,int v){
		for(;top[u]!=top[v];v=par[top[v]])
			if(deep[top[u]]>deep[top[v]])
				swap(u,v);
		return deep[u]>deep[v]?v:u;
	}
	void change(int u,int v,int d){//从u到v的链设置数为d
		using namespace seg;
		D=d;
		while(top[u]!=top[v]){  //deep[top[u]]>=deep[top[v]]
			if(deep[top[u]]<deep[top[v]]) swap(u,v);
			L=dfn[top[u]],R=dfn[u];update();
			u=par[top[u]];
		}  //deep[u]>=deep[v]
		if(deep[u]<deep[v]) swap(u,v);
		L=dfn[v],R=dfn[u],update();
	}
	int query(int u,int v){//从u到v的链询问最大最小值
		using namespace seg;
		pii res={543210,-543210};
		while(top[u]!=top[v]){
			if(deep[top[u]]<deep[top[v]]) swap(u,v);
			L=dfn[top[u]],R=dfn[u];
			res=pushup(res,query1());
			u=par[top[u]];
		}
		if(deep[u]<deep[v]) swap(u,v);
		L=dfn[v],R=dfn[u];
		res=pushup(res,query1());
		return res.mi==res.ma;
	}
}
struct {int u,v,len;}qr[maxn];
int main(){
	scanf("%d%d",&n,&q);
	for(int u,v,i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	using namespace shu;
	deep[1]=1;dfs(1);//dfs会初始化deep,par,szt,hc数组
	idc=1;top[1]=1;ddfs(1);//ddfs会初始化top,rdf,dfn数组
	for(int i=0;i<q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		qr[i]={u,v,0};
		qr[i].len=deep[u]+deep[v]-2*deep[lca(u,v)];
	}
	sort(qr,qr+q,[](auto&a,auto&b){return a.len>b.len;});
	for(int i=0;i<q;i++){
		if(!query(qr[i].u,qr[i].v))
			return (puts("No")),0;
		change(qr[i].u,qr[i].v,i+1);
	}
	puts("Yes");
}