#include<cstdio>
#include<queue>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=109,mod=100000;
char mp[300]={},s[16];
int tr[maxn][4]={},ed[maxn]={},sz=1,fail[maxn]={};
void insert(char *s){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=mp[s[i]];
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	ed[u]=1;
}
void build(){
	queue<int> q;
	rep(i,0,4) if(tr[0][i])
		q.push(tr[0][i]);
	while(q.size()){
		int u=q.front();q.pop();
		if(ed[fail[u]]) ed[u]=1;
		rep(i,0,4){
			int ne=tr[u][i];
			if(ne) fail[ne]=tr[fail[u]][i],q.push(ne);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
int ma[maxn][maxn]={},an[maxn][maxn]={};
int n,m;
void mul(int a[maxn][maxn],int b[maxn][maxn]){
	int c[maxn][maxn]={};
	rep(i,0,sz) rep(j,0,sz) {
		ll cc=0;
		rep(k,0,sz)
			cc+=1ll*a[i][k]*b[k][j];
		c[i][j]=cc%mod;
	}
	memcpy(a,c,sizeof c);
}
int main(){
	mp['A']=0,mp['C']=1,mp['G']=2,mp['T']=3;
	scanf("%d %d",&m,&n);
	rep(i,0,m) scanf("%s",s),insert(s);
	build();
	rep(i,0,sz){
		if(!ed[i]) rep(j,0,4) 
			if(!ed[tr[i][j]]) ma[i][tr[i][j]]++;
	}
	rep(i,0,sz) an[i][i]=1;
	for(;n;n/=2,mul(ma,ma)) if(n&1) mul(an,ma);
	int res=0;
	rep(i,0,sz) res+=an[0][i];
	printf("%d\n",res%mod);
}