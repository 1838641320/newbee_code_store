#include<stdio.h>
#include<string.h>
#define maxn 6666
unsigned char input[maxn+5]={0},search[maxn+5]={0};
int sunday(char *p,char *s){
	int place[300];
	memset(place,-1,sizeof(place));
	int l1=strlen(input),l2=strlen(search);
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
	return i<=end?i:-1;
}
int main() {
	scanf("%s%s",search,input);
	int place=sunday(input,search);
	printf("place:%d\n",place);
	if(~place) puts(input+place);
	else puts("not found");
	getchar();
}
