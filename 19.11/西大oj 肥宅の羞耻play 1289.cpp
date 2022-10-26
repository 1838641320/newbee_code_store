#include<stdio.h>
int main() {
	int T,n,q,i,j,weight[1024],w,count;
	scanf("%d",&T);
	for (i=0; i<T; i++) {
		scanf("%d",&n);
		for (j=0; j<n; j++) scanf("%d",&weight[j]);
		scanf("%d",&q);
		for (j=0; j<q; j++) {
			count=0;
			scanf("%d",&w);
			for(int i1=0; i1<n; i1++) if(weight[i1]==w) count++;
			if(j<q-1) printf("%d ",count);
			else printf("%d\n",count);
		}
	}
}
