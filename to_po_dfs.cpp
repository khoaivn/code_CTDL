#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 1e5+5;
vector<int> graph[MAX];
int n, m;
bool visited[MAX];
stack<int> topo_order;
int ans[MAX];

void read_input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    topo_order.push(u);
}

void topo_sort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (!topo_order.empty()) {
        cout << topo_order.top() << " ";
        topo_order.pop();
    }

    // int cnt = 0;
    // while (!topo_order.empty()) {
    //     ans[topo_order.top()] = ++cnt;
    //     topo_order.pop();
    // }
    // for (int i = 0; i < n; ++i) 
    //     cout << ans[i] << ' ';
}

int main() {
    freopen("MINPATH.INP", "r", stdin);
    freopen("MINPATH.OUT", "w", stdout);

    read_input();
    topo_sort();

    fclose(stdin);
    fclose(stdout);
    return 0;
}