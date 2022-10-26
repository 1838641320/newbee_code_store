#include<stdio.h>
#include<math.h>
int main(void)
{
	int money,year;
	double rate,sum;
	printf("输入存钱数");
	scanf("%d",&money);
	printf("输入存入年数");
	scanf("%d",&year);
	printf("输入年利息");
	scanf("%lf",&rate);
	sum=money*pow(1+rate,year);
	printf("合计=%.3f\n",sum);
	return 0;
}
