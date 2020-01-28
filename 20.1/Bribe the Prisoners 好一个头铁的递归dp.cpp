#include<cstdio>
#include<cstring>
#include<algorithm>
int N,p, Q, dp[108][108], a[108], test;
int solve(int s,int e) {
    if (dp[s][e]) return dp[s][e];
    if (s+1==e) return 0;
    int t= 0x3f3f3f3f;
    for (int i =s+1;i<e;i++) t = std::min(t,solve(s, i)+solve(i, e));
    return dp[s][e]=t+a[e]-a[s]-2;
}
int main(){
    scanf("%d", &N);
    for (test = 1; test <= N; test++) {
        scanf("%d%d", &p, &Q);
        for (int i = 1; i <= Q; i++) scanf("%d", &a[i]);
        memset(dp,0,4*108*108);
        a[0]=0;a[Q+1]=p+1;
        printf("Case #%d: %d\n",test,solve(0, Q + 1));
    }
}