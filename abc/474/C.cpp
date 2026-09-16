#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> A(n + q);
    for(int i = 0; i < n + q; i++) cin >> A[i];

    vector<int> look(n + 1, false);
    vector<int> ans;
    int cnt = 0, i = n + q - 1;
    while(i >= 0 && cnt != n) {
        if(!look[A[i]]) {
            look[A[i]] = true;
            cnt++;
            ans.push_back(A[i]);
        }
        i--;
    }

    for(int i = n - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
