#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
#include<queue>
const int maxn=1e6+9;
struct state{
	int len,nex;
	int ch[26];
}st[maxn*2];
ll times[maxn*2]={};
vector<int> g[maxn*2]={};
int sz=0,last;
void sam_init(){
	st[sz++]={0,-1};
	last=0;
}
void sam_extend(int c){
	int cur=sz++;
	times[cur]=1;
	st[cur].len=st[last].len+1;
	int p=last;
	for(;~p&&st[p].ch[c]==0;p=st[p].nex)
		st[p].ch[c]=cur;
	if(p==-1) st[cur].nex=0;
	else {
		int q=st[p].ch[c];
		if(st[p].len+1==st[q].len)
			st[cur].nex=q;
		else {
			int clone=sz++;
			st[clone]=st[q];
			st[clone].len=st[p].len+1;
			for(;~p&&st[p].ch[c]==q;p=st[p].nex)
				st[p].ch[c]=clone;
			st[q].nex=st[cur].nex=clone;
		}
	}
	last=cur;
}
char s[maxn]={};
ll ans=0;
void dfs(int x){
	for(int i:g[x]) dfs(i),times[x]+=times[i];
}
int main(){
	scanf("%s",s);
	sam_init();
	for(char *p=s;*p;p++) sam_extend(*p-'a');
	rep(i,1,sz) g[st[i].nex].push_back(i);
	dfs(0);
	rep(i,1,sz) if(times[i]>1)
		ans=max(times[i]*st[i].len,ans);
	printf("%lld\n",ans);
}