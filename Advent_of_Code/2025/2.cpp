#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://adventofcode.com/2025/day/1
int main() {_
    // freopen("input.txt", "r", stdin);
    int cur = 50, res = 0;
    string s;
    while (cin >> s) {
        int x = stoi(s.substr(1));
        if (s[0] == 'L') {
            res += abs((cur - x - 100) / 100) - (cur == 0);
            cur -= x;
        } else {
            res += abs((x + cur) / 100);
            cur += x;
        }
        cur = (cur % 100 + 100) % 100;
    }
    cout << res << '\n';
    return 0;
}