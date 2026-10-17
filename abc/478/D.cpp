#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    struct events{
        int i;
        int x;
        int k;

        bool operator<(const events& other) const {
        return i < other.i;
        }
    };

    vector<events> A;
    for(int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x;
        l--; r--;

        A.push_back({l, x, 1});
        if(r + 1 < n) A.push_back({r + 1, x, -1});
    }

    sort(A.begin(), A.end());
    vector<vector<pair<int, int>>> B(n);
    for(auto[i, x, k] : A) {
        B[i].push_back({x, k});
    }
    vector<int> ans(n);
    map<int, int> cnt;
    ans[0] = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            ans[i] += ans[i - 1];
        }   
                
        for(auto [x, k] : B[i]) {
            if(k == 1) {
                if(cnt[x] == 0) {
                    ans[i]++;
                }

                cnt[x]++;
            }
            else {
                cnt[x]--;

                if(cnt[x] == 0) {
                    ans[i]--;
                }
            }
        }
    }

    for(int x : ans) cout << x << ' ';
    cout << '\n';
}