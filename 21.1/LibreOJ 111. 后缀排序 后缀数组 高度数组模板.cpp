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
const int maxn=1e6+9;
int n;
char s[maxn];
int sa[maxn],rk[maxn],oldrk[maxn<<1];
int id[maxn],px[maxn],cnt[maxn];
void construct_sa(char s[]){
	int m=256,p;//value range
	auto cmp=[&](int x,int y,int w){
		return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
	};
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
			rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
	}
}
int ht[maxn];
void construct_height(char s[],int sa[]){
	for(int i=1,k=0;i<=n;i++){
		if(k) --k;
		for(int j=sa[rk[i]-1];s[i+k]==s[j+k];)k++;
		ht[rk[i]]=k;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	construct_sa(s);
	for(int i=1;i<=n;i++) printf("%d ",sa[i]);
	// puts("");
	// construct_height(s,sa);
	// for(int i=1;i<=n;i++) printf("%d ",ht[i]);
}