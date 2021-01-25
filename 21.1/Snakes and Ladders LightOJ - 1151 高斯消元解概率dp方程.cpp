#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const int maxn=1e2+9;
const double ppf=1.0/6;
double p[maxn][maxn]={};
int go[maxn]={};
void gause(double a[maxn][maxn]){
	int pi,i,j,k;
	for(i=1;i<=100;i++){
		pi=i;
		for(j=i;j<=100;j++) 
			if(fabs(a[j][i])>fabs(a[pi][i])) pi=j;
		swap(a[i],a[pi]);
		double t=a[i][i];
		for(j=i;j<=101;j++) a[i][j]/=t;
		for(j=1;j<=100;j++)if(i!=j)
			for(k=i,t=a[j][i];k<=101;k++) 
				a[j][k]-=t*a[i][k];
	}
}
void solve(){
	for(int i=1;i<=108;i++) go[i]=i;
	mem(p,0);
	int n,a,b;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&a,&b);
		go[a]=b;
	}
	for(int i=1;i<100;i++){
		int t=min(6,100-i);
		p[i][i]=t;
		p[i][101]=6;
		for(int j=1;j<=t;j++) p[i][go[i+j]]-=1;
	}
	p[100][101]=0,p[100][100]=1;
	gause(p);
	printf("%.10lf\n",p[1][101]);
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) 
		printf("Case %d: ",i),solve();
}