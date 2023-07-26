#include "iostream"
#include "bits/stdc++.h"

using namespace std;

const int maxN = 100;

int count = 0;
int num[maxN];
int low[maxN];
int tail[maxN];

vector <int> g[maxN];

void dfs(int u, int parent){
    num[u] = low[u] = ++count;
    for (int v : g[u]){
        if (v == parent) continue;
        if (!num[v]){
            dfs(v, u);
            low[u] = min(low[v], low[u]);
        } else {
            low[u] = min(num[v], low[u]);
        }
    }
    tail[u] = count;
}


int main(){
    freopen("tree_dfs.inp", "r", stdin);
    freopen("tree_dfs.out", "w", stdout);
    scanf("%d%d", &n, &m);
    printf("%d\n", n);
    printf("%d\n", m);
    while (m--){
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    return 0;
}