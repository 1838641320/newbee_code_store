#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
//-------------------------------------------------
using namespace std;
#include<queue>
const int maxn=4e4+9;
int len[maxn*2],nex[maxn*2],ch[maxn*2][26];
ll times[maxn*2]={},pos[maxn*2];
vector<int> g[maxn*2]={};
int sz,last;
void sam_init(){
	rep(i,0,sz) len[i]=nex[i]=0,mem(ch[i],0),times[i]=0,pos[i]=0;
	sz=1;last=0;nex[0]=-1;
}
void sam_extend(int c,int pi){
	int cur=sz++;
	times[cur]=1;
	pos[cur]=pi;
	len[cur]=len[last]+1;
	int p=last;
	for(;~p&&ch[p][c]==0;p=nex[p])
		ch[p][c]=cur;
	if(p==-1) nex[cur]=0;
	else {
		int q=ch[p][c];
		if(len[p]+1==len[q])
			nex[cur]=q;
		else {
			int clone=sz++;
			nex[clone]=nex[q];
			memcpy(ch[clone],ch[q],sizeof(ch[q]));
			len[clone]=len[p]+1;
			nex[q]=nex[cur]=clone;
			for(;~p&&ch[p][c]==q;p=nex[p])
				ch[p][c]=clone;
		}
	}
	last=cur;
}
char s[maxn]={};
ll ans=0;
void dfs(int x){
	for(int i:g[x]) 
		dfs(i),
		times[x]+=times[i],
		pos[x]=max(pos[x],pos[i]);
}
int m;
int main(){
	while(scanf("%d",&m),m){
		sam_init();
		scanf("%s",s);
		int slen=strlen(s);
		rep(i,0,slen){
			sam_extend(s[i]-'a',i);
		}
		rep(i,0,sz+1) g[i].clear();
		rep(i,1,sz) g[nex[i]].push_back(i);
		dfs(0);
		int maxl=0;
		rep(i,0,sz) if(times[i]>=m) {
			if(len[i]>maxl){
				maxl=len[i];
				ans=pos[i];
			}
			else if(len[i]==maxl){
				ans=max(ans,pos[i]);
			}			
		}
		if(maxl==0) puts("none");
		else printf("%d %d\n",maxl,ans-maxl+1);
	}
}