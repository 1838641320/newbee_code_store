#include<stdio.h>
#include<math.h>
#define all for(j=0;j<N;j++)
#define reset count=-1,sum=0
#define no else printf("N ")
#define yes if(count>-1)
#define mod(x) if (array[j]%5==x)
int main() {
	int T,N,i,j;
	scanf("%d",&T);
	for (i=0; i<T; i++) {
		int array[1024]={0};
		double reset;
		scanf("%d",&N);
		all scanf("%d",&array[j]);
		all {
			if (array[j]%10==0) {
			sum+=array[j];
			count++;
			}
		}
		yes printf("%.lf ",sum);
		no;reset;
		all {
			mod(1) {
				count++;
				sum+=array[j]*pow(-1,count);
			}
		}
		yes printf("%.lf ",sum);
		no;reset;
		all {
			mod(2) count++;
		}
		yes printf("%.lf ",count+1);
		no;reset;
		all {
			mod(3) {
				count++;
				sum+=array[j];
			}
		}
		yes printf("%.1lf ",sum/(count+1));
		no;reset;
		sum=-1E99;
		all {
			mod(4) {
				count++;
				if(sum<array[j]) sum=array[j];
			}
		}
		yes printf("%.lf\n",sum);
		else printf("N\n");
	}
}
