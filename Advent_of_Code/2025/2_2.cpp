#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

long long sol(string a, string b) {
    try {
        int l1 = a.size(), l2 = b.size();
        long long aa = stol(a), bb = stol(b);
        map<long long, bool> seen;
        long long res = 0;
        for (int len = 2; len <= l2; len++) {
            int la = l1/len, lb = l2/len + l2 - l1;
            long long start = la > 0 ? stol(a.substr(0, la)) : 1, end = lb > 0 ? stol(b.substr(0, lb)) : 1;
            // cout << "len=" << len << " start=" << start << " end=" << end << "\n";
            for (long long i = start; i <= end; i++) {
                string numStr = "";
                for (int kk = 0; kk < len; kk++) numStr += to_string(i);
                long long num = stol(numStr);
                if (num > bb) break;
                if (num >= aa && !seen[num]) {
                    res += num;
                    seen[num] = true;
                }
            }
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