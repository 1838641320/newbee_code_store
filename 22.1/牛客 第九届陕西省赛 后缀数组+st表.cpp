#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
#include<cmath>
typedef long long ll;
const int maxn=2e5+9;
//sa[i]是第i小的后缀,rk[i]是下标i后缀是第几大
namespace SA{
int sa[maxn],rk[maxn];
int id[maxn],px[maxn],cnt[maxn],ork[maxn*2];//!! double !!
bool cmp(int x,int y,int w){
	return ork[x]==ork[y]&&ork[x+w]==ork[y+w];
}
void constuct(char s[],int m=256){//1-index,val range [1,m]
	int p=0,n=strlen(s+1);
	for(int i=1;i<=n;i++) cnt[rk[i]=s[i]]++;
	for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	for(int i=n;i>0;i--) sa[cnt[rk[i]]--]=i;
	for(int w=1;p<n;w<<=1,m=p){
		p=0;
		for(int i=n;i>n-w;i--) id[++p]=i;
		for(int i=1;i<=n;i++) if(sa[i]>w)
			id[++p]=sa[i]-w;
		for(int i=0;i<=m;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[px[i]=rk[id[i]]]++;
		for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>0;i--) sa[cnt[px[i]]--]=id[i];
		memcpy(ork,rk,sizeof(rk));
		p=0;
		for(int i=1;i<=n;i++)
			rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
	}
}
int ht[maxn];
void get_height(char s[],int sa[]=SA::sa){
	int i=1,k=0,n=strlen(s+1);
	for(;i<=n;i++){
		if(k) --k;
		for(int j=sa[rk[i]-1];s[i+k]==s[j+k];)k++;
		ht[rk[i]]=k;
	}
}
}
template<class ty,class cmp=std::less<ty>>
struct ST{
	vector<ty> st[22];
	ST(int n,ty a[]){
		for(int i=0;i<=log2(n);i++) 
			st[i].resize(n+1);
		for(int i=1;i<=n;i++) st[0][i]=a[i];
		for(int i=1;1<<i<=n;i++){
			for(int j=1;j+(1<<i)-1<=n;j++){
				st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))],cmp());
			}
		}
	}
	ty qr(int l,int r){
		if(l>r) return 1<<30;
		int x=log2(r-l+1);
		return min(st[x][l],st[x][r-(1<<x)+1],cmp());
	}
};
int n;
char s[maxn];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	SA::constuct(s);
	SA::get_height(s);
	ST<int> st(n,SA::ht);
	int q;
	scanf("%d",&q);
	while(q--){
		using namespace SA;
		int l,r;
		scanf("%d%d",&l,&r);
		int le=r-l+1;
		int lb=0,ub=rk[l];
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			if(st.qr(mid+1,rk[l])>=le)
				ub=mid;
			else lb=mid;
		}
		if(le+sa[ub]<=n){
			cout<<le+1<<' '<<s[sa[ub]+le]<<'\n';
			continue;
		}
		ub++;
		if(ub>n){
			cout<<0<<'\n';
			continue;
		}
		int res=st.qr(ub,ub);
		cout<<res+1<<' '<<s[sa[ub]+res]<<'\n';
	}
}
int main(){
	int t=1;
	// cin>>t;
	while(t--)
		solve();
}
