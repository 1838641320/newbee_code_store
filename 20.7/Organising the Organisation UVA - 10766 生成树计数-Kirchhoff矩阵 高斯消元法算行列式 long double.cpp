#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long double LD;
const LD ep=1e-10;
const int maxn=59;
LD K[maxn][maxn];//Kirchhoff
bool A[maxn][maxn];
LD det(int n){
	LD res=1;
	rep(i,0,n){
		int p=i;
		rep(j,i+1,n)
			if(fabs(K[j][i])>fabs(K[p][i])) p=j;
		if(fabs(K[p][i])<ep) return 0;
		swap(K[p],K[i]);
		if(p!=i) res=-res;
		res*=K[i][i];
		rep(j,i+1,n) K[i][j]/=K[i][i];
		rep(j,0,n) if(j!=i)
			rep(k,i+1,n) K[j][k]-=K[j][i]*K[i][k];
	}
	return res;
}
int main(){
	int n,m,k,x,y;
	while(~scanf("%d%d%d",&n,&m,&k)){
		mem(A,0),mem(K,0);
		while(m--){
			scanf("%d%d",&x,&y);
			x--,y--;
			A[x][y]=A[y][x]=1;
		}
		rep(i,0,n) rep(j,0,n) if(i!=j&&A[i][j]==0)
			K[i][i]+=1,K[i][j]-=1;
		printf("%.Lf\n",fabs(det(n-1)));
	}
}