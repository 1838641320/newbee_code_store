#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n;
	char words[109][80]={0},ans[80]={0};
	while(gets(words[n++]));
	qsort(words,n-1,80,strcmp);
	for(int i=0;words[0][i]==words[n-2][i];i++) 
		ans[i]=words[0][i];
	puts(ans);
}
