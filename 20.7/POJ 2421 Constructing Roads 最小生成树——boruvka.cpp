#include"s.h"
#include<cstdio>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=109;
int par[maxn],n,k,a[maxn][maxn];
int findp(int x){ return par[x]==x?x:par[x]=findp(par[x]); }
int boruvka(){
	int ans=0,dis[maxn],link[maxn];
	memset(link,-1,sizeof link);
	for(int fa,fb;;){
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++){
			fa=findp(i);
			for(int j=1;j<=n;j++){
				fb=findp(j);
				if(fa==fb) continue;
				if(dis[fa]>a[i][j]){
					link[fa]=fb;
					dis[fa]=a[i][j];
				}
			}
		}
		bool update=0;
		for(int i=1;i<=n;i++){
			if(dis[i]==0x3f3f3f3f) continue;
			fa=findp(i);fb=findp(link[i]);
			if(fa==fb) continue;
			ans+=dis[i];
			update=1;
			dis[i]=0x3f3f3f3f;
			par[fa]=fb;
		}
		if(update==0) break;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&a[i][j]);
	rep(i,0,n+2) par[i]=i;
	scanf("%d",&k);
	for(;k--;){
		int a,b;scanf("%d%d",&a,&b);
		a=findp(a),b=findp(b);
		par[a]=b;
	}
	printf("%d\n",boruvka());
}