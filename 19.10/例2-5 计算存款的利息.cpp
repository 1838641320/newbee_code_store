#include<stdio.h>
#include<math.h>
int main(void)
{
	int money,year;
	double rate,sum;
	printf("�����Ǯ��");
	scanf("%d",&money);
	printf("�����������");
	scanf("%d",&year);
	printf("��������Ϣ");
	scanf("%lf",&rate);
	sum=money*pow(1+rate,year);
	printf("�ϼ�=%.3f\n",sum);
	return 0;
}
