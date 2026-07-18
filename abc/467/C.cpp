#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    vector<int> D(N - 1);
    for (int i = 0; i < N - 1; i++) {
        D[i] = ((A[i] + A[i + 1]) & 1) ^ B[i];
    }

    int ans = INT_MAX;

    for (int first = 0; first <= 1; first++) {
        vector<int> x(N);
        x[0] = first;

        for (int i = 0; i < N - 1; i++) {
            x[i + 1] = x[i] ^ D[i];
        }

        int cost = 0;
        for (int v : x) cost += v;
        ans = min(ans, cost);
    }

    cout << ans << '\n';
    return 0;
}