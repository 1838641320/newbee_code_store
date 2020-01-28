#include<cstdio>
int main() {
	int T,N,a,i,j;
	scanf("%d",&T);
	for (a=1;a<=T;a++) {
		scanf("%d%*c",&N);
		int s[9]={0},ans=0,p;
		for (i=0;i<N;getchar(),i++) for (j=0;j<N;j++) if (getchar()=='1') s[i]=j;
		for (i=0;i<N;i++) if(s[i]>i){
			p=-1;
			for (j=i+1;j<N;j++) if (s[j]<=i) {p=j;break;}
			ans+=p-i;
			for (j=p;j>i;j--) s[j-1]^=s[j]^=s[j-1]^=s[j];
		}
		printf("Case #%d: %d\n",a,ans);
	}
}