#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1192
int main() {_
    int n, m; cin >> n >> m;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    function<void(int, int)> solve;
    solve = [&](int i, int j) {
        vis[i][j] = 1;
        for (auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= n || y < 0 || y >= m || ss[x][y] == '#' || vis[x][y]) continue;
            solve(x, y);
        }
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && ss[i][j] == '.') {
                solve(i, j);
                res++;
            }
        }
    }
    cout << res;
    return 0;
}