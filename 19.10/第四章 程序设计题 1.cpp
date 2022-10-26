#include<stdio.h>
int main()
{	int sum=0,number=1;
	printf("输入多个正整数");
	while (number>0) 
	{scanf("%ld",&number);
		if (number%2==1) sum=sum+number;};
	printf("%ld",sum);
	return 0;}
