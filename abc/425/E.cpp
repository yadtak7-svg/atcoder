#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int M;
    cin >> T >> M;

    const int MAX = 5000;

    vector<vector<int>> comb(MAX + 1, vector<int>(MAX + 1, 0));

    comb[0][0] = 1 % M;

    for (int n = 1; n <= MAX; n++) {
        comb[n][0] = 1 % M;
        comb[n][n] = 1 % M;

        for (int k = 1; k < n; k++) {
            comb[n][k] =
                (comb[n - 1][k - 1] + comb[n - 1][k]) % M;
        }
    }

    while (T--) {
        int N;
        cin >> N;

        vector<int> C(N);

        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> C[i];
            sum += C[i];
        }

        long long ans = 1;
        int now = 0;

        for (int i = 0; i < N; i++) {
            now += C[i];

            ans *= comb[now][C[i]];
            ans %= M;
        }

        cout << ans << '\n';
    }

    return 0;
}