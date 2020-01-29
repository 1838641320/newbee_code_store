#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
constexpr int MAX_M=15;
int M, X;
double P;
double dp[2][(1 << MAX_M) + 1];
void solve() {
    int n = 1 << M;
    double* prev = dp[0], * next = dp[1];
    memset(prev, 0, sizeof(double) * (n + 1));
    prev[n] = 1.0;
    for (int r = 0; r < M; r++) {//押一次
        for (int i = 0; i <= n; i++) {//离散化后所有的钱数
            int jub = min(i, n - i);
            double t = 0.0;
            for (int j = 0; j <= jub; j++) {//离散化后枚举每次押多少
                t = max(t, P * prev[i + j] + (1 - P) * prev[i - j]);
            }
            next[i] = t;
        }
        swap(prev, next);
    }
    int i = (ll)X * n / 1000000;
    printf("%.6f\n", prev[i]);
}
int main() {
    M = 3;
    P = 0.75;
    X = 600000;
    solve();
}