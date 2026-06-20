#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            A[i][j] = S[i][j] - '0';
        }
    }

    long long ans = 0;

    for (int top = 0; top < H; top++) {

        vector<int> col(W, 0);

        for (int bottom = top; bottom < H; bottom++) {

            for (int j = 0; j < W; j++) {
                col[j] += A[bottom][j];
            }

            unordered_map<long long, long long> mp;
            mp[0] = 1;

            long long sum = 0;

            for (int j = 0; j < W; j++) {
                sum += col[j];

                if (mp.count(sum - K))
                    ans += mp[sum - K];

                mp[sum]++;
            }
        }
    }

    cout << ans << '\n';
}