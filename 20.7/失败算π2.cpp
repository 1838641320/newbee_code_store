#include"s.h"
#include<cstdio>
typedef long double ld;
const ld one=1,two=2,three=3;
int main(){
	long double t=0L,sqrt3,lb=1.5L,ub=two,mid,q=0L;
	printf("%d\n\n",sizeof(long double));
	for(;q<900.0L;q+=one){
		mid=(lb+ub)/two;
		if(mid*mid<three){ lb=mid;continue; }
		if(mid*mid>three){ ub=mid;continue; }
	}
	sqrt3=one/mid;
	q=1;
	for(ld i=sqrt3,add=-1.0L/three;q<100.0L;q+=two){
		t+=i;
		printf("%.40LF\n",t*6.0L);
		i=i*add*q/(q+two);
	}
}