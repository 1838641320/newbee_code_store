#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//------------------------------------------------------
using namespace std;
const int maxn=1e3+9;
char s[maxn],p[maxn];
namespace sa{
	int n;
	int sa[maxn],rk[maxn];
	int id[maxn],px[maxn],cnt[maxn],oldrk[maxn<<1];
	bool cmp_sa(int x,int y,int w){
		return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
	}
	void construct_sa(char s[]){
		int m=256,p;
		for(int i=1;i<=n;i++) cnt[rk[i]=s[i]]++;
		for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>0;i--) sa[cnt[rk[i]]--]=i;
		for(int w=1;w<n;w<<=1,m=p){
			p=0;
			for(int i=n;i>n-w;i--) id[++p]=i;
			for(int i=1;i<=n;i++) if(sa[i]>w)
				id[++p]=sa[i]-w;
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++) cnt[px[i]=rk[id[i]]]++;
			for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
			for(int i=n;i>0;i--) sa[cnt[px[i]]--]=id[i];
			memcpy(oldrk,rk,sizeof(rk));
			p=0;
			for(int i=1;i<=n;i++)
				rk[sa[i]]=cmp_sa(sa[i],sa[i-1],w)?p:++p; 
		}
	}
	int sa_find(char p[],char s[],int sa[]){
		int ub=n,lb=-1,lenp=strlen(p);
		while(ub-lb>1){
			int mid=ub+lb>>1;
			if(strncmp(p,s+sa[mid],lenp)<=0) ub=mid;
			else lb=mid;
		}
		if(strncmp(p,s+sa[ub],strlen(p))==0) return sa[ub];
		return -1;
	}
}
//---------------------------------------------------
namespace sam{
	struct state{
		int len,nex;
		int ch[26];
		int fpos;
	}st[maxn*2];
	int sz=0,last;
	void sam_init(){
		sz=last=0;
		st[sz++]={0,-1};
	}
	void sam_extend(int c){
		int cur=sz++;
		st[cur].fpos=st[cur].len=st[last].len+1;
		int p=last;
		for(;~p&&st[p].ch[c]==0;p=st[p].nex)
			st[p].ch[c]=cur;
		if(p==-1) st[cur].nex=0;
		else {
			int q=st[p].ch[c];
			if(st[p].len+1==st[q].len)
				st[cur].nex=q;
			else{
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
	int sam_find(char p[]){
		int pi=0;
		char *ps=p;
		for(;*ps;ps++){
			pi=st[pi].ch[*ps-'a'];
			if(pi==0) return -1;
		}
		return st[pi].fpos-(ps-p);
	}
}

//------------------------------------------

int main(){

	// {
	// 	using namespace sa;
	// 	scanf("%s",s+1);
	// 	n=strlen(s+1);
	// 	construct_sa(s);
	// 	while(scanf("%s",p)==1) {
	// 		int pp=sa_find(p,s,sa::sa);
	// 		printf("%d\n",pp);
	// 		if(pp!=-1) puts(s+pp);
	// 	}
	// }

	{
		using namespace sam;
		scanf("%s",s);
		sam_init();
		for(char *p=s;*p;p++) sam_extend(*p-'a');
		while(scanf("%s",p)==1){
			int pp=sam_find(p);
			printf("%d\n",pp);
			if(pp!=-1) puts(s+pp);
		}
	}
}