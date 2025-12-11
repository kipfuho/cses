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
    queue<int> qq;
    vector<int> vis(n + 1, 0);
    vis[1] = 1, qq.push(1);
    while (!qq.empty()) {
        int u = qq.front();
        qq.pop();

        if (u == n) {
            break;
        }

        for (int v : g[u]) {
            if (vis[v]) continue;
            vis[v] = u;
            qq.push(v);
        }
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // trace back
    vector<int> path;
    int cur = n, step = 1;
    do {
        step++;
        path.push_back(cur);
        cur = vis[cur];
    } while (cur != 1);

    reverse(path.begin(), path.end());
    cout << step << "\n1 ";
    for (int i : path) cout << i << " ";
    return 0;
}