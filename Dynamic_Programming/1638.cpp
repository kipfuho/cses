#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1638
int main() {_
    int n; cin >> n;
    vector<string> rows(n);
    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (rows[0][i] == '*') break;
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        dp[0] = rows[i][0] == '*' ? 0 : dp[0];
        for (int j = 1; j < n; j++) {
            dp[j] = rows[i][j] == '*' ? 0 : ((dp[j - 1] + dp[j]) % 1000000007);
        }
    }
    cout << dp[n - 1];
    return 0;
}