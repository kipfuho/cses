#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1070
int main() {_
    int n; cin >> n;
    if (n < 5) {
        if (n == 1) {
            cout << "1";
        } else if (n == 4) {
            cout << "2 4 1 3";
        }else {
            cout << "NO SOLUTION";
        }
    }
    else {
        for (int i = 1; i <= n; i += 2) cout << i << " ";
        for (int i = 2; i <= n; i += 2) cout << i << " ";
    }
    return 0;
}