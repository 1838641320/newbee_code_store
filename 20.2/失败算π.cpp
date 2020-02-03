#include<cstdio>
typedef long double ld;
int main(){
	long double t=0,sqrt3,lb=1.5,ub=2,mid,q=0;
	printf("%d\n\n",sizeof(long double));
	for(;q<900;q+=1){
		mid=(lb+ub)/(ld)2;
		if(mid*mid<(ld)3){ lb=mid;continue;}
		if(mid*mid>(ld)3){ ub=mid;continue ;}
	}
	sqrt3=((ld)1)/mid;
	q=1;
	for(ld i=sqrt3,add=((ld)-1)/((ld)3);q<100;q+=2){
		t+=i;
		printf("%.40LF\n",t*6);
		i=i*add*q/(q+(ld)2);
	}
}