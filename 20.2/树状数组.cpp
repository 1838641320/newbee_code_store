#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5+8;
ll bit[maxn] = {0},a[maxn] = {0},n;
ll sum(ll i) {
    int s = 0;
    while (i>0) {
        s += bit[i];
        i -= i&-i;
    }
    return s;
}
void add(ll i,ll x) {
    while (i<=n) {
        bit[i] += x;
        i += i&-i;
    }
}
int main() {
    ll r,i;
    scanf("%lld",&n);
    for (i = 0;i<n;i++) add(i+1,i*i);
    while (~scanf("%lld",&r))
        printf("%lld\n",sum(r));
}