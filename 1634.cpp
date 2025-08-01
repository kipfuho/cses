#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1634
int main() {_
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    
    if (dp[x] == 1e9) dp[x] = -1;
    cout << dp[x];
    return 0;
}