#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll dp[2][1000001];
int mod = 1e9 + 7;
void precal() {
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1, dp[1][1] = 1;
    for (int i = 2; i <= 1000001; i++) {
        dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % mod;
        dp[1][i] = (4 * dp[1][i - 1] + dp[0][i - 1]) % mod;
    }
}

// https://cses.fi/problemset/task/2413
int main() {_
    int t; cin >> t;
    precal();
    while (t--)
    {
        int n; cin >> n;
        cout << (dp[0][n] + dp[1][n]) % mod << '\n';
    }
    return 0;
}