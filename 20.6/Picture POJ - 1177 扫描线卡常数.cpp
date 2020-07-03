#include<cstdio>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
using namespace std;
const int maxn=2e4+50;
int n,ans=0;
struct node{
	int x1,x2,h,d;
	bool operator < (const node &a) const { return h<a.h; }
	node(int a,int b,int c,int d):x1(a),x2(b),h(c),d(d){};
	node():x1(),x2(),h(),d(){};
};
vector<node> g;
int line[maxn];
pair<int,int> count_(){
	int num=0,len=0;
	for(int j=1;j<maxn;j++) {
		if((line[j-1]==0)^(line[j]==0)) num++;
		if(line[j]) len++;
	}
	return make_pair(num,len);
}
int main(){
	scanf("%d",&n);
	if(n==0) return puts("0"),0;
	for(int i=0,a,b,c,d;i<n;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a+=1e4+20,c+=1e4+20;
		g.push_back(node(a,c,b,1));
		g.push_back(node(a,c,d,-1));
	}
	sort(g.begin(),g.end());
	for(int i=0,ned=2*n-1,last=0;i<ned;i++){
		int l=g[i].x1,r=g[i].x2,d=g[i].d;
		for(int *j=line+l,*ed=line+r;j!=ed;j++) *j+=d;
		pair<int,int> pii=count_();
		int len=pii.second,num=pii.first;
		ans+=abs(len-last);
		last=len;
		ans+=num*(g[i+1].h-g[i].h);
	}
	for(int j=1;j<maxn;j++) if(line[j]) ans++;
	printf("%d\n",ans);
}