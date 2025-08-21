#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1083
int main() {_
    ll n; cin >> n;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        ll x; cin >> x;
        sum += x;
    }
    cout << (n * (n + 1)) / 2 - sum;
    return 0;
}