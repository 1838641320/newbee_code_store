#include<bits/stdc++.h>
typedef long long ll;
const int maxn=2e7+9;
void z_function(const char s[],int z[]){
	int l=0,r=0,n=strlen(s);
	for(int i=1;i<n;i++){
		if(i<=r) z[i]=std::min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if(i+z[i]>r+1) l=i,r=i+z[i]-1;
	}
}
int res[maxn*2];
char a[maxn],b[maxn*2];
int main(){
	scanf("%s%s",a,b);
	int sa=strlen(a),sb=strlen(b);
	b[sb++]=1;
	strcpy(b+sb,a);
	z_function(b,res);
	printf("%lld\n%lld\n",[=]()->ll{ll ans1=sb;for(int i=1;i<sb-1;i++) ans1^=(i+1ll)*(res[i]+1ll);return ans1;}(),[=]()->ll{ll ans2=0;for(int i=sb;i<sa+sb;i++) ans2^=(i-sb*1ll+1)*(res[i]+1ll);return ans2;}());
}