#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 100005
typedef struct {
	int phone,num;
}ANS;
int save[maxn]={0};
char map[]={"22233344455566670778889990"};
ANS ans[maxn]={0};
int cmp(const void*a,const void*b) {return *(int*)a-*(int*)b;}
int main(){
	int n,j=0,j1=0,flag=0;
	scanf("%d",&n);
	getchar();
	while(n--){
		char in[90]={0};
		int each=0;
		gets(in);
		for(int i=0,t=strlen(in);i<t;i++){
			if(in[i]=='-'||in[i]=='Q'||in[i]=='Z'||in[i]==' ') continue;
			if(in[i]>='0'&&in[i]<='9') each=each*10+in[i]-'0';
			else if(in[i]>='A'&&in[i]<'Z') each=each*10+map[in[i]-'A']-'0';
		}
		save[j++]=each;
	}
	qsort(save,j,4,cmp);
	for(int i=0;i<j;i++){
		if(ans[j1].phone!=save[i]){
			ans[++j1].phone=save[i];
			ans[j1].num++;
		}
		else ans[j1].num++;
	}
	for(int i=0;i<=j1;i++) if(ans[i].num>1) {
		printf("%03d-%04d %d\n",ans[i].phone/10000,ans[i].phone%10000,ans[i].num);
		flag++;
	}
	if(!flag) puts("No duplicates.");
}
