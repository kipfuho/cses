#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1193
int main() {_
    int n, m; cin >> n >> m;
    vector<string> mt;
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        mt.push_back(s);
    }
    queue<vector<int>> qq;
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<pair<int,int>>> vis(n, vector<pair<int,int>>(m, {-1, -1}));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mt[i][j] == 'A') {
                vis[i][j] = {i, j};
                qq.push({i, j, 0});
                break;
            }
        }
        if (!qq.empty()) {
            break;
        }
    }

    int x, y, step = -1;
    while (!qq.empty()) {
        auto front = qq.front();
        qq.pop();

        if (mt[front[0]][front[1]] == 'B') {
            x = front[0], y = front[1], step = front[2];
            break;
        }

        for (auto& dir: dirs) {
            int x = front[0] + dir[0], y = front[1] + dir[1];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y].first != -1 || mt[x][y] == '#') {
                continue;
            }

            vis[x][y] = {front[0], front[1]};
            qq.push({x, y, front[2] + 1});
        }
    }

    if (step < 0) {
        cout << "NO";
        return 0;
    }

    // trace back
    string path = "";
    vector<string> ways = {"L", "R", "U", "D"};
    while (mt[x][y] != 'A') {
        int prevx = vis[x][y].first, prevy = vis[x][y].second;
        for (int i = 0; i < 4; i++) {
            int xx = dirs[i][0] + prevx, yy = dirs[i][1] + prevy;
            if (xx == x && yy == y) {
                path += ways[i];
            }
        }
        x = prevx, y = prevy;
    }

    reverse(path.begin(), path.end());
    cout << "YES\n" << step << "\n" << path;
    return 0;
}