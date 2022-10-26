#include<stdio.h>
int main (void)
{
	double cel,fah;
	int choice;
	restart:
	printf("已知华氏温度转摄氏温度输入1\n已知摄氏温度转华氏温度输入2\n结束程序输入其他\n");
	scanf("%d",&choice) ;
	if (choice==1)
	{
		printf("华氏度=");
		scanf("%lf",&fah) ;
		cel=5.0/9.0*(fah-32.0);
		printf("摄氏度=%.3lf\n\n\n",cel);
	}
	else if(choice==2) {
		printf("摄氏度=");
		scanf("%lf",&cel) ;
		fah=9.0/5.0*cel+32.0;
		printf("华氏度=%.3lf\n\n\n",fah);
	}
	else {goto end;}
	goto restart;
	end:
	return 0;
}
