#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//----------------------------------------
#include<random>
#include<ctime>
using namespace std;
const int maxn=2e5+9;
int top=0,root,L,M,R;
int val[maxn],ch[maxn][2],pri[maxn];
int szt[maxn];
mt19937 rd;
void inti(){
	rd.seed(time(0));
	root=top=0;
};
void update(int in){szt[in]=szt[ch[in][0]]+szt[ch[in][1]]+1;}
int newn(int v){
	val[++top]=v,szt[top]=1;
	ch[top][0]=ch[top][1]=0;pri[top]=rd();
	return top;
}
void split(int in,int v,int &l,int &r){
	if(!in) return void(l=r=0);
	if(val[in]<=v)
		l=in,split(ch[in][1],v,ch[in][1],r);
	else 
		r=in,split(ch[in][0],v,l,ch[in][0]);
	update(in);
}
int merge(int l,int r){
	if(!l||!r) return l+r;
	if(pri[l]<pri[r])
		{ch[l][1]=merge(ch[l][1],r);update(l);return l;}
	else 
		{ch[r][0]=merge(l,ch[r][0]);update(r);return r;}
}
int getKth(int k){
	for(int in=root,t;;){
		t=szt[ch[in][0]];
		if(k<=t) in=ch[in][0];
		else if(k==t+1) return val[in];
		else in=ch[in][1],k-=t+1;
	}
}
int n,mi,k,leave=0,base=0;
char s[9]={};
int main(){
	read(n,mi);
	while(n--){
		scanf("%s%d",s,&k);
		if(s[0]=='I'){
			k+=base;
			if(k<mi) continue;
			split(root,k,L,R);
			root=merge(L,merge(newn(k),R));
		}
		else if(s[0]=='A') mi-=k,base-=k;
		else if(s[0]=='S'){
			mi+=k,base+=k;
			split(root,mi-1,L,R);
			leave+=szt[L];
			root=R;
		}
		else {
			if(k<=szt[root]) printf("%d\n",getKth(szt[root]-k+1)-base);
			else puts("-1");
		}
	}
	printf("%d\n",leave);
}