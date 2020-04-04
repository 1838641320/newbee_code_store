#include<cstdio>
#include<cmath>
#include<vector>
#define all(i,n) for(int i=0;i<n;i++)
using namespace std;
const double ep = 1e-8;
typedef vector<vector<double> > matrix;
typedef vector<double> vec;
matrix A;
vec gauss_jordan(const matrix &A,const vec &b) {
	int n = A.size();
	matrix B = A;
	all(i,n) B[i].push_back(b[i]);
	all(i,n) {
		int pivot = i;
		for (int j = i; j < n; j++) if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
		swap(B[i],B[pivot]);
		if (fabs(B[i][i]) < ep) return vec();
		for (int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
		for (int j = 0; j < n; j++) {
			if (i != j) {
				for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	vec x(n);
	all(i,n) x[i] = B[i][n];
	return x;
}
int main() {
	int n;
	scanf("%d",&n);
	matrix A(n,vec(n));
	vec B;
	all(i,n) all(j,n) {
		double in;
		scanf("%lf",&in);
		A[i][j] = in;
	}
	all(i,n) {
		double in;
		scanf("%lf",&in);
		B.push_back(in);
	}
	B = gauss_jordan(A,B);
	for (auto i : B) printf("%.4lf ",i);
}
