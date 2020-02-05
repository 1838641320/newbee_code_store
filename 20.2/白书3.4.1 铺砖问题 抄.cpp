﻿#include<iostream>
#define maxn 15
using namespace std;
bool M[maxn+2][maxn+2];
int dp[2][1<<maxn]; 
int main(){
	int n,m,mod;
	while(cin>>n>>m &&n&&m){
		cin>>mod;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){ //从0开始后面会好操作一点 
				char input; cin>>input;
				if(input=='.') M[i][j]=0; //0:白 1：黑，将0全变为1 
				else M[i][j]=1;
			}
		}
		int *now=dp[0],*nex=dp[1];
		now[0]=1;
		for(int i=n-1;i>=0;i--){ //从n-1 开始会方便二进制表示状态 
			for(int j=m-1;j>=0;j--){
				for(int used=0;used< (1<<m) ;used++){ //遍历状态,这里反过来表示  
					if(used>>j & 1 || M[i][j]) nex[used]=now[used & ~(1<<j)];//假如这个位置被用了或者是1 不用填 
					else{
						int res=0;
						if(j+1<m && !(used>>(j+1)&1) && !M[i][j+1]) res+=now[used|1<<(j+1)];//横着放 
						if(i+1<n && !M[i+1][j] ) res+=now[used|1<<j];//竖着放 
						nex[used]=res%mod;
					} 
				}
				swap(now,nex);
			}
		}
		cout<<now[0]<<endl;
	}
	return 0; 
}