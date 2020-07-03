#include"s.h"
#include<bits/stdc++.h>
#define mid (l+r)/2
#define lch in*2
#define rch in*2+1
using namespace std;
const int maxn=209;
int n,L,R,D,tot;
double x[maxn];
struct { double len;int v; } tr[4*maxn];
struct Line{
    double x1,x2,h;
    int d;
    bool operator < (const Line &a) const { return h<a.h; }
}rect[maxn];
void pushup(int in,int l,int r){
    if(tr[in].v) tr[in].len=x[r+1]-x[l];
    else tr[in].len=tr[lch].len+tr[rch].len;
}
void update(int in=1,int l=1,int r=tot-1){
    if(l>R||r<L) return;
    if(L<=l&&R>=r) {
        tr[in].v+=D;
        pushup(in,l,r);
        return;
    }
    update(lch,l,mid);update(rch,mid+1,r);
    pushup(in,l,r);
}
int main(){
    int __=1;
    while(scanf("%d",&n),n){
        printf("Test case #%d\nTotal explored area: ",__++);
        tot=1;
        memset(x,0,sizeof x);
        for(int i=1;i<=n;i++){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            rect[tot]={x1,x2,y1,1};
            x[tot++]=x1;
            rect[tot]={x1,x2,y2,-1};
            x[tot++]=x2;
        }
        sort(x+1,x+1+2*n);
        sort(rect+1,rect+1+2*n);
        tot=unique(x+1,x+1+2*n)-x-1;
        double ans=0;
        for(int i=1;i<=2*n;i++){
            ans+=tr[1].len*(rect[i].h-rect[i-1].h);
            L=lower_bound(x+1,x+1+tot,rect[i].x1)-x;
            R=lower_bound(x+1,x+1+tot,rect[i].x2)-x-1;
            D=rect[i].d;
            update();
        }
        printf("%.2lf\n\n",ans);
    }
}
