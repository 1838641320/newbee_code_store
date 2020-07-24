#include"s.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
int n,m;
std::vector<int> g[1009],linky[509];
bool vis[509];
int dfs(int x,int num){
	rep(i,0,g[x].size()){
		int y=g[x][i];
		if(vis[y]) continue;vis[y]=1;
		if(linky[y].size()<num) 
			return linky[y].push_back(x),1;
		rep(j,0,num)
			if(dfs(linky[y][j],num))
				return linky[y][j]=x,1;
	}
	return 0;
}
int judge(int mid){
	rep(y,0,m) linky[y].clear();
	rep(x,0,n){
		memset(vis,0,sizeof vis);
		if(!dfs(x,mid)) return 0;
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&m),n|m){
		rep(i,0,n){
			g[i].clear();
			char in[2048]={},*p=in;
			for(scanf("%*s"),fgets(p,2048,stdin);
				*p!='\n';)
				g[i].push_back(strtol(p,&p,10));
		}
		int ub=1001,lb=0;
		while(ub>lb+1){
			int mid=(ub+lb)/2;
			if(judge(mid)) ub=mid;
			else lb=mid;
		}
		printf("%d\n",ub);
	}
}