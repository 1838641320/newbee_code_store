#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 1e-9
typedef struct{
	char name[30];
	double height;
}Building;
int cmp(const void *a,const void *b){
	return ((Building*)a)->height>((Building*)b)->height?1:-1;
}
int cmp2(const void *a,const void *b){
	if(fabs(*((double*)a)-((Building*)b)->height)<epsilon) return 0;
	return (*(double*)a)>((Building*)b)->height?1:-1;
}
int main(){
	Building building[10]={0},*find;
	int n,search;
	double jjj;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%s %lf",building[i].name,&building[i].height);
		qsort(building,n,sizeof(Building),cmp);
		for(int i=0;i<n;i++) printf("%s ",building[i].name);
		puts("");
		while(~scanf("%lf",&jjj)) 
			if(find=(Building*)bsearch(&jjj,building,n,sizeof(Building),cmp2))
				printf("%s\n",find->name);
			else puts("not found");
	}
}
/*test example
5
liujiao 1.2
sanjiao 1.3
shiijiao 3
sijiao 4
qijiao 1.2
1.2
2
*/
