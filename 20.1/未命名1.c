#include<stdio.h>
#include<math.h>
typedef long long ll;
ll save[30]={0},ans[30]={0},T,n,i=1;
int main(){
	for(;i<26;i++){
		save[i]=ans[i-1]+save[i-1];
		ans[i]=save[i]+(ll)pow(2,i-1);
	}
	for(scanf("%lld",&T);T--;printf("%lld\n",ans[n])) scanf("%lld",&n);
}
