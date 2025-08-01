#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1145
int main() {_
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (len == 0 || a[i] > a[len - 1]) {
            a[len++] = a[i];
        } else {
            auto it = lower_bound(a.begin(), a.begin() + len, a[i]);
            a[it - a.begin()] = a[i];
        }
    }
    cout << len;
    return 0;
}