#include<stdio.h>
int main()
{	int i,a[10],*p;long sum; //������� 
	printf("Enter 5 integers\n");//������ʾ������ʮ������ 
	for (i=0;i<5;i++) scanf("%d",&a[i]);//��ʼ���� 
	for (i=0;i<5;i++) sum=sum+a[i];//����������� 
	printf("calculated by array, sum=%ld\n",sum);//�������������͵Ľ�� 
	sum=0;//�������ֵ 
	for (p=a;p<a+5;p++) sum=sum+*p;//����ָ����� 
	printf("calculated by pointer, sum=%ld\n",sum);//�������ָ����͵Ľ��
	return 0;} 
