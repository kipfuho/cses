#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1193
int main() {_
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> vis(n + 1, 0);
    function<void(int, int)> dfs;
    dfs = [&] (int u, int pre) {
        if (vis[u]) return;

        vis[u] = 1;
        for (int v : g[u]) {
            if (v == pre) continue;

            dfs(v, u);
        }
    };

    vector<int> coms;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            coms.push_back(i);
            dfs(i, -1);
        }
    }

    cout << coms.size() - 1 << '\n';
    for (int i = 1; i < coms.size(); i++) {
        cout << coms[0] << " " << coms[i] << '\n';
    }
    return 0;
}