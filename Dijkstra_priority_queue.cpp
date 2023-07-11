#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

vector<pii> adj[MAXN];
int d[MAXN];
bool Free[MAXN];
int n, m;

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    d[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (Free[u]) continue;
        Free[u] = true;

        for (auto v : adj[u]) {
            if (d[u] + v.second < d[v.first]) {
                d[v.first] = d[u] + v.second;
                pq.push(make_pair(d[v.first], v.first));
            }
        }
    }
}

int main() {
    freopen("MINPATH.INP", "r", stdin);
    freopen("MINPATH.OUT", "w", stdout);
    cin >> n >> m;
    int s;
    cin >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

   

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        Free[i] = false;
    }

    dijkstra(s);

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            cout << "INF ";
        else
            cout << d[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}