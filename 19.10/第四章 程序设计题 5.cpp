#include<stdio.h>
int main(){
	int total,c5,c2,c1,count=0;
	printf("���м���Ǯ��");
	scanf("%d",&total);
	if (total<8||total>100) return 1;
	for(c5=1;c5<=(total/5+1);c5++)
		for (c2=1;c2<=(total/2+1);c2++)
		{c1=total-5*c5-2*c2;
			if (c1>=0) 
			{count++;
			printf("5��Ӳ�Ҹ�����%2d,2��Ӳ�Ҹ�����%2d,��Ӳ�Ҹ�����%2d\n",c5,c2,c1);}}
	printf("һ��%d�ֻ���\n",count);
return 0;}
