#include"stdafx.h"
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int maxn = 609;
struct disjoint_set { int p,w; }ds[maxn];
typedef struct { int a,f,i; } P;
int n,p,q;
int findp(int x) {
	if (ds[x].p==x) return x;
	int tp = ds[x].p;
	ds[x].p = findp(tp);
	ds[x].w ^= ds[tp].w;
	return ds[x].p;
}
void unite(int a,int b,int u) {
	int pa = findp(a),pb = findp(b);
	if (pa!=pb) {
		ds[pa].p = pb;
		ds[pa].w ^= ds[b].w^u^ds[a].w;
	}
}
int main() {
	for (;scanf("%d%d%d",&n,&p,&q),n|p|q;) {
		int num = p+q+1;
		for (int i = 0;i<maxn;i++) ds[i].p = i,ds[i].w = 0;
		while (n--) {
			char s[6] = {};
			int a,b;
			scanf("%d %d %s",&a,&b,s);
			unite(a,b,s[0]=='n');
		}
		for (int i = 0;i<num;i++) findp(i);
		vector<int> group[maxn][2] = {};
		for (int i = 1;i<num;i++)
			group[findp(i)][ds[i].w].push_back(i);
		P dp[maxn][maxn] = {};
		memset(dp,0,sizeof(dp));
		int si = 0;
		dp[0][0].a = 1;
		for (int i = 1;i<num;i++) {
			int s1 = group[i][0].size(),s2 = group[i][1].size();
			if ((s1|s2)==0) continue;
			si++;
			for (int j = 0;j<num;j++) {
				int f = dp[si-1][j].a;
				if (f==0) continue;
				if (j+s1<num) {
					dp[si][j+s1].a = f+dp[si][j+s1].a;
					dp[si][j+s1].f = j;
					dp[si][j+s1].i = i;
				}
				if (j+s2<num) {
					dp[si][j+s2].a = f+dp[si][j+s2].a;
					dp[si][j+s2].f = j;
					dp[si][j+s2].i = i;
				}
			}
		}
		if (dp[si][p].a!=1) { puts("no");continue; }
		char ans[maxn] = {};
		for (int i = p;i;i = dp[si--][i].f) {
			int out = dp[si][i].i,t = group[out][1].size()==i-dp[si][i].f;
			for (vector<int>::iterator j = group[out][t].begin();j!=group[out][t].end();j++)
				ans[*j]=1;
		}
		for (int i = 0;i<num;i++)  ans[i]&&printf("%d\n",i);
		puts("end");
	}
}