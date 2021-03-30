#include<iostream>
#include<algorithm>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=5e4+9;
int pa[maxn],ch[maxn][2];
int n;
#define l(x) ch[x][0]
#define r(x) ch[x][1]
#define get(x) (r(pa[x])==x)
int isrt(int x){return l(pa[x])!=x&&r(pa[x])!=x;}
void rotate(int x){
	int y=pa[x],z=pa[y],k=get(x);
	if(!isrt(y)) ch[z][ch[z][1]==y]=x;
	ch[y][k]=ch[x][!k],pa[ch[x][!k]]=y;
	ch[x][!k]=y,pa[y]=x,pa[x]=z;
}
void splay(int x){
	for(int p;p=pa[x],!isrt(x);rotate(x))
		if(!isrt(p)&&get(p)==get(x)) rotate(p);
}
int access(int x){
	int p=0;
	for(;x;p=x,x=pa[x]) splay(x),ch[x][1]=p;
	return p;
}
void link(int x,int y){pa[x]=y;}
void cut(int x){
	access(x),splay(x),pa[l(x)]=0,l(x)=0;
}
int findrt(int x){
	access(x),splay(x);
	for(;l(x);x=l(x));
	splay(x);return x;
}
int issub(int u,int v){
	access(v),splay(u);
	while(ch[u][1]) u=ch[u][1];
	return v==u;
}
void solve(){
	mem(ch,0),mem(pa,0);
	for(int i=1,v;i<=n;i++){
		scanf("%d",&v);
		link(i,v);
	}
	int m;char buf[16]={};
	scanf("%d",&m);
	while(m--){
		scanf("%s",buf);
		if(buf[0]=='Q') {
			int v;scanf("%d",&v);
			printf("%d\n",findrt(v));
		}
		else {
			int u,v;scanf("%d%d",&u,&v);
			if(issub(u,v)||u==v) continue;
			cut(u);
			if(v) link(u,v);
		}
	}
}
int main(){
	int t=0;
	while(~scanf("%d",&n))
		t++&&puts(""),solve();
}