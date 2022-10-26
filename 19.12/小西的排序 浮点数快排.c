#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char name[30];
	double height;
}Building;
int cmp(const void *a,const void *b){
	return ((Building*)a)->height>((Building*)b)->height?1:-1;
}
int main(){
	Building building[10];
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%s %lf",building[i].name,&building[i].height);
		qsort(building,n,sizeof(Building),cmp);
		for(int i=0;i<n;i++) printf("%s ",building[i].name);
		puts("");
	}
}

