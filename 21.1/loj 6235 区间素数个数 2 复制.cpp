#include <cmath>
#include <iostream>
using namespace std;
#define ll long long
const int N = 1000000 + 10;
ll f1[N], f2[N];
ll n;
double inv[N];
int main() {
    cin >> n;
    int lim = sqrt(n);
    for (int i = 1; i <= lim; ++i)
        f1[i] = i - 1, f2[i] = n / i - 1, inv[i] = 1.0 / i;
    for (int p = 2; p <= lim; ++p) {
        if (f1[p] == f1[p - 1])
            continue;
        ll x0 = f1[p - 1], w1 = lim / p, w2 = min((ll)lim, (n / p / p)), dd = n / p;
        for (int i = 1; i <= w1; ++i)
            f2[i] += x0 - f2[i * p];
        for (int i = lim / p + 1; i <= w2; ++i)
            f2[i] += x0 - f1[(int)(inv[i] * dd + 1e-7)];
        for (int i = lim; i >= 1ll * p * p; --i)
            f1[i] += x0 - f1[(int)(inv[p] * i + 1e-7)];
    }
    cout << f2[1] << endl;
    return 0;
}