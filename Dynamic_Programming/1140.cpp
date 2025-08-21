#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1140
int main() {_
    int n; cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        arr.push_back(v);
    }
    // sort by end time
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    vector<int> location;
    vector<ll> value;
    location.push_back(0);
    value.push_back(0);
    for (auto &v : arr) {
        auto it = upper_bound(location.begin(), location.end(), v[0] - 1);
        int index = (it == location.end() ? location.size() - 1 : it - location.begin());
        cout << index << " ";
        if (index <= 0) {
            if (location.size() > 0 && v[1] == location.back() && v[2] <= value.back()) {
                continue;
            }
            location.push_back(v[1]);
            value.push_back(v[2]);
        } else {
            index--;
            ll lastValue = (index == value.size() - 1) ? 0LL : value[value.size() - 1];
            location.push_back(v[1]);
            value.push_back(max(lastValue, value[index] + v[2]));
        }
    }
    cout << '\n';
    for (int i = 0; i < value.size(); i++) {
        cout << location[i] << " " << value[i] << '\n';
    }
    cout << value.back() << endl;
    return 0;
}