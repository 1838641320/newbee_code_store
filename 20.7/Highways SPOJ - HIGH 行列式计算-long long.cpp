#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=19;
ll mat[maxn][maxn];
ll det(int n){
	ll res=1;
	rep(i,0,n){
		rep(j,i+1,n){
			while(mat[j][i]){
				ll t=mat[i][i]/mat[j][i];
				rep(k,i,n) mat[i][k]-=t*mat[j][k];
				swap(mat[i],mat[j]);
				res=-res;
			}
		}
		res*=mat[i][i];
	}
	return res;
}
void solve(){
	memset(mat,0,sizeof mat);
	int n,m,f,t;scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&f,&t);
		f--;t--;
		mat[f][f]++,mat[t][t]++;
		mat[f][t]--;mat[t][f]--;
	}
	printf("%lld\n",abs(det(n-1)));
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}