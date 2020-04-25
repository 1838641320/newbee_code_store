#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
const double ep=1e-8;
typedef vector<double> vec;
typedef vector<vec> matrix;
namespace gauss{
	vec solve(const matrix &A,const vec &b) {
		int n=A.size();
		matrix a=A;
		for (int i=0;i<n;i++) a[i].push_back(b[i]);
		for (int i=0;i<n;i++) {
			int p=i;
			for (int j=i+1;j<n;j++) if (fabs(a[j][i])>fabs(a[p][i])) p=j;
			swap(a[i],a[p]);
			if (fabs(a[i][i])<ep) return vec();
			for (int j=i+1;j<=n;j++) a[i][j]/=a[i][i];
			for (int j=0;j<n;j++)
				if (i!=j) for (int k=i+1;k<=n;k++)
					a[j][k]-=a[j][i]*a[i][k];
		}
		vec x(n);
		for (int i=0;i<n;i++) x[i]=a[i][n];
		return x;
	}
}
int main() {
	int n;
	cin>>n;
	matrix a(n,vec(n));
	vec x(n),res;
	for (auto &i:a) for (auto &j:i) cin>>j;
	for (auto &i:x) cin>>i;
	res=gauss::solve(a,x);
	for (auto &i:res) printf("%.4lf\n",i);
}