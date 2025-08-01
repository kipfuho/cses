#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1158
int main() {_
    int n, x; cin >> n >> x;
    vector<int> prices;
    vector<int> pages;
    for (int i = 0; i < n; i++) {
        int pr; cin >> pr;
        prices.push_back(pr);
    }
    for (int i = 0; i < n; i++) {
        int pa; cin >> pa;
        pages.push_back(pa);
    }

    vector<int> dp(100001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 100000; j >= prices[i]; j--) {
            if (dp[j - prices[i]]) {
                dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
            }
        }
    }
    int res = 1;
    for (int i = x; i > 0; i--) {
        res = max(res, dp[i]);
    } 
    cout << res - 1;
    return 0;
}