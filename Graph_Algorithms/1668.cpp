#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1193
int main() {_
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ok = true;
    queue<int> qq;
    vector<int> vis(n + 1, 0);
    function<void(int, int)> dfs;
    dfs = [&] (int u, int pre) {
        if (vis[u]) {
            if (vis[u] == vis[pre]) ok = false;
            return;
        }

        vis[u] = (vis[pre] == 1 ? 2 : 1);
        for (int v : g[u]) {
            if (v == pre) continue;

            dfs(v, u);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 1; i <= n; i++) cout << vis[i] << " ";
    return 0;
}