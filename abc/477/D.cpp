#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> sts(n, 0);
    vector<int> last(n, -1);
    vector<pair<int, char>> q2;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            --x;

            sts[x] ^= 1;
            last[x] = i;
        }
        else {
            char c;
            cin >> c;
            q2.push_back({i, c});
        }
    }

    vector<char> ans(n, 'a');

    for (int x = 0; x < n; x++) {

        if (sts[x] == 1) {

            auto it = lower_bound(
                q2.begin(),
                q2.end(),
                make_pair(last[x], (char)0)
            );

            if (it != q2.begin()) {
                --it;
                ans[x] = it->second;
            }
        }
        else {

            auto it = upper_bound(
                q2.begin(),
                q2.end(),
                make_pair(last[x], (char)127)
            );

            if (it != q2.end()) {
                --it;
                ans[x] = it->second;
            }
        }
    }

    for (char c : ans) {
        cout << c;
    }
    cout << '\n';
}