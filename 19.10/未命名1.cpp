#include<stdio.h>
int main(){
	int n,sum=1,i;
	for(;scanf("%d",&n)>0;sum=1){
	for (i=1;i<n;i++) sum=(sum+1)*2;
	printf("%d\n",sum);}}
