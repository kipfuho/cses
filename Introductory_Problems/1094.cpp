#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1094
int main() {_
    int n; cin >> n;
    ll res = 0;
    int prev; cin >> prev;
    for (int i = 1; i < n; i++) {
        int cur; cin >> cur;
        if (prev > cur) {
            res += prev - cur;
        }
        prev = max(prev, cur);
    }
    cout << res;
    return 0;
}