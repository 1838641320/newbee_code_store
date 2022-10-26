#include<stdio.h>
#include<math.h>
int main(){
	long long i,j,n,sum1=0,sum2=0,in1,in2,M[200008]={0};
	scanf("%lld",&n);
	scanf("%lld",&in1);
	for(i=1;i<n;i++){
		scanf("%lld",&in2);
		M[i-1]=abs(in1-in2);
		in1=in2;
	}
	in1=in2=0;
	for(i=0;i<n-1;i++){
		in1+=M[i]*(i%2?-1:1);
		if(in1>sum1) sum1=in1;
		if(in1<=0) in1=0;
	}
	for(i=1;i<n-1;i++){
		in2+=M[i]*(i%2?1:-1);
		if(in2>sum2) sum2=in2;
		if(in2<=0) in2=0;
	}
	printf("%lld",sum1>sum2?sum1:sum2);
}

