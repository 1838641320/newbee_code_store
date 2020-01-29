#include<cstdio>
#include<queue>
#define typeone
using namespace std;
#ifdef typeone
typedef struct {
    int x, y, z, len;
}P;
typedef struct {
    bool operator()(P& a, P& b) { return a.len > b.len; }
}gre;
#endif
#ifdef typetwo
struct P {
    int x, y, z, len;
};
struct gre {
    bool operator()(P& a, P& b) { return a.len > b.len; }
};
#endif
priority_queue<P, vector<P>, gre> route;
int main() {
    route.push({ 1,1,1,3 }); route.push({ 1,0,1,2 }); route.push({ 2,1,1,4 });
    P a = { 2,3,4,8 }, b = { 7,4,2,0 };
    gre CMM;
    printf("a>b?%s\n", CMM(a, b) ? "yes" : "no");
    route.push(a); route.push(b);
    while (!route.empty()) {
        printf("%d ", route.top().len);
        route.pop();
    }
    puts("");
}