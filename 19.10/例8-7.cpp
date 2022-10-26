#include<stdio.h>
int main()
{	int i,a[10],*p;long sum; //定义变量 
	printf("Enter 5 integers\n");//输入提示：输入十个整数 
	for (i=0;i<5;i++) scanf("%d",&a[i]);//开始输入 
	for (i=0;i<5;i++) sum=sum+a[i];//利用数组求和 
	printf("calculated by array, sum=%ld\n",sum);//输出利用数组求和的结果 
	sum=0;//重置求和值 
	for (p=a;p<a+5;p++) sum=sum+*p;//利用指针求和 
	printf("calculated by pointer, sum=%ld\n",sum);//输出利用指针求和的结果
	return 0;} 
