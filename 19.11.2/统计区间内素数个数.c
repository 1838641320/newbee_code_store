#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int prime_generate(int n,int *prime) {
	int *j=malloc(4*n),p=0;
	memset(j,0,4*n);
	memset(prime,0,4*n);
	j[0]=j[1]=1;
	for(int i=2; i<n; ++i) {
		if(!j[i])
			prime[p++]=i;
		for(int i1=0; i*prime[i1]<n&&i1<p; i1++) {
			j[i*prime[i1]]=1;
			if(!i%prime[i1])
				break;
		}
	}
	return p;
}
int main() {
	int n,L,R;
	while(~scanf("%d%d",&L,&R)) {
		n=sqrt(R)+2;
		int *prime=malloc(4*n),p=prime_generate(n,prime),count=0,yes;
		for(int i=L; i<=R; i++) {
			yes=1;
			for(int j=0; j<p&&prime[j]<=sqrt(i); j++)
				if(i%prime[j]==0) {
					yes=0;
					break;
				}
			if(yes&&i!=1) count++;
		}
		printf("%d\n",count);
	}
}
