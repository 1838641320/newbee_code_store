#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
int mp[22][22]={},a[1009]={},n,i,j,k,num=4;
int main() {
	for (cin>>n,i=0,j;i<n*n;i++)
		cin>>j,a[j]++;
	for (;num;num/=2) 
		for (i=0;i<n;i++) for (j=0;j<n;j++) {
			set<pair<int,int>>s={{i,j},{i,n-j-1},{n-i-1,j},{n-i-1,n-j-1}};
			if (s.size()-num||mp[i][j])continue;
			for (k=1;k<=1000;k++)
				if (a[k]>=num) {
					mp[i][j]=mp[i][n-j-1]=mp[n-i-1][j]=mp[n-i-1][n-j-1]=k;
					a[k]-=num;
					break;
				}
				else if (k==1000) { puts("NO");exit(0); }
		}
	for (puts("YES"),i=0;i<n;i++,puts("")) for (j=0;j<n;j++)
		cout<<mp[i][j]<<' ';
}