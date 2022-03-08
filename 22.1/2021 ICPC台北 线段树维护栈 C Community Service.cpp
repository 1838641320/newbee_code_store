#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
#include<numeric>
// #include<array>
// #include<bitset>
typedef long long ll;
const int maxn=1e6+9;
vector<int> tr[maxn*4],lz[maxn*4];
int n;
bool vis[maxn];
string name[maxn];
int get(vector<int>&v){
	while(v.size()&&vis[v.back()])
		v.pop_back();
	return v.size()?v.back():0;
}
#define mid ((l+r)/2)
#define lch in*2
#define rch in*2+1
void update(int L,int R,int v,int in=1,int l=1,int r=n){
	tr[in].push_back(v);
	if(L<=l&&r<=R) return lz[in].push_back(v);
	if(L<=mid) update(L,R,v,lch,l,mid);
	if(R>mid) update(L,R,v,rch,mid+1,r);
}
int query(int L,int R,int in=1,int l=1,int r=n){
	if(L<=l&&r<=R) return get(tr[in]);
	int ret=get(lz[in]);
	if(L<=mid) ret=max(ret,query(L,R,lch,l,mid));
	if(R>mid) ret=max(ret,query(L,R,rch,mid+1,r));
	return ret;
}
void solve(){
	name[0]=">_<";
	int e,op,x,y;
	char buf[33];
	scanf("%d%d",&n,&e);
	for(int ii=1;ii<=e;ii++){
		scanf("%d",&op);
		if(op==1){
			scanf("%s%d%d",buf,&x,&y);
			name[ii]=buf;
			x++,y++;
			update(x,y,ii);
		}
		else{
			scanf("%d%d",&x,&y);
			x++,y++;
			int ans=query(x,y);
			vis[ans]=1;
			printf("%s\n",name[ans].c_str());
		}
	}
}
int main(){
	int t=1;
	// scanf("%d",&t);
	while(t--) solve();
}