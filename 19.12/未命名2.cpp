#include <stdio.h>
#include <math.h>
int main()
{
	int a[100], i, n, sum, ave, flag=0;
	while(~scanf("%d",&n)&&n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(flag)printf("\n");
		ave=sum/n;sum=0;
		for(i=0;i<n;i++)
		{
			sum+=fabs(ave-a[i]);
		}
		printf("%d\n",sum/2);
		flag++;
	} 
	return 0;
}
