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
#include<ctime>
using std::swap;
const int maxn=1e5+9;
int ar[maxn],n;
void partition(int a[],int len){
	if(len<2) return;
	swap(a[0],a[rand()%len]);
	int i=0,j=len-1;
	int x=a[0];
	while(i<j){
		while(i<j&&a[j]>=x) j--;
		if(i<j) a[i++]=a[j];
		while(i<j&&a[i]<x) i++;
		if(i<j) a[j--]=a[i];
	}
	a[i]=x;
	partition(a,i);
	partition(a+i+1,len-i-1);
}
void mysort(int a[],int len){
	srand(time(0));
	partition(a,len);
}
int main(){
	read(n);
	rep(i,0,n) read(ar[i]);
	mysort(ar,n);
	rep(i,0,n) printf(" %d"+!i,ar[i]);
}