#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
#include<queue>
const int maxn=5e5+9;
int len[maxn*2],nex[maxn*2],ch[maxn*2][26];
ll times[maxn*2]={};
vector<int> g[maxn*2];
int sz,last;
void sam_init(){
	mem(len,0),mem(nex,0),mem(ch,0),
	sz=1;last=0;nex[0]=-1;
}
void sam_extend(int c,int pi){
	int cur=sz++,p=last;;
	times[cur]=1;
	len[cur]=len[last]+1;
	for(;~p&&ch[p][c]==0;p=nex[p])
		ch[p][c]=cur;
	if(p==-1) nex[cur]=0;
	else {
		int q=ch[p][c];
		if(len[p]+1==len[q]) nex[cur]=q;
		else {
			int cl=sz++;
			nex[cl]=nex[q];
			memcpy(ch[cl],ch[q],sizeof(ch[q]));
			len[cl]=len[p]+1;
			nex[q]=nex[cur]=cl;
			for(;~p&&ch[p][c]==q;p=nex[p])
				ch[p][c]=cl;
		}
	}
	last=cur;
}
char s[maxn];
ll ti[maxn*2],dnt,t,k;
bool vis[maxn*2];
vector<char> vec;
void getprt(int x,int ty){
	if(k<=0) return;
	// {for(char c:vec) putchar(c);}puts("");
	ti[x]=ty?times[x]:1;
	if(x) {
		k-=ti[x];
		if(k<=0) {
			for(char c:vec) putchar(c);
			puts("");
			return;
		}
	}
	vis[x]=1;
	rep(i,0,26)if(ch[x][i]){
		vec.push_back('a'+i);
		int an=ch[x][i];
		if(vis[an]&&k>ti[an]){
			k-=ti[an];
		}
		else getprt(an,ty);
		ti[x]+=ti[an];
		vec.pop_back();
	}
}
void dfs2(int x){for(int i:g[x]) dfs2(i),times[x]+=times[i];}
void solve(){
	sam_init();
	scanf("%s",s);
	int slen=strlen(s);
	rep(i,0,slen) sam_extend(s[i]-'a',i);
	rep(i,1,sz) g[nex[i]].push_back(i);
	dfs2(0);
	while(~scanf("%lld%lld",&t,&k)){
		rep(i,0,sz) vis[i]=0;
		getprt(0,t);
		if(k>0) puts("-1");
	}
}
int main(){
	// int t;scanf("%d",&t);
	// while(t--) 
		solve();
}