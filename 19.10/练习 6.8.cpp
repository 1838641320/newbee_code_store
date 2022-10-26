#include<stdio.h>
int reverse(int number);
double pow(int a,int b);
int number_length(int number);
int main()
{
	int x,y;
	printf("输入一个整数\n");
	scanf("%d",&x);
	y=reverse(x);
	printf("%d 的逆序数是:\n%d",x,y);
	return 0;
}
int reverse(int number)
{
	int j,k,i,k2=0;
	j=number_length(number);
	for (i=1;i<=j;i++)
	{
		k=(number%10);
		k2=k2+k*int(pow(10.0,(j-i)));
		number=number/10;
	}
return k2;
	
}
double pow(int a,int b)
{
	int i=1,temp_a=a;
	while (i<b)
	{
		a=temp_a*a;
		i++;
	}
	if (b==0) a=1;
	while (i>b)
	{
		a=1/a;
		i--;
	} 
	return a;
}
int number_length(int number)
{
	int i=0;
	while ((number%10)!=0)
	{
		i++;
		number=number/10;
	}
	return i;
 }
