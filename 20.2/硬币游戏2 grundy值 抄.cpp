#include<cstdio>
#include<set>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 10008;
int n,k,x[maxn] = {0},a[maxn] = {0};
int grundy[maxn] = {0};
int main() {
	grundy[0] = 0;
	int max_x = *max_element(x,x+n);
	for (int j = 1;j<=max_x;j++) {
		set<int> s;
		for (int i = 0;i<k;i++) 
			if (a[i]<=j) s.insert(grundy[j-a[i]]);
		int g = 0;
		while (s.count(g)) g++;
		grundy[j] = g;
	}
	int X = 0;
	for (int i = 0;i<n;i++) X ^= grundy[x[i]];
	puts(X?"yes":"no");
}