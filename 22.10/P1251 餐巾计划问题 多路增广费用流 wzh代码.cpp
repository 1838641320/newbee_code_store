#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using i64 = long long;


template<class Ty>
struct MCmaxFlow {
    const Ty INF = numeric_limits<Ty>::max();
    int S, T, n; Ty MF = 0, MC = 0;
    struct Edge {
        int v, nxt; Ty f, w;
        Edge() : Edge(0, 0, 0, 0) {};
        Edge(int v, int nxt, Ty f, Ty w) : v(v), nxt(nxt), f(f), w(w) {};
    };

    vector<Ty> dist;
    vector<int> cur, h;
    vector<bool> vis;
    vector<Edge> E;

    MCmaxFlow(int _) : n(_) { init(_); };

    void init(int _) {
        dist.resize(_ + 1);
        vis.resize(_ + 1);
        cur.resize(_ + 1);
        h.resize(_ + 1);
        E.resize(2);
    }

    void add(int u, int v, Ty f, Ty w) {
        E.emplace_back(v, h[u], f, w), h[u] = int(E.size()) - 1;
    }

    void addEdge(int u, int v, Ty f, Ty w) {
        add(u, v, f, w), add(v, u, 0, -w);
    }

    bool SPFA() {
        dist.assign(n + 1, INF);
        queue<int> que;
        dist[S] = 0, cur[S] = h[S];
        que.push(S);
        while (que.size()) {
            int u = que.front(); que.pop();
            vis[u] = false;
            for (int i = h[u]; i; i = E[i].nxt) {
                auto& [v, nxt, f, w] = E[i];
                if (f && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (!vis[v]) {
                        vis[v] = true;
                        cur[v] = h[v];
                        que.push(v);
                    }
                }
            }
        }
        return dist[T] != INF;
    }

    Ty DFS(int u, Ty flow) {
        if (u == T) return flow;
        Ty last = flow;
        vis[u] = true;
        for (int i = cur[u]; i && last; i = E[i].nxt) {
            cur[u] = i;
            auto& [v, nxt, f, w] = E[i];
            if (f && !vis[v] && dist[v] == dist[u] + w) {
                Ty cost = DFS(v, min(f, last));
                if (!cost) dist[v] = INF;
                E[i].f -= cost, E[i ^ 1].f += cost;
                last -= cost;
            }
        }
        vis[u] = false;
        return flow - last;
    }

    void work() {
        while (SPFA()) {
            Ty flow = DFS(S, INF);
            MC += dist[T] * flow;
            MF += flow;
        }
    }
};


void solve() {
    int n;
    cin >> n;

    MCmaxFlow<i64> G(n + n + 2);
    G.S = n + n + 1, G.T = G.S + 1;
    vector<int> r(n + 1);
    for (i64 i = 1; i <= n; ++i) {
        cin >> r[i];
    }

    i64 a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    for (int i = 1; i <= n; ++i) {
        G.addEdge(i, G.T, r[i], 0);
        G.addEdge(i, i + n, G.INF, 0);
        G.addEdge(G.S, i + n, r[i], 0);
        G.addEdge(G.S, i, G.INF, a);
        if (i + 1 <= n) {
            G.addEdge(i + n, i + n + 1, G.INF, 0);
        }
        if (i + b <= n) {
            G.addEdge(i + n, i + b, G.INF, c);
        }
        if (i + d <= n) {
            G.addEdge(i + n, i + d, G.INF, e);
        }
    }

    G.work();

    cout << G.MC << "\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}
