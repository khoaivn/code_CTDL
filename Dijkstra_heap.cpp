#include <iostream>
#include <cstring>
using namespace std;

const int maxN = 100;
const int maxC = 10000;
const long long INF = 2000000000000000000LL;

int c[maxN + 1][maxN + 1];
int d[maxN + 1];
int Trace[maxN + 1];
bool Free[maxN + 1];
int Heap[MaxN + 1];

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


struct Edge{// kiểu dữ liệu tự tạo để lưu thông số của một cạnh.
    int v;
    long long w;
};
struct Node{// kiểu dữ liệu để lưu đỉnh u và độ dài của đường đi ngắn nhất từ s đến u.
    int u;
    long long Dist_u;
};
struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};
void dijkstra(int n, int s, vector<vector<Edge>> &E, vector<long long> &D, vector<int> &trace) {
    D.resize(n, INF);
    trace.resize(n, -1);
    vector<bool> P(n, 0);
    
    D[s] = 0;
    priority_queue<Node, vector<Node>, cmp> h; // hàng đợi ưu tiên, sắp xếp theo dist[u] nhỏ nhất trước
    h.push({s, D[s]});
    
    while(!h.empty()) {
        Node x = h.top();
        h.pop();
        
        int u = x.u;
        if(P[u] == true) // Đỉnh u đã được chọn trước đó, bỏ qua
            continue;
            
        P[u] = true; // Đánh dấu đỉnh u đã được chọn
        for(auto e : E[u]) {
            int v = e.v;
            long long w = e.w; 
            
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                h.push({v, D[v]});
                trace[v] = u;
            }
        }
    }
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
