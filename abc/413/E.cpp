#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> p(1 << n);
        for (auto& e : p)
            cin >> e;
        auto solve = [&](auto&& solve, int l, int r) -> vector<int> {
            if (r - l == 1) return {p[l]};
            int mid = (l + r) / 2;
            vector<int> a = solve(solve, l, mid);
            vector<int> b = solve(solve, mid, r);
            if (a[0] > b[0]) swap(a, b);
            a.insert(a.end(), b.begin(), b.end());
            return a;
        };
        vector<int> ans = solve(solve, 0, 1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            cout << ans[i] << " \n"[i == (1 << n) - 1];
        }
    }
}
