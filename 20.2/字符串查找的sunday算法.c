#include<stdio.h>
#include<string.h>
#define maxn 6666
int place[300]={0};
unsigned char input[maxn+5]={0},search[maxn+5]={0},*res;
int main() {
	fgets(input,maxn,stdin);
	fgets(search,maxn,stdin);
	int l1=strlen(input)-1,l2=strlen(search)-1;
	memset(place,-1,sizeof(place));
	for(int i=0;i<l2;i++) 
		place[search[i]]=i;
	int i=0,end=l1-l2;
	while(i<end){
		int j=0;
		for(;j<l2;j++) 
			if(input[i+j]!=search[j]) break;
		if(j==l2) break;
		else i+=l2-place[input[l2+i]];
	}
	if(i<end){
		printf("place:%d\n",i);
		puts(input+i);
	}
	else puts("not found");
	getchar();
}
