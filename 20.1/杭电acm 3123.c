#include<stdio.h>
#include<stdlib.h>
main(T){
	long long i,j,an,m,n,sum,ans;
	scanf("%d",&T);
	while(T--){
		char n1[120];
		scanf("%s %lld",n1,&m);
		n1[7]=0;
		n=atoi(n1);
		j=n>m?m-1:n;
		sum=an=i=1;ans=0;
		for(;i<=j&&ans!=sum;i++) {
			ans=sum;
			an=(an*i)%m;
			sum=(sum+an)%m;
		}
		printf("%lld\n",sum%m);
	}
}
