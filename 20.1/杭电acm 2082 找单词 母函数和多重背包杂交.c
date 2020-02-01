#include<stdio.h>
int main(int K){
	scanf("%d",&K);
	while(K--){
		int chr[28]={0},ans[54][28]={0},res=0,i,j,k;
		for(i=1;i<=26;i++) scanf("%d",&chr[i]);
		ans[0][0]=1;
		for(i=1;i<=26;i++)for(j=0;j<=chr[i];j++)for(k=0;k<=50&&k+j*i<=50;k++)
			ans[k+j*i][i]+=ans[k][i-1];
		for(i=1;i<=50;i++) res+=ans[i][26];
		printf("%d\n",res);
	}
}
