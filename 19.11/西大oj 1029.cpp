#include<stdio.h>
int main(){
	long long k,n,sum,i;
	while(scanf("%lld",&n)!=-1){
	for (k=0;;k++) {
		sum=k;
		for (i=1;i<k;i++) {
			sum*=k;
			if (sum>n) break;}
		if (sum>n) break;	
		} 
	printf("%lld\n",k-1);}
}
