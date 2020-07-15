#include"s.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int a[maxn]={},n,k,sz,x,y,rim[maxn]={},P[maxn]={};
bool vis[maxn]={};
void exgcd(int a,int b,int &x,int &y){
	if(!b) { x=1,y=0;return; }
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;sz=0;
		rim[sz++]=i;
		for(int p=a[i];p!=i;p=a[p])
			vis[p]=1,rim[sz++]=p;
		exgcd(k%sz,sz,x,y);
		x=(x+sz)%sz;
		for(int i=0;i<sz;i++)
			P[rim[i]]=rim[(i+x)%sz];
	}
	for(int i=1;i<=n;i++) printf("%d ",P[i]);
}