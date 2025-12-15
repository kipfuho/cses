#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

long long sol(string a, string b) {
    try {
        int l1 = a.size(), l2 = b.size();
        long long start = stol(a.substr(0, max(l1/2, 1))), end = stol(b.substr(0, l2/2 + (l2&1))), aa = stol(a), bb = stol(b);
        long long res = 0;
        for (long long i = start; i <= end; i++) {
            long long num = stol(to_string(i) + to_string(i));
            if (num > bb) break;
            if (num >= aa) res += num;
        }
        return res;
    } catch (...) {
        cout << "error with " << a << " " << b << "\n";
        return 0;
    }
}

// https://adventofcode.com/2025/day/1
int main() {_
    // freopen("2_input.txt", "r", stdin);
    string s; cin >> s;
    vector<string> parts;
    stringstream ss(s);
    string token;

    while (std::getline(ss, token, ',')) {
        parts.push_back(token);
    }
    long long res = 0;
    // cout << parts.size() << "\n";
    for (auto &part : parts) {
        string a = part.substr(0, part.find('-'));
        string b = part.substr(part.find('-') + 1);
        long long x = sol(a, b);
        res += x;
        // cout << x << "\n";
    }
    cout << res << '\n';
    return 0;
}