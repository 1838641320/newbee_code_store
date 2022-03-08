#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
int len[maxn*2],nex[maxn*2];
map<int,int> ch[maxn*2];
int sz,last;
void sam_init(){
	rep(i,0,sz) len[i]=nex[i]=0,ch[i].clear();
	sz=1,last=0;nex[0]=-1;
}
void sam_extend(int c){
	int cur=sz++,p=last;
	len[cur]=len[last]+1;
	last=cur;
	for(;~p&&ch[p].count(c)==0;p=nex[p])
		ch[p][c]=cur;
	if(p==-1) return void(nex[cur]=0);
	int q=ch[p][c];
	if(len[p]+1==len[q])
		return void(nex[cur]=q);
	int cl=sz++;
	nex[cl]=nex[q];
	ch[cl]=ch[q];len[cl]=len[p]+1;
	nex[q]=nex[cur]=cl;
	for(;~p;p=nex[p]){
		auto it=ch[p].find(c);
		if(it==ch[p].end()||it->second!=q) break;
		ch[p][c]=cl;
	}
}
ll a[maxn]={1<<29},n;
vector<ll> st,sts;
void solve(int __case){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sam_init();
	st.resize(1,0),sts.resize(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		sam_extend(a[i]);
		int up=i-len[nex[last]];
		while(a[st.back()]<=a[i]) st.pop_back(),sts.pop_back();
		sts.push_back(sts.back()+a[i]*(i-st.back()));
		st.push_back(i);
		ll ub=st.size()-1,lb=0,mid;//(]
		while(ub>lb+1){
			mid=(ub+lb)/2;
			if(st[mid]>up) ub=mid;
			else lb=mid;
		}
		ans+=sts[lb]+a[st[ub]]*(up-st[lb]);
	}
	printf("%lld\n",ans);
}
int main(){
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) solve(i);
}