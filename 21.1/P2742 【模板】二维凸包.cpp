#include<iostream>
#include<algorithm>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
const int maxn=1e6+9;
//---------------------------------------
struct P{double x,y;};
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};};
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};};
double operator*(P a,P b){return a.x*b.y-a.y*b.x;}
double operator^(P a,P b){return a.x*b.x+a.y*b.y;};
int st[maxn],top;
void tubao(P a[],int&n){
	P b[n];rep(i,0,n) b[i]=a[i];
	sort(b,b+n,[](P&a,P&b){return a.y<b.y||(a.y==b.y&&a.x<b.x);});
	for(int i=n-1;i>=0;i--) 
		b[i].x-=b[0].x,b[i].y-=b[0].y;
	sort(b,b+n,[](P&a,P&b){return 
		a*b>0||(a*b==0&&hypot(a.x,a.y)<hypot(b.x,b.y));});
	top=0;
	for(int i=0;i<n;st[top++]=i++){
		while(top>=2&&(b[i]-b[st[top-1]])*(b[st[top-1]]-b[st[top-2]])>=0)
			top--;
	}
	n=top;rep(i,0,top) a[i]=b[st[i]];
}
//---------------------------------------
P a[maxn];
int n;
int main(){
	scanf("%d",&n);
	rep(i,0,n) scanf("%lf%lf",&a[i].x,&a[i].y);
	tubao(a,n);
	double ans=0;
	rep(i,1,n) ans+=hypot(a[i].x-a[i-1].x,a[i].y-a[i-1].y);
	printf("%.2lf",ans+hypot(a[0].x-a[n-1].x,a[0].y-a[n-1].y));
}
/*
a1,a2,b1,b2为两条直线的两个端点
如果满足(b1−a1)×(b1−a2)和(b2−a1)×(b2−a2)不同号，并且(a1−b1)×(a1−b2)和(a2−b1)×(a2−b2)不同号，则两线段相交，叫跨立实验。
点积
a.x×b.x+a.y×b.y
叉积
a.x×b.y−a.y×b.x
*/
