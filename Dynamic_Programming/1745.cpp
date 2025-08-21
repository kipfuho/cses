#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1745
int main() {_
    int n; cin >> n;
    int ans = 0;
    vector<int> arr(n);
    vector<int> dp(100001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 100000; j >= arr[i]; j--) {
            if (!dp[j] && dp[j - arr[i]] > 0) {
                ans++;
                dp[j] = 1;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= 100000; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}