#include <bits/stdc++.h>
using namespace std;

const int MAX_ = 1e6 + 3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> A(n);
    long long all = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        all += A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> ans(MAX_);

    ans[0] = 0;

    int cnt = n;
    int cur = 0;

    for (int i = 1; i < MAX_; i++) {
        while (cur < n && A[cur] < i) {
            cur++;
            cnt--;
        }

        ans[i] = ans[i - 1] + cnt;
    }

    while (q--) {
        int x;
        cin >> x;
        
        long long need = ans[x - 1] + 1;

        if (need > all) {
            cout << -1 << '\n';
        } else {
            cout << need << '\n';
        }
    }
}