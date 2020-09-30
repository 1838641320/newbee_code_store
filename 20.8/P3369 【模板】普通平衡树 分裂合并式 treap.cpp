#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
namespace treap{
	mt19937 rd;
	int ch[maxn][2],pri[maxn],val[maxn],szt[maxn];
	int root,sz;
	void init(){
		mem(ch,0),mem(pri,0),mem(val,0),mem(szt,0);
		sz=0;rd.seed(time(0));root=0;}
	int newnode(int v){
		szt[++sz]=1,val[sz]=v,pri[sz]=rd();
		return sz;
	}
	void update(int x){szt[x]=szt[ch[x][0]]+szt[ch[x][1]]+1;}
	int merge(int x,int y){
		if(!x||!y) return x+y;
		if(pri[x]<pri[y]) 
			{ch[x][1]=merge(ch[x][1],y);return update(x),x;}
		else 
			{ch[y][0]=merge(x,ch[y][0]);return update(y),y;}
	}
	void split(int in,int k,int &x,int &y){
		if(!in) return void(x=y=0);
		if(val[in]<=k) 
			x=in,split(ch[in][1],k,ch[in][1],y);
		else 
			y=in,split(ch[in][0],k,x,ch[in][0]);
		update(in);
	}
	int get_rank(int in,int k){
		while(1){
			int t=szt[ch[in][0]];
			if(k<=t) in=ch[in][0];
			else if(k==t+1) return in;
			else k-=t+1,in=ch[in][1];
		}
	}
};
using namespace treap;
int main(){
	init();
	int n,ty,p,x,y,z;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&ty,&p);
		if(ty==1) {
			split(root,p,x,y);
			root=merge(merge(x,newnode(p)),y);
		}
		if(ty==2){
			split(root,p,x,z);
			split(x,p-1,x,y);
			y=merge(ch[y][0],ch[y][1]);
			root=merge(merge(x,y),z);
		}
		if(ty==3){
			split(root,p-1,x,y);
			printf("%d\n",szt[x]+1);
			root=merge(x,y);
		}
		if(ty==4) printf("%d\n",val[get_rank(root,p)]);
		if(ty==5){
			split(root,p-1,x,y);
			printf("%d\n",val[get_rank(x,szt[x])]);
			root=merge(x,y);
		}
		if(ty==6){
			split(root,p,x,y);
			printf("%d\n",val[get_rank(y,1)]);
			root=merge(x,y);
		}
	}
}
