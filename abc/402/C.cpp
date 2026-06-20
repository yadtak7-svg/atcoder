#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);
    vector<int> A(m, 0);
    vector<bool> looked(m, false);

    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        A[i] = k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            G[x - 1].push_back(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        b--;

        for(int z : G[b]) {
            A[z]--;
            if(A[z] == 0 && looked[z] == false) {
                looked[z] = true;
                ans++;
            }
        }

        cout << ans << endl;
    }
}