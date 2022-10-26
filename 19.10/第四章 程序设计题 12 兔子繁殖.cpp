#include<stdio.h>
#include<math.h>
int main()
{int month=1,kid1=1,kid2=0,sum=1,parents=0,n;
printf("请问您要几只兔子？\n");
scanf("%d",&n);
	printf("第%2d个月有%d只\n",month,sum);
while(sum<n){
	parents=kid2+parents;
	kid2=kid1;
	kid1=parents;
	sum=kid1+kid2+parents;
	month++;
	printf("第%2d个月有%d只\n",month,sum);}
printf("\n\n您要的兔子%d个月到货",month);
printf("\n");scanf("%d",&sum);//暂停程序 
return 0;}
