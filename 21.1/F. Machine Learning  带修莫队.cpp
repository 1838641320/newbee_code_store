#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
using namespace std;
const int maxn=1e5+9,bck=2155;
struct OPE{int l,r,t,in;}query[maxn];
int opp[maxn],lv[maxn],rv[maxn];
int cmp(const OPE&a,const OPE&b){
	if(a.l/bck!=b.l/bck) return a.l/bck<b.l/bck;
	if(a.r/bck!=b.r/bck) return a.r/bck<b.r/bck;
	return a.t<b.t;
}
int n,q,qsz,opsz;
int ar[maxn],cnt[maxn*2],mex[maxn],ans[maxn];
int main() {
	read(n,q);
	for(int i=1;i<=n;i++) 
		read(ar[i]);
	int tims=0,l,r;
	for(int i=1;i<=q;i++){
		int ty,a,b;
		read(ty,a,b);
		if(ty==1) query[qsz]={a,b,tims,qsz},qsz++;
		else {
			opp[opsz]=a;
			lv[opsz]=ar[a];
			rv[opsz]=b;
			ar[a]=b;opsz++;
			tims++;
		}
	}
	while(tims>0) tims--,ar[opp[tims]]=lv[tims];
	{
		int b[maxn*2];
		rep(i,0,n) b[i]=ar[i+1];
		rep(i,0,opsz) b[i+n]=rv[i];
		sort(b,b+n+opsz);
		int t=unique(b,b+n+opsz)-b;
		rep(i,1,n+1) ar[i]=lower_bound(b,b+t,ar[i])-b+1;
		rep(i,0,opsz) lv[i]=lower_bound(b,b+t,lv[i])-b+1;
		rep(i,0,opsz) rv[i]=lower_bound(b,b+t,rv[i])-b+1;
	}
	l=r=0;
	sort(query,query+qsz,cmp);
	rep(i,0,qsz){
		while(l>query[i].l){
			int t=cnt[ar[--l]]++;
			mex[t]--,mex[t+1]++;
		}
		while(r<query[i].r){
			int t=cnt[ar[++r]]++;
			mex[t]--,mex[t+1]++;
		}
		while(l<query[i].l) {
			int t=cnt[ar[l++]]--;
			if(t>0) mex[t]--;mex[t-1]++;
		}
		while(r>query[i].r){
			int t=cnt[ar[r--]]--;
			if(t>0) mex[t]--,mex[t-1]++;
		}
		while(tims>query[i].t){
			tims--;int p=opp[tims];
			ar[p]=lv[tims];
			if(p>=l&&p<=r) {
				int t=cnt[rv[tims]]--;
				if(t>0) mex[t]--,mex[t-1]++;
				t=cnt[lv[tims]]++;
				mex[t]--,mex[t+1]++;
			}
		}
		while(tims<query[i].t){
			int p=opp[tims];
			ar[p]=rv[tims];
			if(p>=l&&p<=r) {
				int t=cnt[lv[tims]]--;
				if(t>0) mex[t]--,mex[t-1]++;
				t=cnt[rv[tims]]++;
				mex[t]--,mex[t+1]++;
			}
			tims++;
		}
		int res=1;
		while(mex[res]>0) res++;
		ans[query[i].in]=res;
	}
	rep(i,0,qsz) printf("%d\n",ans[i]);
}