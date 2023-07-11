#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100100;

long long choco, money;
pair<long long, long long> type[Nmax];
void in(){
    cin >> choco >> money;
    for(int i = 1; i <= choco; i++){
        cin >> type[i].first >> type[i].second;
    }
    sort(type + 1, type + choco + 1);
}
void sol(){
    long long ans = 0;
    for(int i = 1; i <= choco; i++){
        long long x = 1ll * money / type[i].first;
        if(x == 0) break;
        //cout << i << ' ' << x << ' ';
        x = min(x, type[i].second);
        ans += 0ll + x;
        money -= 1ll * x * type[i].first;
        //cout << ans << '\n';
    } cout << ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    in();
    sol();
    return 0;
}