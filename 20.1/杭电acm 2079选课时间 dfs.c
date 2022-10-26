#include<stdio.h>
#include<string.h>
int T,n,k,a[10],x,y,total;
void dfs(int sum,int i){
	if(sum==n) total++;
	if(sum>=n||a[i-1]==0) return;
	for(int k=0;k<=a[i];k++)
		dfs(sum+i*k,i+1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		total=0;
		scanf("%d%d",&n,&k);
		memset(a,0,40);
		a[0]=0x7f;
		for(int i=0;i<k;i++) {
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		dfs(0,1);
		printf("%d\n",total);		
	}
}
