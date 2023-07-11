#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100005;

vector<int> graph[MAX];
priority_queue<int, vector<int>, greater<int> > pq;
int inDegree[MAX], ans[MAX];
vector<int> topoSort;
int n, m;
void init(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }
}
void process(){
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topoSort.push_back(u);
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }
}
void print_result(){
    // if (topoSort.size() == n) {
    //     for (int i : topoSort) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // } else {
    //     cout << "The graph has cycle(s)." << endl;
    // }

    int cnt = 0;
    for (auto x : topoSort){
        ans[x] = ++cnt;
    } 
    	
    for (int i = 1; i <= n; ++i) 
        cout << ans[i] << ' ';
}

int main() {
    freopen("MINPATH.INP", "r", stdin);
    freopen("MINPATH.OUT", "w", stdout);
    init();
    process();
    print_result();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
