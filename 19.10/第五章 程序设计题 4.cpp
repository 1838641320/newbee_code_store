#include<stdio.h>
#include<math.h>
int prime(int m);
int main(){
	int m,n,i,count=0,sum=0;
	printf("分别输入计算的下限和上限\n");
	scanf("%d%d",&m,&n);
	for (i=m;i<=n;i++){
		if (prime(i)) {
			count++;sum=sum+i;
			printf("%6d",i);
			if (count%5==0) printf("\n");}}
	printf("\n\n素数的总数是%d\n素数的总和是%d\n",count,sum);
	return 0;}

int prime(int m){
	int j,q;
	if (m==1) return 0;
	q=sqrt(m);
	for (j=2;j<=q;j++){
	if (m%j==0) 
		return 0;}
return 1;}
