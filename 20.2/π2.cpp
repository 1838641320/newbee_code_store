#include<cstdio>
typedef long double Ld;
int main(){
	Ld x=0.5,an=1,x1=0.25,s=0,i=1;
	for(;i<(Ld)90.0;i+=(Ld)2.0){
		s+=x;
		printf("%.40Lf\n",s*6);
		x*=x1*i*i/(i+1)/(i+2);
	}
}