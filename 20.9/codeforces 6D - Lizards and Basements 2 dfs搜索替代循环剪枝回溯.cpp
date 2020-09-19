#include<cstdio>
#include<cstdlib>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=509;
int n,a,b,h[18]={},res[18]={},real[18]={},ans=99999;
void dfs(int x,int times){
	if(times>ans) return;
	if(x==n-1){
		if(h[x]<0) 
			ans=__min(ans,times),
			memcpy(real,res,sizeof res);
		return;
	}
	int t=__max(h[x-1]/b,__max(h[x]/a,h[x+1]/b))+1;
	int s=h[x-1]<0?0:h[x-1]/b+1;
	for(int i=s;i<=t;i++){
		res[x]=i;
		h[x-1]-=i*b,h[x]-=i*a,h[x+1]-=i*b;
		dfs(x+1,times+i);
		h[x-1]+=i*b,h[x]+=i*a,h[x+1]+=i*b;
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	rep(i,0,n) scanf("%d",h+i);
	dfs(1,0);
	printf("%d\n",ans);
	rep(i,1,n) rep(j,0,real[i]) printf("%d ",i+1);
}