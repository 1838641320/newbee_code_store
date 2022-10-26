#include<stdio.h>
void wanshu(int n);
int main()
{  int top,j,floor;
   scanf("%d%d",&floor,&top);
	for (j=floor;j<=top;j++) wanshu(j);
    return 0;
}
void wanshu(int n){
	int i,s=1;
    for(i=2;i<=n/2;i++){
    if(n%i==0) s=s+i;}
    if(s==n){
        printf("%d=1",n);
         for(i=2;i<=n/2;i++)
            if(n%i==0)  printf("+%d",i);
         printf("\n");
     }}
