#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1069
int main() {_
    string s; cin >> s;
    int res = 0, cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            res = max(res, cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cout << max(res, cnt);
    return 0;
}