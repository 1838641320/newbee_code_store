#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
#include<bitset>
using namespace std;
const int maxn=5e4+9;
bitset<maxn> da[7][233],ans;
int ar[7][maxn],bsz,blo[maxn];
struct haar{
	int x,i;
	bool operator<(const haar&a)const{return x<a.x;}
}ha[7][maxn];
int n,k;
void pre(){
	rep(i,0,k) {
		sort(ha[i],ha[i]+n);
		for(int j=1;j*bsz<n;j++){
			int p=min(j*bsz,n);
			da[i][j]=da[i][j-1];
			for(int u=(j-1)*bsz;u<p;u++)
				da[i][j].set(ha[i][u].i);
		}
	}
}
auto get(int di,int pos){
	pos=lower_bound(ha[di],ha[di]+n,(haar){ar[di][pos],0})-ha[di];
	auto ret=da[di][blo[pos]];
	for(int i=blo[pos]*bsz;i<pos;i++)
		ret.set(ha[di][i].i);
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	bsz=sqrt(n);
	rep(i,0,n){
		blo[i]=i/bsz;
		rep(j,0,k) {
			scanf("%d",&ar[j][i]);
			ha[j][i]={ar[j][i],i};
		}
		ar[k][i]=i;
		ha[k][i]={ar[k][i],i};
	}
	k++;
	pre();
	rep(i,0,n){
		ans.set();
		rep(j,0,k) ans&=get(j,i);
		printf("%d\n",ans.count());
	}
}