#include"s.h"
#include<bits/stdc++.h>
#define mid (l+r)/2
#define lch in*2
#define rch in*2+1
using namespace std;
const int maxn=2e3+9;
int n,L,R,D,tot;
double x[maxn];
struct line{
	double x1,x2,h;
	int d;
	bool operator < (const line &a) const { return h<a.h; }
}rect[maxn];
struct node{
	double len,len2;
	int v;
}tr[maxn*4];
void pushup(int in,int l,int r){
	if(tr[in].v) 
		tr[in].len=x[r+1]-x[l];
	else if(l!=r) 
		tr[in].len=tr[lch].len+tr[rch].len;
	else 
		tr[in].len=0;
	if(tr[in].v>=2)
		tr[in].len2=x[r+1]-x[l];
	else if(l!=r&&tr[in].v==1)
		tr[in].len2=tr[lch].len+tr[rch].len;
	else if(l!=r)
		tr[in].len2=tr[lch].len2+tr[rch].len2;
	else
		tr[in].len2=0;
}
void update(int in=1,int l=1,int r=tot-1){
	if(l>R||r<L) return;
	if(L<=l&&R>=r){
		tr[in].v+=D;
		pushup(in,l,r);
		return;
	}
	update(lch,l,mid);update(rch,mid+1,r);
	pushup(in,l,r);
}
double solve(){
	memset(x,0,sizeof x);
	tot=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		double x1,x2,y1,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		rect[tot]={x1,x2,y1,1};
		x[tot++]=x1;
		rect[tot]={x1,x2,y2,-1};
		x[tot++]=x2;
	}
	sort(rect+1,rect+1+2*n);
	sort(x+1,x+1+2*n);
	tot=unique(x+1,x+1+2*n)-x-1;
	memset(tr,0,sizeof tr);
	double ans=0;
	for(int i=1;i<=n*2;i++){
		ans+=tr[1].len2*(rect[i].h-rect[i-1].h);
		L=lower_bound(x+1,x+1+tot,rect[i].x1)-x;
		R=lower_bound(x+1,x+1+tot,rect[i].x2)-x-1;
		D=rect[i].d;
		update();
	}
	return ans;
}
int main(){
	int t;scanf("%d",&t);
	while(t--) printf("%.2lf\n",solve());
}