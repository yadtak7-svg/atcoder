#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num(const string& x) {
    int sz = x.size();
    ll k = 1, res = 0;
    for (int i = sz - 1; i >= 0; i--, k *= 10) {
        res += (x[i] - '0') * k;
    }
    return res;
}

bool check(ll x, ll a) {
    string s;
    if (x == 0) s = "0";
    while (x > 0) {
        ll k = x % a;
        s.push_back(char(k + '0'));
        x /= a;
    }

    int sz = s.size();
    for (int i = 0; i < sz / 2; i++) {
        if (s[i] != s[sz - i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, n;
    cin >> a >> n;

    ll ans = 0;

    queue<string> que;

    ll pow10[9];
    pow10[0] = 1;
    for (int i = 1; i <= 8; i++) pow10[i] = pow10[i - 1] * 10;

    for (int H = 1; H <= 7; H++) {
        ll lo = (H == 1) ? 0 : pow10[H - 1];
        ll hi = pow10[H] - 1;

        for (ll h = lo; h <= hi; h++) {
            string half = to_string(h);
            if ((int)half.size() != H && !(H == 1)) continue;

            {
                string full = half;
                for (int i = (int)half.size() - 2; i >= 0; i--) full.push_back(half[i]);
                que.push(full);
            }
            {
                string full = half;
                for (int i = (int)half.size() - 1; i >= 0; i--) full.push_back(half[i]);
                que.push(full);
            }
        }
    }

    while (!que.empty()) {
        string x = que.front();
        que.pop();

        ll val = num(x);
        if (val < 1 || val > n) continue; 
        if (check(val, a)) {
            ans += val;
        }
    }

    cout << ans << endl;
    return 0;
}