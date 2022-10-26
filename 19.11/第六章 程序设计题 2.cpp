#include<stdio.h>
fn(int a,int n){
	int sum_=0,i;
	for (i=1;i<=n;i++){
	sum_+=a;
	a*=10;}
	return sum_;}
int main(){
	int a,sum=0,n,i;
	scanf("%d%d",&a,&n);
	for (i=1;i<=n;i++) sum+=fn(a,i);
	printf("%d\n",sum);}
