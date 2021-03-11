#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
using namespace std;
#include<vector>
const int maxn=2e5+9;
typedef pair<double,double> pdd;
bool cmp(const pdd&a,const pdd&b){
	return a.second<b.second;
}
pdd ps[maxn]={};
double closest_pair(pdd ps[],int n){
	if(n<=1) return 1e99;
	int m=n/2;
	double xc=ps[m].first;
	double di=min(closest_pair(ps,m),closest_pair(ps+m,n-m));
	inplace_merge(ps,ps+m,ps+n,cmp);//y ascend
	vector<pdd> vec;
	for(int i=0;i<n;i++){
		if(fabs(ps[i].first-xc)>=di) continue;
		for(int j=vec.size()-1;j>=0;j--){
			double dx=ps[i].first-vec[j].first,dy=ps[i].second-vec[j].second;
			if(dy>=di) break;
			di=min(di,hypot(dx,dy));
		}
		vec.push_back(ps[i]);
	}
	return di;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n) scanf("%lf%lf",&ps[i].first,&ps[i].second);
	sort(ps,ps+n);
	printf("%.4lf",closest_pair(ps,n));
}