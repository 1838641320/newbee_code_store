#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//------------------------------------------------------
using namespace std;
const int maxn=1e5+9;
int n;
#include<queue>
void out(int x){
	printf("? %d\n",x);fflush(stdout);
}
int main(){
	read(n);
	int lb=0,ub=n+1,m1,m2,mid,r1,r2,res;
	double len;
	len=ub-lb;
	mid=lb+len/2;
	out(mid),read(res);
	while(ub-lb>8){
		len=ub-lb;
		m1=lb+len/4;
		out(m1),read(r1);
		if(r1<res) {
			ub=mid;
			mid=m1;
			res=r1;
			continue;
		}
		m2=mid+len/4;
		out(m2),read(r2);
		if(r2<res) {
			lb=mid;
			mid=m2;
			res=r2;
			continue;
		}
		if(r1>res&&r2>res){
			lb=m1,
			ub=m2;
			continue;
		}
	}
	int x=max(0,lb-3),y=1;
	vector<int> vec;
	for(int i=x;i<=min(x+12,n+1);i++) {
		if(i==0) {vec.push_back(9999999);continue;}
		if(i==n+1) {vec.push_back(9999999);continue;}
		out(i);read(y);
		vec.push_back(y);
	}
	for(int i=1;i<vec.size()-1;i++) if(vec[i]<min(vec[i-1],vec[i+1])) y=i;
	printf("! %d",y+x);fflush(stdout);
}