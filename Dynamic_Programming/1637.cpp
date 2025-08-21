#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

vector<int> dp;
inline void solve(int n, int step) {
    if (n < 0 || dp[n] <= step) return;
    dp[n] = step;

    int nn = n;
    int nnn = 0;
    while (nn > 0) {
        nnn = max(nnn, nn % 10);
        nn /= 10;
    }
    solve(n - nnn, step + 1);
    return;
}

// https://cses.fi/problemset/task/1637
int main() {_
    int n; cin >> n;
    dp.resize(n + 1, 1e9);
    solve(n, 0);
    cout << dp[0];
    return 0;
}