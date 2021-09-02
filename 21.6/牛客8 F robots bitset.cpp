#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=5e2+9;
#include<queue>
struct bitset{
	static const int sz=3914;
	uint64_t ar[sz];
	void reset(){mem(ar,0);}
	void set(int a){ar[a>>6]|=1ull<<(a&63);}
	int test(int a){return ar[a>>6]>>(a&63)&1;}
	void operator|=(const bitset& rop){
		auto s=&ar[0],t=&ar[sz];
		auto i=&rop.ar[0];
		while(s!=t) (*s++)|=*i++;
	}
};
bitset sta[maxn];
int mp[maxn][maxn],n,m,line[maxn][maxn],col[maxn][maxn];
struct qrs{int x,y,in;};
vector<qrs> Qs[maxn][maxn];
int ans[1234567];
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) scanf("%1d",&mp[i+1][j+1]);
	rep(i,0,n) rep(j,0,m){
		line[i+1][j+1]=line[i+1][j]+mp[i+1][j+1];
	}
	rep(i,0,n) rep(j,0,m){
		col[i+1][j+1]=col[i][j+1]+mp[i+1][j+1];
	}
	int q;
	scanf("%d",&q);
	rep(i,0,q){
		int ty,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&ty,&x1,&y1,&x2,&y2);
		if(ty==1){
			ans[i]=(y1==y2&&x2>=x1&&col[x1][y1]==col[x2][y2]);
		}
		else if(ty==2){
			ans[i]=(x1==x2&&y2>=y1&&line[x1][y1]==line[x2][y2]);
		}
		else Qs[x1][y1].push_back({x2,y2,i});
	}
	for(int i=n;i>0;i--) for(int j=m;j>0;j--){
		if(mp[i][j]) sta[j].reset();
		else {
			sta[j].set((i-1)*m+j-1);
			sta[j]|=sta[j+1];
		}
// 		{
// 			printf("\n\n%d %d\n\n",i,j);
// 			rep(i,0,16) printf("%d",sta[j].test(i));
// 		}
		for(auto ii:Qs[i][j]){
			ans[ii.in]=sta[j].test((ii.x-1)*m+ii.y-1);
		}
	}
	rep(i,0,q) puts(ans[i]?"yes":"no");
}
int main(){
	// int t;scanf("%d",&t);
	// while(t--) 
		solve();
}