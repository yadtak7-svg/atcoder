#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, M;
    cin >> N >> K >> M;

    
    vector<pair<long long, int>> A(N);

    for (int i = 0; i < N; i++) {
        int C;
        long long V;
        cin >> C >> V;
        C--;                   
        A[i] = {V, C};
    }

   
    sort(A.begin(), A.end());

    vector<bool> used_color(N, false);
    vector<bool> used(N, false);

    long long ans = 0;
    int color_cnt = 0;

    
    for (int i = N - 1; i >= 0 && color_cnt < M; i--) {
        int color = A[i].second;

        if (!used_color[color]) {
            used_color[color] = true;
            used[i] = true;
            ans += A[i].first;
            color_cnt++;
        }
    }

    int remain = K - M;
    for (int i = N - 1; i >= 0 && remain > 0; i--) {
        if (!used[i]) {
            ans += A[i].first;
            remain--;
        }
    }

    cout << ans << '\n';
    return 0;
}