#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=2e4+9;
char pp[159][80]={},t[(int)1e6+9];
int cnt[159],n;
namespace AC{
	int tr[maxn][26],sz,end[maxn],fail[maxn];
	void insert(char *s,int num){
		int u=0,c,len=strlen(s);
		rep(i,0,len){
			c=s[i]-'a';
			if(!tr[u][c]) tr[u][c]=++sz;
			u=tr[u][c];
		}
		end[u]=num;
	}
	void build(){
		queue<int> q;
		rep(i,0,26) if(tr[0][i])
			q.push(tr[0][i]);
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
	void query(char *s){
		int u=0,len=strlen(s);
		rep(i,0,len){
			u=tr[u][s[i]-'a'];
			for(int j=u;j;j=fail[j]) 
				cnt[end[j]]++;
		}
	}
	void clear(){
		mem(tr,0),mem(end,0),mem(fail,0);
		sz=0;
	}
}
int main(){
	using namespace AC;
	while(scanf("%d",&n),n){
		clear();mem(cnt,0);
		for(int i=1;i<=n;i++){
			scanf("%s",pp[i]);
			insert(pp[i],i);
		}
		build();
		scanf("%s",t);
		query(t);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,cnt[i]);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) 
			if(cnt[i]==ans) puts(pp[i]);
	}
}