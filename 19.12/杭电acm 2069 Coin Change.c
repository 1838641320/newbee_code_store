#include<stdio.h>
int main() {
	int sum=0;
	while(~scanf("%d",&sum)){
		int a,b,c,i=0,a1=sum/50,b1=sum/25,c1=sum/10;
		for(a=0;a<=a1;a++)
			for(b=0;b<=b1;b++)
				for(c=0;c<=c1;c++){
					int t=(sum-50*a-25*b-10*c);
					if(t<0) break;
					if(t>=0) i+=t/5+1;
					if(a+b+c+t>97) i-=(a+b+c+t-97)/4;
					i=i<0?0:i;
				}
		printf("%d\n",i);
	}
}
