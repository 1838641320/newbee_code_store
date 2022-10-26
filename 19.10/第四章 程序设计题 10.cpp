#include<stdio.h>
int main(){
	int n,sum=1,i;
	printf("第几天早上剩一个桃子?\n");
	for(;scanf("%d",&n)>0;sum=1){
	for (i=1;i<n;i++) sum=(sum+1)*2;
	printf("%d\n",sum);}}
