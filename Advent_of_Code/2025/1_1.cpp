#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://adventofcode.com/2025/day/1
int main() {_
    freopen("1_input.txt", "r", stdin);
    int cur = 50, res = 0;
    string s;
    while (cin >> s) {
        if (s[0] == 'L') {
            cur -= stoi(s.substr(1));
        } else {
            cur += stoi(s.substr(1));
        }
        cur %= 100;
        res += (cur == 0);
    }
    cout << res << '\n';
    return 0;
}