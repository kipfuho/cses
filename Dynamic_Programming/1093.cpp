#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

// https://cses.fi/problemset/task/1069
int main() {_
    int n; cin >> n;
    int sum = (n * (n + 1) / 2);
    if (sum & 1) {
        cout << 0;
        return 0;
    }

    vector<ll> arr(125251, 0);
    arr[0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 125250; j >= i; j--) {
            if (arr[j - i]) {
                arr[j] = (arr[j] + arr[j - i]) % 1000000007;
            }
        }
    }
    cout << ((arr[sum / 2] & 1) ? arr[sum / 2] + 1000000007 : arr[sum / 2]) / 2;
    return 0;
}