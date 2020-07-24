#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int maxn=59;
ll K[maxn][maxn];
bool a[maxn][maxn];
ll det(int n,ll mat[maxn][maxn]){
	int i,j,k;
	ll res=1;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			while(mat[j][i]){
				ll t=mat[i][i]/mat[j][i];
				for(k=i;k<n;k++) mat[i][k]-=t*mat[j][k];
				swap(mat[i],mat[j]);
				res=-res;
			}
		}
		res*=mat[i][i];
	}
	return res;
}
int main(){
	int n,m,k,x,y;
	while(~scanf("%d%d%d",&n,&m,&k)){
		mem(a,0),mem(K,0);
		while(m--){
			scanf("%d%d",&x,&y);
			x--,y--;
			a[x][y]=a[y][x]=1;
		}
		rep(i,0,n) rep(j,0,n){
			if(a[i][j]==0&&i!=j)
				K[i][i]++,K[i][j]--;
		}
		printf("%lld\n",abs(det(n-1,K)));
	}
}
