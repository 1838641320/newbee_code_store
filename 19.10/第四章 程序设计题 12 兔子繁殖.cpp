#include<stdio.h>
#include<math.h>
int main()
{int month=1,kid1=1,kid2=0,sum=1,parents=0,n;
printf("������Ҫ��ֻ���ӣ�\n");
scanf("%d",&n);
	printf("��%2d������%dֻ\n",month,sum);
while(sum<n){
	parents=kid2+parents;
	kid2=kid1;
	kid1=parents;
	sum=kid1+kid2+parents;
	month++;
	printf("��%2d������%dֻ\n",month,sum);}
printf("\n\n��Ҫ������%d���µ���",month);
printf("\n");scanf("%d",&sum);//��ͣ���� 
return 0;}
