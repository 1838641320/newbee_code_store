#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#include<queue>
typedef long long ll;
const int maxn=1.2e5+9;
string sa,sb;
int n,m;
namespace sam{
int len[maxn*2],nex[maxn*2],ch[maxn*2][27];//main node info
int sz,last;
void init(){
	rep(i,0,sz) len[i]=nex[i]=0,mem(ch[i],0);
	sz=1;last=0;nex[0]=-1;
}
void extend(int c){
	int cur=sz++,p=last;
	len[cur]=len[last]+1;
	last=cur;
	for(;~p&&ch[p][c]==0;p=nex[p])
		ch[p][c]=cur;
	if(p==-1) return void(nex[cur]=0);
	int q=ch[p][c];
	if(len[p]+1==len[q]) 
		return void(nex[cur]=q);
	int cl=sz++;//clone node
	nex[cl]=nex[q];
	memcpy(ch[cl],ch[q],sizeof(ch[q]));
	len[cl]=len[p]+1;
	nex[q]=nex[cur]=cl;
	for(;~p&&ch[p][c]==q;p=nex[p])
		ch[p][c]=cl;
}
}
int ml[maxn*2];
int check(int len){
	int np=-9;
	for(int i=0;i+len<=2*n;i++){
		if(ml[i+len-1]>=len) np=i;
		if(i+len>=n&&i+len-n>np)
			return 0;
	}
	return 1;
}
void solve(){
	scanf("%d%d",&n,&m);
	sam::init();
	cin>>sa;
	sa+=sa;
	for(int i=0;i<m;i++) {
		string t;
		cin>>t;
		sb+=char('z'+1)+t;
	}
	for(char c:sb) sam::extend(c-'a');
	for(int i=0,ml1=0,p=0;i<(int)sa.size();i++){
		using namespace sam;
		int c=sa[i]-'a';
		if(ch[p][c]) p=ch[p][c],ml1++;
		else{
			while(p!=-1&&!ch[p][c]) p=nex[p];
			if(p==-1) ml1=p=0;
			else ml1=len[p]+1,p=ch[p][c];
		}
		ml[i]=ml1;
	}
	int ub=n+1,lb=0;
	for(int mid;ub>lb+1;){
		mid=(ub+lb)/2;
		if(check(mid)) lb=mid;
		else ub=mid;
	}
	printf("%d\n",lb);
}
int main(){
	int t=1;
	// scanf("%d",&t);
	for(int i=1;i<=t;i++) 
		solve();
}