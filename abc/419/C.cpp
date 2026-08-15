#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> X(n), Y(n);
    long long maxX = 0, maxY = 0, minX = 1e9, minY = 1e9;
    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        maxX = max(maxX, X[i]);
        maxY = max(maxY, Y[i]);
        minX = min(minX, X[i]);
        minY = min(minY, Y[i]);
    }

    long long dx = maxX - minX;
    long long dy = maxY - minY;

    long long ans = max((dx + 1) / 2, (dy + 1) / 2);

    cout << ans << '\n';
}