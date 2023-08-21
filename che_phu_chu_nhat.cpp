#include <bits/stdc++.h>
#include <iostream>
#define int long long
const int maxn = 50005;
using namespace std;
int n, res;
struct Event{
    int x, low, high, t; ///-1: close, 1: open
    bool operator<(Event &a){
        return (x < a.x) || ((x == a.x) && t < a.t);
    }
};
struct Node{
    int cnt, cover;
} ST[16 * maxn];

void update(int id, int L, int R, int u, int v, int val){
    if (v <= L || R <= u)
        return;
    if (u <= L && R <= v){
        ST[id].cnt += val;
        if (ST[id].cnt == 0)
            ST[id].cover = ST[2 * id].cover + ST[2 * id + 1].cover;
        else
            ST[id].cover = R - L;
        return;
    }
    int mid = (L + R) / 2;
    update(2 * id, L, mid, u, v, val);
    update(2 * id + 1, mid, R, u, v, val);
    if (ST[id].cnt == 0)
        ST[id].cover = ST[2 * id].cover + ST[2 * id + 1].cover;
}

vector<Event> E;

int main(){
    freopen("che_phu_chu_nhat.inp", "r", stdin);
    freopen("che_phu_chu_nhat.out", "w", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        struct Event open = {x1, y2, y1, 1};
        struct Event close = {x2, y2, y1, -1};
        E.push_back(open);  /// open
        E.push_back(close); /// close
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++){
        res = res + ST[1].cover * (E[i].x - E[i - 1].x);
        update(1, -maxn, maxn, E[i].low, E[i].high, E[i].t);
    }
    cout << res;
    return 0;
}