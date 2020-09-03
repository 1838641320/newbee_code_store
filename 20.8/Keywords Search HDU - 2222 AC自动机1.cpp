#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
namespace AC{
int tr[maxn][26],sz;
int end[maxn],fail[maxn];
void insert(char s[]){
	int u=0,c,len=strlen(s);
	rep(i,0,len){
		c=s[i]-'a';
		if(!tr[u][c]) tr[u][c]=++sz;
		u=tr[u][c];
	}
	end[u]++;
}
void build(){
	queue<int> q;
	rep(i,0,26)
		if(tr[0][i]) q.push(tr[0][i]);
	while(q.size()){
		int u=q.front();q.pop();
		rep(i,0,26){
			int ne=tr[u][i];
			if(ne)
				fail[ne]=tr[fail[u]][i],q.push(ne);
			else 
				tr[u][i]=tr[fail[u]][i];
		}
	}
}
int query(char p[]){
	int u=0,res=0,len=strlen(p);
	rep(i,0,len){
		u=tr[u][p[i]-'a'];
		for(int j=u;j&&end[j]!=-1;j=fail[j])
			res+=end[j],end[j]=-1;
	}
	return res;
}
void clear(){
	mem(tr,0),mem(end,0),mem(fail,0);
	sz=0;
}
}
char s[maxn];
void solve(){
	int n;
	AC::clear();
	scanf("%d",&n);
	rep(i,0,n) scanf("%s",s),AC::insert(s);
	AC::build();
	scanf("%s",s);
	printf("%d\n",AC::query(s));
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}