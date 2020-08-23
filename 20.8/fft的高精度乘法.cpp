#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using com=complex<double>;
const double pi=acos(-1);
const int maxn=5e5+9;
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
char inbuf[99999];
stack<char> outbuf;
int main(){
	for(int i=1;i<maxn;i*=2) Cos[i]=cos(pi/i);
	for(int i=1;i<maxn;i*=2) Sin[i]=sin(pi/i);
	scanf("%s",inbuf);
	for(n=0;sscanf(inbuf+n,"%1d",a+n)==1;n++);
	reverse(a,a+n);
	scanf("%s",inbuf);
	for(m=0;sscanf(inbuf+m,"%1d",b+m)==1;m++);
	reverse(b,b+m);
	poly_mul(n,m,a,b);
	for(int i=0,carry=0;;i++){
		a[i]+=carry;
		carry=a[i]/10;
		a[i]-=carry*10;
		if(!carry&&!a[i]) break;
		(a[i]<0||a[i]>9)&&printf("%d %d\n",i,a[i]);
		outbuf.push('0'+a[i]);
	}
	while(outbuf.size()) putchar(outbuf.top()),outbuf.pop();
	puts("");
}