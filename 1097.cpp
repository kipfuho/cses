#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int n;
vector<vector<ll>> arr;
inline ll solve(int i, int j) {
    if (arr[i][j] != 1e18) return arr[i][j];

    return arr[i][j] = max(arr[i][i] - solve(i + 1, j),
                           arr[j][j] - solve(i, j - 1));
}

// https://cses.fi/problemset/task/1097
int main() {_
    cin >> n;
    arr.resize(n, vector<ll>(n, 1e18));
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i][i];
        sum += arr[i][i];
    }

    cout << (sum + solve(0, n - 1)) / 2;
    return 0;
}