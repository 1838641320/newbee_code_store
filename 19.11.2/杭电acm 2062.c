#include<stdio.h>
long long sum(int n,int bit) {
	long long all=1,an=1;
	for (int i=n-bit; i>=1; i--) {
		an*=i;
		all+=an;
	}
	return all;
}
int main() {
	long long m,n,t;
	while(~scanf("%lld%lld",&n,&m)) {
		int k,first=1,i;
		int put[21]= {0},th[21]= {0};
		for(i=1; i<=n&&m>0; i++) {
			t=sum(n,i);
			th[i]=(m-1)/t+1;
			m-=t*(th[i]-1)+1;
		}
		int length=i;
		for(i=1; i<length; i++) {
			k=1;
			for(int j=0; j<th[i]; j++) {
				while(put[k]) k++;
				k++;
			}
			if(!first) printf(" ");
			printf("%d",--k);
			first=0;
			put[k]=1;
		}
		puts("");
	}
}
