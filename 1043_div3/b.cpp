//

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep1(a) for (int i = 0; i < (a); i++)
#define rep2(i, a) for (int i = 0; i < (a); i++)
#define rep3(i, a, b) for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(args...) overload4(args, rep4, rep3, rep2, rep1)(args)
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))
#define ff first
#define ss second
using namespace std;

void sol(){
    ll n; cin >> n;
    vector<ll> ans;
    for (ll i = 10; ; ) {
        ll j = i + 1;
        if (n / j <= 0) break;

        if (n % j == 0) {
            ans.push_back(n / j);
        }
        i *= 10;
    }
    if (ans.empty()) {
        cout << "0\n";
        return;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}