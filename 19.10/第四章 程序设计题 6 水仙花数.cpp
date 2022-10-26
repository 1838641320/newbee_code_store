#include<stdio.h>
#include<math.h>
int main()
{int n,i,digit,bit_result,sum,temp;
printf("输入要求的水仙花数的位数(小于8)\n");
scanf("%d",&n);
for(i=pow(10,n-1);i<pow(10,n);i++)
	{sum=0;
	temp=i;
	for(digit=0;digit<n;digit++){
		bit_result=temp%10;
		temp=temp/10;
		sum=sum+pow(bit_result,n);}
	if (sum==i) printf("\n%d",i);}
return i;}
