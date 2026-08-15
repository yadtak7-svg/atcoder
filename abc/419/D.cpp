#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    vector<int> diff(N + 2, 0);

    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;

        diff[L] ^= 1;
        diff[R + 1] ^= 1;
    }

    int state = 0;

    for (int i = 1; i <= N; i++) {
        state ^= diff[i];

        if (state == 0) {
            cout << S[i - 1];
        } else {
            cout << T[i - 1];
        }
    }

    cout << '\n';
}