#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1746
int main() {_
    int n, m; cin >> n >> m;
    int mod = 1e9 + 7;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));
    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j - 1] +
                            dp[i - 1][j]     +
                            dp[i - 1][j + 1]) % mod;
            }
        } else {
            dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] +
                             dp[i - 1][arr[i]]     +
                             dp[i - 1][arr[i] + 1]) % mod;
        }
    }
    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % mod;
    return 0;
}