#include<stdio.h>
int main(){
	int N,M,a,b,c,i;
	while(~scanf("%d%d%d%d%d",&N,&M,&a,&b,&c)){
		for(i=0;i<N*M;i++) {
			int weight;
			scanf("%d",&weight);
			if((weight>=a)&&(weight<=b)) weight=c;
			if((i+1)%M==0) printf("%04d\n",weight);
			else printf("%04d ",weight);
		}
	}
}
