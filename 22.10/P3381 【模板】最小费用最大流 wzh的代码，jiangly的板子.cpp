#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using i64 = long long;

template<class Ty>
struct MincostFlow {
    const Ty INF = numeric_limits<Ty>::max();
    int S, T, n; Ty MF = 0, MC = 0;
    struct Edge {
        int v, nxt; Ty f, w;
        Edge() : Edge(0, 0, 0, 0) {};
        Edge(int v, int nxt, Ty f, Ty w) : v(v), nxt(nxt), f(f), w(w) {};
    };
    struct mypair {
        Ty dist; int u;
        mypair() : mypair(0, 0) {}
        mypair(Ty d, int u) : dist(d), u(u) {}
        bool operator<(const mypair& rhs) const {
            return dist > rhs.dist;
        }
    };

    vector<Ty> dist, D;
    vector<int> h, pre;
    vector<Edge> E;

    MincostFlow(int _) : n(_) { init(_); };

    void init(int _) {
        h.resize(_ + 1, -1);
        dist.resize(_ + 1);
        pre.resize(_ + 1);
        D.resize(_ + 1);
    }

    void add(int u, int v, Ty flow, Ty weight) {
        E.emplace_back(v, h[u], flow, weight), h[u] = int(E.size()) - 1;
    }

    void addEdge(int u, int v, Ty f, Ty w) {
        add(u, v, f, w), add(v, u, 0, -w);
    }

    bool dijkstra() {
        dist.assign(n + 1, INF);
        priority_queue<mypair> q;
        dist[S] = 0;
        q.emplace(0, S);
        while (q.size()) {
            auto [dis, u] = q.top(); q.pop();
            if (dist[u] < dis) continue;
            for (int i = h[u]; ~i; i = E[i].nxt) {
                auto& [v, nxt, f, w] = E[i];
                if (f > 0 && dist[v] > dis + D[u] - D[v] + w) {
                    dist[v] = dis + D[u] - D[v] + w;
                    q.emplace(dist[v], v);
                    pre[v] = i;
                }
            }
        }
        return dist[T] != INF;
    }

    void work() {
        while (dijkstra()) {
            Ty flow = INF;
            for (int i = 0; i <= n; ++i) D[i] += dist[i];
            for (int i = T; i != S; i = E[pre[i] ^ 1].v) flow = min(flow, E[pre[i]].f);
            for (int i = T; i != S; i = E[pre[i] ^ 1].v) {
                E[pre[i]].f -= flow, E[pre[i] ^ 1].f += flow;
            }
            MC += D[T] * flow;
            MF += flow;
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    MincostFlow<i64> G(n);
    cin >> G.S >> G.T;

    for (int i = 1; i <= m; ++i) {
        int u, v, w, f;
        cin >> u >> v >> f >> w;
        G.addEdge(u, v, f, w);
    }

    G.work();

    cout << G.MF << " " << G.MC << "\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}
