#include <bits/stdc++.h>
#include <iostream>

#define int long long
using namespace std;
struct P{
    int x, t, y1, y2;
};
vector<P> point;

bool cmp(P a, P b){
    return ((a.x < b.x) || (a.x == b.x && a.t < b.t));
}
int n, res, BIT[100005];

void upd(int pos, int val){
    while (pos < n){
        BIT[pos] += val;
        pos = pos + (pos & -pos); 
    }
}
int get(int pos){
    int s = 0;
    while (pos > 0){
        s = s + BIT[pos];
        pos = pos - (pos & -pos);
    }
    return s;
}
int32_t main(){ 
    ios_base::sync_with_stdio(0);
    freopen("intersection_point.inp", "r", stdin);
    freopen("intersection_point.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2; /// read data input
        if (y1 == y2){
            struct P be = {x1, 1, y1, 0};
            struct P end = {x2, 3, y1, 0};
            point.push_back(be); /// begin
            point.push_back(end); /// end
        }

        if (x1 == x2){
            struct P ver = {x1, 2, y1, y2};
            point.push_back(ver); /// Vertical
        }
    }
    sort(point.begin(), point.end(), cmp);
    for (P a : point){
        if (a.t == 1)
            upd(a.y1, 1); /// Begin of segment
        if (a.t == 3)
            upd(a.y1, -1); /// End of segment
        if (a.t == 2)      /// Count the intersection
            res = res + get(a.y2) - get(a.y1 - 1);
    }
    cout << res;
}