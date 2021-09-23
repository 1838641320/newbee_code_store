#include<iostream>
#include<algorithm>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
const int maxn=1e6+9;
struct P{double x,y;};
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};};
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};};
double operator*(P a,P b){return a.x*b.x+a.y*b.y;};
double operator^(P a,P b){return a.x*b.y-a.y*b.x;}
double len(const P&a){return hypot(a.x,a.y);}
//return positive if b on the left of ac else negtive
int side(P&a,P&b,P&c){return ((c-a)^(b-a))>=0;}
P rotate(P&a,double t){
	double c=cos(t),s=sin(t);
	return {a.x*c-a.y*s,a.x*s+a.y*c};
}
int st[maxn],top;
P b[maxn];
void tubao(P a[],int&n){//in counter clockwise
	for(int i=0;i<n;i++) b[i]=a[i];
	sort(b,b+n,[](P&a,P&b){
		return a.x<b.x||(a.x==b.x&&a.y<b.y);});
	st[++top]=0,st[++top]=1;
	for(int i=2;i<n;st[++top]=i++)//upper part
		while(top>1&&side(b[st[top-1]],b[st[top]],b[i]))
			top--;
	int tmp=top;
	st[++top]=n-1,st[++top]=n-2;
	for(int i=n-3;i>=0;st[++top]=i--)//lower part
		while(top>tmp&&side(b[st[top-1]],b[st[top]],b[i]))
			top--;
	n=top-1;for(int i=0;i<n;i++) a[i]=b[st[i+1]];
}
P a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n) scanf("%lf%lf",&a[i].x,&a[i].y);
	tubao(a,n);
	double ans=0;
	rep(i,1,n) ans+=len(a[i]-a[i-1]);
	printf("%.2lf",ans+len(a[0]-a[n-1]));
}