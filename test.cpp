#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/x
int main() {_
    map<ll, ll, greater<int>> mp;
    mp[0] = 1;
    mp[10] = 2;
    mp[5] = 3;
    for (auto &it : mp) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}