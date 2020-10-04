// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//
const ll mod=1e9+7;
const int maxs=14650,maxn=509;
int tr[maxn][4],fa[maxn],ed[maxn]={},sz=1;
char s[50]={},mp[300]={};
int n;
void insert(char *s){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=mp[s[i]];
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	ed[u]++;
}
void build(){
	int q[maxn],l=0,r=0;
	rep(i,0,4) if(tr[0][i])
		q[r++]=tr[0][i];
	while(l<r){
		int u=q[l++];
		ed[u]+=ed[fa[u]];
		rep(i,0,4){
			int ne=tr[u][i];
			if(ne) fa[ne]=tr[fa[u]][i],q[r++]=ne;
			else tr[u][i]=tr[fa[u]][i];
		}
	}
}
int dp[maxs][maxn];
int _kase=1;
void solve(){
	mem(tr,0),mem(ed,0),mem(fa,0),sz=1;
	rep(i,0,n) scanf("%s",s),insert(s);
	build();
	scanf("%s",s);
	int len=strlen(s),radix[6]={},br[6]={},base=0;
	rep(i,0,len) radix[mp[s[i]]]++;
	br[0]=1;
	rep(i,0,4) {
		br[i+1]=br[i]*(radix[i]+1);
		base=base+radix[i]*br[i];
	}
	rep(i,0,sz) rep(j,0,base+1) dp[j][i]=-1;
	dp[base][0]=0;
	for(int i=base;i>0;i--) rep(j,0,sz) if(dp[i][j]!=-1) {
			rep(k,0,4){
				int ni=i-br[k],nj=tr[j][k];
				if(i%br[k+1]>=br[k])
					dp[ni][nj]=__max(dp[ni][nj],dp[i][j]+ed[nj]);
			}
	}
	int ans=0;
	rep(i,0,sz) ans=__max(ans,dp[0][i]);
	printf("Case %d: %d\n",_kase++,ans);
}
int main(){
	mp['A']=0,mp['C']=1,mp['G']=2,mp['T']=3;
	while(scanf("%d",&n),n) solve();
}