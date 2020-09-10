#include<cstdio>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
using namespace std;
using ull=unsigned long long;
const int maxn=59;
int tr[maxn][26],sz=1,fa[maxn],ed[maxn];
void insert(char *s){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=s[i]-'a';
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	ed[u]=1;
}
void build(){
	int q[maxn],l=0,r=0;
	rep(i,0,26) if(tr[0][i])
		q[r++]=tr[0][i];
	while(l<r){
		int u=q[l++];
		ed[u]|=ed[fa[u]];
		rep(i,0,26){
			int ne=tr[u][i];
			if(ne) fa[ne]=tr[fa[u]][i],q[r++]=ne;
			else tr[u][i]=tr[fa[u]][i];
		}
	}
}
void mul(ull a[maxn][maxn],ull b[maxn][maxn]){
	ull c[maxn][maxn]={};
	rep(i,0,sz*2) rep(j,0,sz*2)
		rep(k,0,sz*2) c[i][j]+=a[i][k]*b[k][j];
	memcpy(a,c,sizeof c);
}
void qpow(ull a[maxn][maxn],ull n){
	ull c[maxn][maxn]={};rep(i,0,sz*2) c[i][i]=1;
	for(;n;n>>=1,mul(a,a)) if(n&1llu) mul(c,a);
	memcpy(a,c,sizeof c);
}
int main(){
	ull n,m;
	char s[maxn]={};
	while(~scanf("%llu%llu",&n,&m)){
		mem(tr,0),mem(fa,0),mem(ed,0),sz=1;
		rep(i,0,n) scanf("%s",s),insert(s);
		build();
		ull res[maxn][maxn]={},ans=0;
		rep(i,0,sz) res[i][i]=res[i][sz+i]=1;
		rep(i,0,sz){
			if(ed[i]) res[sz+i][sz+i]=26;
			else rep(j,0,26) res[sz+i][sz+tr[i][j]]++;
		}
		qpow(res,m+1);
		rep(i,0,maxn) if(ed[i]) ans+=res[0][sz+i];
		printf("%llu\n",ans);
	}
}