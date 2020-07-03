#include"s.h"
#include<bits/stdc++.h>
#define mid (l+r)/2
#define lch in*2
#define rch in*2+1
using namespace std;
const int maxn=1e5+9;
struct node{ int v,lv,rv,lz; }tr[2][4*maxn];
int n,m,L,R,D,TR,Q;
void build(int in=1,int l=1,int r=n){
	int len=r-l+1;
	tr[0][in]=tr[1][in]={len,len,len,-1};
	if(l==r) return;
	build(lch,l,mid);build(rch,mid+1,r);
}
void pushup(int in,int l,int r){
	auto &ro=tr[TR][in],&lc=tr[TR][lch],&rc=tr[TR][rch];
	ro.lv=lc.lv;
	ro.rv=rc.rv;
	if(lc.lv>=mid-l+1) ro.lv+=rc.lv;
	if(rc.rv>=r-mid) ro.rv+=lc.rv;
	ro.v=max(max(lc.v,rc.v),lc.rv+rc.lv);
}
void pushdown(int in,int l,int r){
	int la=tr[TR][in].lz;
	if(la==-1) return;
	tr[TR][in].lz=-1;
	int lv=la*(mid-l+1),rv=la*(r-mid);
	tr[TR][lch]={lv,lv,lv,la};
	tr[TR][rch]={rv,rv,rv,la};
}
void update(int in=1,int l=1,int r=n){
	if(l>R||r<L) return;
	if(L<=l&&R>=r) {
		int lv=(r-l+1)*D;
		tr[TR][in]={lv,lv,lv,D};
		return;
	}
	pushdown(in,l,r);
	update(lch,l,mid);update(rch,mid+1,r);
	pushup(in,l,r);
}
int query(int in=1,int l=1,int r=n){
	if(l==r) return l;
	pushdown(in,l,r);
	if(tr[TR][lch].v>=Q)
		return query(lch,l,mid);
	if(tr[TR][lch].rv+tr[TR][rch].lv>=Q)
		return mid-tr[TR][lch].rv+1;
	return query(rch,mid+1,r);
}
char cmd[9];
void solve(){
	cin>>n>>m;
	build();
	while(m--){
		scanf("%s",cmd);
		if(cmd[0]=='S'){
			scanf("%d%d",&L,&R);
			D=1;
			TR=0;update();
			TR=1;update();
			puts("I am the hope of chinese chengxuyuan!!");
		}
		else if(cmd[0]=='D'){
			scanf("%d",&Q);
			if(tr[0][1].v>=Q){
				TR=0;L=query();
				printf("%d,let's fly\n",L);
				R=L+Q-1,D=0;
				TR=0;update();
				continue;
			}
			puts("fly with yourself");
			continue;
		}
		else {
			scanf("%d",&Q);
			if(tr[0][1].v>=Q){
				TR=0;L=query();
				printf("%d,don't put my gezi\n",L);
				R=L+Q-1,D=0;
				TR=0;update();
				TR=1;update();
				continue;
			}
			else if(tr[1][1].v>=Q){
				TR=1;L=query();
				printf("%d,don't put my gezi\n",L);
				R=L+Q-1,D=0;
				TR=0;update();
				TR=1;update();
			}
			else puts("wait for me");
		}
	}
}
int main() {
	int __;scanf("%d",&__);
	for(int i=1;i<=__;i++) printf("Case %d:\n",i),solve();
}