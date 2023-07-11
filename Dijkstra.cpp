#include <iostream>
#include <cstring>
using namespace std;

const int maxN = 100;
const int maxC = 10000;

int c[maxN + 1][maxN + 1];
int d[maxN + 1];
int Trace[maxN + 1];
bool Free[maxN + 1];

int n, S, F;

void LoadGraph() {
    int m;
    int u, v;

    cin >> n >> m >> S >> F;
    for (u = 1; u <= n; u++) {
        for (v = 1; v <= n; v++) {
            if (u == v) c[u][v] = 0;
            else c[u][v] = maxC;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c[u][v];
    }
}

void Init() {
    int i;
    for (i = 1; i <= n; i++) {
        d[i] = c[S][i];
        Trace[i] = S;
    }
    memset(Free, true, sizeof(Free));
    Free[S] = false;
}

void Dijkstra() {
    int i, u, v;
    int min;

    do {
        u = 0; min = maxC;
        for (i = 1; i <= n; i++) {
            if (Free[i] && (d[i] < min)) {
                min = d[i];
                u = i;
            }
        }
        if (u == 0 || u == F) break;
        Free[u] = false;
        for (v = 1; v <= n; v++) {
            if (Free[v] && (d[v] > d[u] + c[u][v])) {
                d[v] = d[u] + c[u][v];
                Trace[v] = u;
            }
        }
    } while (true);
}

void PrintResult() {
    if (d[F] == maxC) {
        cout << "Path from " << S << " to " << F << " not found\n";
    } else {
        cout << "Distance from " << S << " to " << F << ": " << d[F] << "\n";
        while (F != S) {
            cout << F << "<-";
            F = Trace[F];
        }
        cout << S << "\n";
    }
}

int main() {
    freopen("MINPATH.INP", "r", stdin);
    freopen("MINPATH.OUT", "w", stdout);

    LoadGraph();
    Init();
    Dijkstra();
    PrintResult();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
