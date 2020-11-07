#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
#include<random>
#include<ctime>
using namespace std;
mt19937 rd(time(0));
const int maxn=1e2+9;
int a[maxn][maxn]={},dif[maxn][maxn];
int b[maxn],c[maxn];
int main(){
	int n=20;
	for(int i=1;i<=n;i++) b[i]=rd()%9000,c[i]=b[i]-b[i-1],printf("%d ",b[i]);
	puts("");
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	puts("");
	for(int i=1;i<=n;i++) printf("%d ",c[i]+=c[i-1]);
	puts("");
	for(int i=1;i<=n;i++) c[i]=b[i]-b[i-1];
	for(int i=1;i<=n;i++) c[i]+=b[i-1];
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	puts("");
	puts("\n-----------\n\n");
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		a[i][j]=rd()%9000;
		dif[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
	}
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=n;j++) 
		printf("%d ",a[i][j]);
	puts("");
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=n;j++) 
		printf("%d ",dif[i][j]);
	puts("");
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		dif[i][j]+=dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
	}
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=n;j++) 
		printf("%d ",dif[i][j]);
	puts("");
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dif[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dif[i][j]+=dif[i][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dif[i][j]+=dif[i-1][j];
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=n;j++) 
		printf("%d ",dif[i][j]);
	puts("");
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dif[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dif[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=n;j++) 
		printf("%d ",dif[i][j]);
}