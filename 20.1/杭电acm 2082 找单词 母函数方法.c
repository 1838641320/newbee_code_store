#include<stdio.h>
#include<string.h>
int main(int K){
	scanf("%d",&K);
	while(K--){
		int chr[28]={0},ans[54]={0},result=0,i,j,k;
		for(i=1;i<=26;i++) scanf("%d",&chr[i]);
		for(i=0;i<=chr[1];i++) ans[i]=1;
		for(i=2;i<=26;i++){
			int temp[54]={0};
			for(j=0;j<=chr[i];j++)
				for(k=0;k<=50&&k+j*i<=50;k++) temp[k+j*i]+=ans[k];
			memcpy(ans,temp,54*4);
		}
		for(i=1;i<=50;i++) result+=ans[i];
		printf("%d\n",result);
	}
}
