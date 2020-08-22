#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using com=complex<double>;
const double pi=acos(-1);
const int maxn=5e6+9;
double Cos[maxn]={},Sin[maxn]={};
void fft(int num,com *a,int ty){
	if(num==1) return;
	int mid=num/2;
	com a1[mid],a2[mid];
	for(int i=0;i<num;i+=2)
		a1[i/2]=a[i],a2[i/2]=a[i+1];
	fft(mid,a1,ty),fft(mid,a2,ty);
	com Wn(Cos[mid],ty*Sin[mid]),w(1,0);
	for(int i=0;i<mid;i++,w*=Wn)
		a[i]=a1[i]+w*a2[i],
		a[i+mid]=a1[i]-w*a2[i];
}
com A[maxn]={},B[maxn]={};
void poly_mul(int n,int m,int *a,int *b){
	int num=1;
	while(num<=n+m) num*=2;
	for(int i=0;i<=num;i++)
		A[i].real(a[i]),B[i].real(b[i]);
	fft(num,A,1),fft(num,B,1);
	for(int i=0;i<=num;i++)
		A[i]*=B[i];
	fft(num,A,-1);
	rep(i,0,num) a[i]=A[i].real()/num+0.5;
}
int a[maxn]={},b[maxn]={},n,m;
int main(){
	for(int i=1;i<maxn;i*=2) Cos[i]=cos(pi/i);
	for(int i=1;i<maxn;i*=2) Sin[i]=sin(pi/i);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) scanf("%d",a+i);
	for(int i=0;i<=m;i++) scanf("%d",b+i);
	poly_mul(n,m,a,b);
	for(int i=0;i<=n+m;i++) printf("%d ",a[i]);
}