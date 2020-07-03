#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=209;
struct Li{ double x1,x2,h,d; }rect[maxn];
int n;
char num[maxn];
double x[maxn];
void add(int l,int r,char d){
	for(char *i=num+l,*ed=num+r;i!=ed;i++)
		(*i)+=d;
}
double cnt(int tot){
	double res=0;
	rep(i,0,tot)
		if(num[i]) res+=x[i+1]-x[i];
	return res;
}
int main(){
	int __=1;
	while(scanf("%d",&n),n){
		printf("Test case #%d\nTotal explored area: ",__++);
		rep(i,0,n) scanf("%lf%lf%lf%lf",&rect[i].x1,&rect[i].x2,&rect[i].h,&rect[i].d);
		vector<Li> line;
		rep(i,0,n)
			line.push_back({rect[i].x1,rect[i].h,rect[i].x2,1}),
			line.push_back({rect[i].x1,rect[i].h,rect[i].d,-1});
		double ans=0,past=-99;
		int tot=0;
		for(Li &i:line) x[tot++]=i.x1,x[tot++]=i.x2;
		sort(x,x+tot);
		tot=unique(x,x+tot)-x;
		sort(line.begin(),line.end(),[](Li &a,Li &b){return a.h<b.h;});
		memset(num,0,sizeof num);
		for(Li &i:line){
			ans+=cnt(tot)*(i.h-past);
			past=i.h;
			add(lower_bound(x,x+tot,i.x1)-x,lower_bound(x,x+tot,i.x2)-x,i.d);
		}
		printf("%.2lf\n\n",ans);
	}
}