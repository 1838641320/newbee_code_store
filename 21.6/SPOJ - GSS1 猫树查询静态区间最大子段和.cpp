#include<iostream>
#include<algorithm>
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
using namespace std;
const int maxn=5e4;
int lg2(int x){return x?31-__builtin_clz(x):-1;}
int n;
int a[maxn*2],p[21][maxn*2],s[21][maxn*2];
void build(int d,int l,int r){
	if(d==0){return (void)(p[0][l]=s[0][l]=a[l]);}
	int mid=(l+r)>>1,sum=0,pre;
	pre=p[d][mid]=s[d][mid]=sum=a[mid];
	sum=max(0,sum);
	for(int i=mid-1;i>=l;i--){
		pre+=a[i],sum+=a[i];
		p[d][i]=max(p[d][i+1],sum);
		s[d][i]=max(s[d][i+1],pre);
		sum=max(0,sum);
	}
	pre=p[d][mid+1]=s[d][mid+1]=sum=a[mid+1];
	sum=max(0,sum);
	for(int i=mid+2;i<=r;i++){
		pre+=a[i],sum+=a[i];
		p[d][i]=max(p[d][i-1],sum);
		s[d][i]=max(s[d][i-1],pre);
		sum=max(sum,0);
	}
	build(d-1,l,mid);
	build(d-1,mid+1,r);
}
int query(int l,int r){
	if(l==r) return a[l];
	int dep=lg2((l-1)^(r-1))+1;
	return max(max(p[dep][l],p[dep][r]),s[dep][l]+s[dep][r]);
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	n=1<<(lg2(n)+1);
	build(lg2(n),1,n);
	int m;read(m);
	while(m--){
		int l,r;read(l,r);
		printf("%d\n",query(l,r));
	}
}