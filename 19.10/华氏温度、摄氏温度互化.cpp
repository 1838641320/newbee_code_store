#include<stdio.h>
int main (void)
{
	double cel,fah;
	int choice;
	restart:
	printf("��֪�����¶�ת�����¶�����1\n��֪�����¶�ת�����¶�����2\n����������������\n");
	scanf("%d",&choice) ;
	if (choice==1)
	{
		printf("���϶�=");
		scanf("%lf",&fah) ;
		cel=5.0/9.0*(fah-32.0);
		printf("���϶�=%.3lf\n\n\n",cel);
	}
	else if(choice==2) {
		printf("���϶�=");
		scanf("%lf",&cel) ;
		fah=9.0/5.0*cel+32.0;
		printf("���϶�=%.3lf\n\n\n",fah);
	}
	else {goto end;}
	goto restart;
	end:
	return 0;
}
