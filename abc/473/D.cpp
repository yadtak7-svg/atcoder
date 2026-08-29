#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
ll K;
vector<ll> A;

void dfs(int i, ll rem) {
    if (i == N) {
        if (rem % N == 0) {
            A[N] = rem / N;

            for (int j = 1; j <= N; j++) {
                if (j > 1) cout << ' ';
                cout << A[j];
            }
            cout << '\n';
        }
        return;
    }

    for (ll x = 0; i * x <= rem; x++) {
        A[i] = x;
        dfs(i + 1, rem - i * x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    A.resize(N + 1);

    dfs(1, K);

    return 0;
}