#include<stdio.h>
#include<math.h>
int prime(int n){int i;
	if (n==1) return 1;
	for(i=2;i<sqrt(n);i++) if(n%i==0) return 0;
	return 1;
}
int main(){
	int a1,i;
	for(i=6;i<=100;i=i+2){
		for(a1=3;a1<=(i/2);a1=a1+2){
			if ((prime(a1))&&(prime(i-a1))){
				printf("%d=%d+%d, ",i,a1,i-a1);
				if((((i-4)/2)%5==0)&&((i-6)!=0)) printf("\n");
			break;}}}
	printf("\n");}
