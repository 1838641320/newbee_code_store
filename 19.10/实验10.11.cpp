#include<stdio.h>
char get_grade(int n);
int main()
{
	int sum,eng_points,math_points,sheji_points;
	char ga,gb,gc;
	double avg;
	printf("����Ӣ�������������Ƶĳɼ�(�ո�ֿ�)\n");
	scanf("%d%d%d",&eng_points,&math_points,&sheji_points);
	ga=get_grade(eng_points);gb=get_grade(math_points);gc=get_grade(sheji_points);
	if (ga=='q'||gb=='q'||gc=='q')
	printf("ERROR\n") ;
	else
	{sum=eng_points+math_points+sheji_points;
	avg=sum/3.0;
	printf("\n�ܳɼ�:%d\nƽ����:%.2lf\n",sum,avg) ;
	printf("Ӣ��ȼ�:%5.c\n�����ȼ�:%5.c\n������Ƶȼ�:%c\n",ga,gb,gc);}
}
char get_grade(int n){
	char grade;
	if (n>0&n<100)
	if (n<60) grade='E';
	else if (n<70) grade='D';
	else if (n<80) grade='C';
	else if (n<90) grade='B';
	else grade='A';
	else grade='q';
	return grade;}
