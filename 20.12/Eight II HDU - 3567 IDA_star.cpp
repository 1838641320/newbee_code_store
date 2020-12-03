#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
using namespace std;
char a[12]={},b[12]={};
char ans[80]={},dir[]="dlru";
int dd[4][2]={1,0,0,-1,0,1,-1,0};
int ___case,LIMITE,nexLIMITE,goalpos[300]={};
int getdis(){
	int ret=0;
	rep(i,0,9){
		if(a[i]=='X') continue;
		int j=goalpos[a[i]];
		ret+=abs(i/3-j/3)+abs(i%3-j%3);
	}
	return ret;
}
void output(int deep){
	printf("Case %d: %d\n",___case,deep);
	puts(ans);
}
int idastar(int pos,int dep,int pre){
	int dis=getdis();
	if(dis+dep>LIMITE) return nexLIMITE=min(nexLIMITE,dis+dep),0;
	if(dis==0) return output(dep),1;
	int x=pos/3,y=pos%3;
	rep(i,0,4){
		if(pre+i==3) continue;
		int xx=x+dd[i][0],yy=y+dd[i][1];
		if(xx<0||yy<0||xx>2||yy>2) continue;
		int tpos=xx*3+yy;
		swap(a[pos],a[tpos]);
		ans[dep]=dir[i];
		if(idastar(tpos,dep+1,i)) return 1;
		swap(a[pos],a[tpos]);
	}
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	for(___case=1;___case<=t;___case++){
		mem(ans,0);
		scanf("%s%s",a,b);
		rep(i,0,9) if(b[i]!='X') goalpos[b[i]]=i;
		int pos=0;
		rep(i,0,9) if(a[i]=='X') {pos=i;break;}
		LIMITE=0;
		while(!idastar(pos,0,-4)) LIMITE=nexLIMITE,nexLIMITE=999;
	}
}