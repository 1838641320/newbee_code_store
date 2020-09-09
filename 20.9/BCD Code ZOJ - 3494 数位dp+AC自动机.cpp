#include<cstdio>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
const int maxn=2e3+9;
int tr[maxn][2],sz=1,fail[maxn],ed[maxn];
void insert(char *s){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=s[i]-'0';
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	ed[u]=1;
}
int q[maxn];
void build(){
	int l=0,r=0;
	rep(i,0,2) if(tr[0][i])
		q[r++]=tr[0][i];
	while(l<r){
		int u=q[l++];
		ed[u]|=ed[fail[u]];
		rep(i,0,2){
			int ne=tr[u][i];
			if(ne) fail[ne]=tr[fail[u]][i],q[r++]=ne;
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
char A[209],B[209];
int bi[maxn],trans[maxn][10];
ll dp[209][maxn];
void trans_pre(){
	rep(i,0,sz) rep(j,0,10){
		int u=i,x=j;
		for(int k=3;k>=0;k--){
			u=tr[u][(x>>k)&1];
			if(ed[u]) {u=-1;break;}
		}
		trans[i][x]=u;
	}
}
ll dfs(int pos,int sta,bool limit,bool pre){
	if(pos==-1) return 1;
	if(!limit&&!pre&&dp[pos][sta]!=-1) return dp[pos][sta];
	int up=limit?bi[pos]:9;
	ll res=0;
	for(int i=0;i<=up;i++){
		if(pre&&i==0) res+=dfs(pos-1,0,limit&&i==up,1);
		else if(~trans[sta][i])
			res+=dfs(pos-1,trans[sta][i],limit&&i==up,0);
	}
	res%=mod;
	if(!limit&&!pre) dp[pos][sta]=res;
	return res;
}
ll solve(char *s){
	int len=strlen(s);
	rep(i,0,len) bi[i]=s[len-1-i]-'0';
	while(bi[len-1]==0&&len) len--;
	return dfs(len-1,0,1,1)%mod;
}
int main(){
	int __,n;scanf("%d",&__);
	while(__--){
		mem(tr,0),mem(fail,0),mem(ed,0);sz=1;
		mem(dp,-1);
		scanf("%d",&n);
		rep(i,0,n){
			scanf("%s",A);
			insert(A);
		}
		build();
		trans_pre();
		scanf("%s%s",A,B);
		for(int i=strlen(A)-1;~i;i--){
			if(A[i]=='0') A[i]='9';
			else {A[i]--;break;}
		}
		printf("%lld\n",(solve(B)-solve(A)+mod)%mod);
	}
}