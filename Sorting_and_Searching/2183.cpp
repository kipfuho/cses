#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// https://cses.fi/problemset/task/2183
int main() {_
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long res = 1;
    for(int i = 0; i < n; i++) {
        if (arr[i] > res) {
            break;
        }
        res += arr[i];  
    }
    cout << res;
    return 0;
}