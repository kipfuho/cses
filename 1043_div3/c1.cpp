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

vector<ll> aa;

void a() {
    ll i = 1;
    while (i < 1e9) {
        aa.push_back(i);
        i *= 3;
    }
}

void sol(){
    int n; cin >> n;
    ll res = 0;
    for (int i = aa.size() - 1; i >= 0; i--) {
        if (n >= aa[i]) {
            ll x = pow(3LL, i + 1) + pow(3LL, i - 1) * i;
            ll y = aa[i];
            if (n >= aa[i] * 2) {
                x *= 2, y *= 2;
            }
            res += x;
            n -= y;
        }
    }
    cout << res << "\n";
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    a();
    while(t--){
        sol();
    }
    return 0;
}