#include<cstdio>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll bi=1e16;
struct Int{
	ll a[7];
	void print(){
		int p=6;
		while(p>0&&a[p]==0) p--;
		printf("%lld",a[p--]);
		for(;~p;) printf("%016lld",a[p--]); 
	}
	void operator+=(Int&x){
		rep(i,0,7) 
			a[i]+=x.a[i],a[i+1]+=a[i]/bi,a[i]%=bi;
	}
};
const int maxs=109;
int n,m,p,mp[800]={};
int tr[maxs][59]={},sz=1,ed[maxs]={},fa[maxs]={};
void insert(char *s){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=mp[(int)s[i]+300];
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	ed[u]++;
}
void build(){
	int q[maxs],l=0,r=0;
	rep(i,0,n) if(tr[0][i])
		q[r++]=tr[0][i];
	while(l<r){
		int u=q[l++];
		ed[u]|=ed[fa[u]];
		rep(i,0,n){
			int ne=tr[u][i];
			if(ne) fa[ne]=tr[fa[u]][i],q[r++]=ne;
			else tr[u][i]=tr[fa[u]][i];
		}
	}
}
Int dp[59][maxs]={},ans={};
char s[59];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	scanf("%s",s);
	for(int i=0;s[i];i++) mp[(int)s[i]+300]=i;
	rep(i,0,p) scanf("%s",s),insert(s);
	build();
	dp[0][0].a[0]=1;
	rep(i,0,m) rep(j,0,sz)
		rep(k,0,n){
			int to=tr[j][k];
			if(ed[to]) continue;
			dp[i+1][to]+=dp[i][j];
	}
	rep(i,0,sz) ans+=dp[m][i];
	ans.print();puts("");
}