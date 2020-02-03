#include<cstdio>
#include<cmath>
constexpr auto MAX_N=10,ST_SIZE=1<<6-1;
constexpr auto PI=3.14159265358979323846L;
int N,C,L[MAX_N],S[MAX_N],A[MAX_N];
double vx[ST_SIZE],vy[ST_SIZE],ang[ST_SIZE],prv[ST_SIZE];
void init(int k,int l,int r){
	ang[k]=vx[k]=0.0;
	if(r==l+1) vy[k]=L[l];
	else{
		int chl=2*k+1,chr=2*k+2;
		init(chl,l,(l+r)/2);
		init(chr,(l+r)/2,r);
		vy[k]=vy[chl]+vy[chr];
	}
}
void change(int s,double a,int v,int l,int r){
	if(s<=l||s>=r) return;
	int chl=v*2+1,chr=v*2+2,mid=(l+r)/2;
	change(s,a,chl,l,mid);
	change(s,a,chr,mid,r);
	if(s<=mid) ang[v]+=a;
	double si=sin(ang[v]),co=cos(ang[v]);
	vx[v]=vx[chl]+(co*vx[chr]-si*vy[chr]);
	vy[v]=vy[chl]+(si*vx[chr]+co*vy[chr]);
}
void solve(){
	int i;
	init(0,0,N);
	for(i=1;i<N;i++) prv[i]=PI;
	for(i=0;i<C;i++){
		int s=S[i];
		double a=A[i]/360.0*2*PI;
		change(s,a-prv[s],0,0,N);
		prv[s]=a;
		printf("%.2lf %.2lf\n",vx[0],vy[0]);
	}
}
int main(){
	N=3;C=3;
	L[0]=L[1]=L[2]=5;
	S[0]=1;S[1]=2;S[2]=1;
	A[0]=270;A[1]=90;A[2]=90;
	solve();
}