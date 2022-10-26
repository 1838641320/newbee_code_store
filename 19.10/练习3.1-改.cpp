#include<stdio.h>
int main()
{int a,b,c;
printf("Enter 3 integers\n");
scanf("%d%d%d",&a,&b,&c);
if (a<=b) a^=b^=a^=b;
if (a<=c) a^=c^=a^=c;
if (b<=c) c^=b^=c^=b;
printf("\n%d %d %d\n",c,b,a);
return 0;}
