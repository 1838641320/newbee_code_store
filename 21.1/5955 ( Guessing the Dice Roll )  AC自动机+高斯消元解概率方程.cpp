#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e2+9;
int n,L,ins[maxn];
int tr[maxn][6],sz,ed[maxn],fa[maxn];
int outt[maxn]={};
void insert(int *l,int n,int index){
    int u=0,c;
    rep(i,0,n){
        c=l[i]-1;
        if(!tr[u][c]) tr[u][c]=++sz;
        u=tr[u][c];
    }
    ed[u]=index;
    outt[index]=u;
}
void build(){
    int q[maxn],l=0,r=0;
    rep(i,0,6) if(tr[0][i])
        q[r++]=tr[0][i];
    while(l<r){
        int u=q[l++];
        rep(i,0,6){
            int ne=tr[u][i];
            if(ne) fa[ne]=tr[fa[u]][i],q[r++]=ne;
            else tr[u][i]=tr[fa[u]][i];
        }
    }
}
void AC_reset(){
    mem(tr,0);mem(ed,0);mem(fa,0);
    sz=0;
}
typedef vector<double>vec;
typedef vector<vec> mat;
void gause(mat&a){
    int n=a.size();
    rep(i,0,n){
        int p=i;
        rep(j,i+1,n) 
            if(fabs(a[j][i])>fabs(a[p][i])) p=j;
        swap(a[p],a[i]);
        rep(j,i+1,n+1) a[i][j]/=a[i][i];
        rep(j,0,n) if(j!=i)
            rep(k,i+1,n+1) a[j][k]-=a[j][i]*a[i][k];
    }
}
void solve(){
    AC_reset();
    scanf("%d%d",&n,&L);
    rep(i,0,n){
        rep(j,0,L)
            scanf("%d",&ins[j]);
        insert(ins,L,i+1);
    }
    build();
    mat t(sz+1,vec(sz+2));
    t[0][sz+1]=1;
    rep(i,0,sz+1){
        t[i][i]+=1;
        if(ed[i]) continue;
        rep(j,0,6) t[tr[i][j]][i]-=1.0/6.0;
    }
    gause(t);
    rep(i,1,n+1) printf("%lf%c",t[outt[i]][sz+1]," \n"[i==n]);
}
int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}