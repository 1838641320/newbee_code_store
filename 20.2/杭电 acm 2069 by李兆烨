#ifdef lzy
#include<algorithm>
#include<iostream>
#include<numeric>
using namespace std;
const int a[]{0,50,25,10,5};
int n,r[10],cnt;
void fun(int rest,int k){
	for(int i=0; i<=rest/a[k]; i++){
		r[k]=i;
		if(k==4){
			if(accumulate(r+1,r+5,n-(r[1]*a[1]+r[2]*a[2]+r[3]*a[3]+r[4]*a[4]))<=100) cnt++;
		}
		else fun(rest-i*a[k],k+1);
	}
}
int main(){
	for(; cin>>n; cout<<cnt<<endl,cnt=0) fun(n,1);
}
#endif
#ifndef lzy
#include<cstdio>
const int a[]{0,50,25,10,5};
int n,r[10],cnt;
void fun(int rest,int k){
	for(int i=0; i<=rest/a[k]; i++){
		r[k]=i;
		if(k==4){
			if((r[1]+r[2]+r[3]+r[4]+n-(r[1]*a[1]+r[2]*a[2]+r[3]*a[3]+r[4]*a[4]))<=100) cnt++;
		}
		else fun(rest-i*a[k],k+1);
	}
}
int main(){
	for(;~scanf("%d",&n); printf("%d\n",cnt),cnt=0) fun(n,1);
}
#endif
